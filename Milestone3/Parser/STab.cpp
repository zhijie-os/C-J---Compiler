#include "STab.h"
#include "AST.h"

#define CreateScope(x) SYMBOL_TABLE.insert({x, {}});
#define Child(p, i) p->children[i]
#define ChildType(p, i) p->children[i]->type
#define ChildLiteral(p, i) p->children[i]->attribute->literal
#define ChildLine(p, i) p->children[i]->attribute->line
#define NodeToData(x) NodeTypeToDataType.find(x)->second

std::string MAIN_ID = "";
std::unordered_map<std::string, FuncRecord> GLOBAL_FUNC{
    {"getchar", {{DataType::INT}, {}}},
    {"halt", {{DataType::VOID}, {}}},
    {"printb", {{DataType::VOID}, {DataType::BOOL}}},
    {"printc", {{DataType::VOID}, {DataType::INT}}},
    {"printi", {{DataType::VOID}, {DataType::INT}}},
    {"prints", {{DataType::VOID}, {DataType::STRING}}},
};

std::unordered_map<std::string, IdentifierRecord> GLOBAL_VAR;
std::unordered_map<std::string, std::unordered_map<std::string, IdentifierRecord>> SYMBOL_TABLE;

const std::unordered_map<DataType, std::string> DataTypeToString{
    {DataType::BOOL, "BOOLEAN"},
    {DataType::INT, "NUMBER"},
    {DataType::STRING, "STRING"},
    {DataType::VOID, "VOID"},
};

const std::unordered_map<NodeType, DataType> NodeTypeToDataType{
    {NodeType::BOOLEAN, DataType::BOOL},
    {NodeType::INT, DataType::INT},
    {NodeType::VOID, DataType::VOID},
    {NodeType::STRING, DataType::STRING},
};

std::vector<DataType> ParseFormals(AST *root)
{
    std::vector<DataType> toReturn;

    // for every formal in formals
    for (auto c : root->children)
    {
        // this formal's first child is the type, push it in to the toReturn
        toReturn.push_back(NodeTypeToDataType.find(ChildType(c, 0))->second);
    }

    return toReturn;
}

void ActualsMatchFormals(AST *fun_c, AST *actual)
{
    std::vector<DataType> formals = fun_c->f_record->paramType;
    std::vector<DataType> actuals;

    // for each actual in actuals
    for (auto c : actual->children)
    {
        // this actual's first child
        actuals.push_back(TypeLookup(c));
    }

    if (formals.size() != actuals.size())
    {
        SemanticError(ChildLine(actual, 0), ChildLiteral(actual, 0) + ": ACTUALS does not match FORMALS by size");
    }

    for (int i = 0; i < formals.size(); i++)
    {
        if (formals[i] != actuals[i])
        {
            SemanticError(ChildLine(actual, 0), ChildLiteral(actual, 0) + ": ACTUALS does not match FORMALS by type");
        }
    }
}

bool ContainReturn(AST *root)
{
    if (root->type == NodeType::RETURN)
    {
        return true;
    }

    for (auto c : root->children)
    {
        if (ContainReturn(c))
        {
            return true;
        }
    }

    return false;
}

void MainDefined()
{
    if (MAIN_ID.empty())
    {
        std::cerr << "Main was not defined!" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void BreakInWhile(AST *root)
{
    bool inWhile = false;
    AST *copy = root;

    while (root->parent)
    {
        root = root->parent;
        if (root->type == NodeType::WHILE)
        {
            inWhile = true;
        }
        else if (root->type == NodeType::BLOCK)
        {
            break;
        }
    }

    if (!inWhile)
    {
        SemanticError(copy->attribute->line, "Break is not inside WHILE loop");
    }
}

void InsertGlobalFunc(std::string literal, DataType returnType, std::vector<DataType> paramType, AST *node)
{
    GLOBAL_FUNC.insert({literal, {returnType, paramType, node}});
    node->f_record = &GLOBAL_FUNC.find(literal)->second;
}

void InsertGlobalVar(std::string literal, DataType type, AST *node)
{
    GLOBAL_VAR.insert({literal, {type, node}});
    node->id_record = &GLOBAL_VAR.find(literal)->second;
}

void InsertLocalVar(std::string scope, std::string literal, DataType type, AST *node)
{
    SYMBOL_TABLE.find(scope)->second.insert({literal, {type, node}});
    node->id_record = &SYMBOL_TABLE.find(scope)->second.find(literal)->second;
}

bool AssertNotDefinedInCurrentScope(std::string scope, AST *ptr)
{
    if (scope.empty())
    {
        if (GLOBAL_VAR.find(ptr->attribute->literal) != GLOBAL_VAR.end())
        {
            std::cerr << "Line: " << ptr->attribute->line << ", "
                      << ptr->attribute->literal << " was definted at or near line "
                      << GLOBAL_VAR.find(ptr->attribute->literal)->second.node->attribute->line
                      << std::endl;
            exit(EXIT_FAILURE);
        }

        if (GLOBAL_FUNC.find(ptr->attribute->literal) != GLOBAL_FUNC.end())
        {
            std::cerr << "Line: " << ptr->attribute->line << ", "
                      << ptr->attribute->literal << " was definted at or near line "
                      << GLOBAL_FUNC.find(ptr->attribute->literal)->second.node->attribute->line
                      << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        if (SYMBOL_TABLE.find(scope)->second.find(ptr->attribute->literal) != SYMBOL_TABLE.find(scope)->second.end())
        {
            std::cerr << "Line: " << ptr->attribute->line << ", "
                      << ptr->attribute->literal << " was definted at or near line "
                      << SYMBOL_TABLE.find(scope)->second.find(ptr->attribute->literal)->second.node->attribute->line
                      << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    return true;
}

void IdentifierDefined(std::string scope, AST *node)
{

    if (node->f_record || node->id_record)
    {
        return;
    }
    else
    {
        if (scope.empty())
        {
            if (GLOBAL_FUNC.find(node->attribute->literal) != GLOBAL_FUNC.end())
            {
                node->f_record = &GLOBAL_FUNC.find(node->attribute->literal)->second;
                return;
            }
            if (GLOBAL_VAR.find(node->attribute->literal) != GLOBAL_VAR.end())
            {
                node->id_record = &GLOBAL_VAR.find(node->attribute->literal)->second;
                return;
            }
        }
        else
        {
            if (SYMBOL_TABLE.find(scope)->second.find(node->attribute->literal) != SYMBOL_TABLE.find(scope)->second.end())
            {
                node->id_record = &SYMBOL_TABLE.find(scope)->second.find(node->attribute->literal)->second;
                return;
            }
            else
            {
                if (GLOBAL_FUNC.find(node->attribute->literal) != GLOBAL_FUNC.end())
                {
                    node->f_record = &GLOBAL_FUNC.find(node->attribute->literal)->second;
                    return;
                }
                if (GLOBAL_VAR.find(node->attribute->literal) != GLOBAL_VAR.end())
                {
                    node->id_record = &GLOBAL_VAR.find(node->attribute->literal)->second;
                    return;
                }
            }
        }
    }

    std::cerr << "Line: " << node->attribute->line << ", "
              << node->attribute->literal << " was not defined in the scope "
              << std::endl;
    exit(EXIT_FAILURE);
}

void SemanticError(int line, std::string reason)
{
    std::cerr << "Line " << line << ", "
              << reason
              << "."
              << std::endl;

    exit(EXIT_FAILURE);
}

// should be the 1st pass
void CollectGlobal(AST *root)
{
    // if the current node is global variable
    if (root->type == NodeType::GLOBAL_VAR_DEC)
    {
        if (AssertNotDefinedInCurrentScope("", Child(root, 1)))
        {

            // insert into global var table, second child's literal would be the identifier (key),
            // the first child would be the type of the identifier

            InsertGlobalVar(ChildLiteral(root, 1), NodeToData(ChildType(root, 0)), Child(root, 1));
        }
    }

    else if (root->type == NodeType::FUNC_DEC || root->type == NodeType::MAIN_DEC)
    {
        if (AssertNotDefinedInCurrentScope("", Child(root, 1)))
        {
            // insert into global function table
            // second child's literal would be the identifier (key)
            // the first child would be the return type
            // the formals would be the children of third child
            InsertGlobalFunc(ChildLiteral(root, 1), NodeToData(ChildType(root, 0)), ParseFormals(Child(root, 2)), Child(root, 1));
            if (root->type == NodeType::MAIN_DEC)
            {
                if (MAIN_ID.empty())
                {
                    MAIN_ID = ChildLiteral(root, 1);
                }
                else
                {
                    SemanticError(ChildLine(root, 1), "MAIN was already defined: " + GLOBAL_FUNC.find(MAIN_ID)->second.node->attribute->literal + ", at line " +
                                                          std::to_string(GLOBAL_FUNC.find(MAIN_ID)->second.node->attribute->line));
                }
            }
        }
    }

    for (auto c : root->children)
    {
        // recurse
        CollectGlobal(c);
    }
}

// BuildSymbolTable, also check if each identifier is defined in the scope
void BuildSymbolTable(AST *root, std::string current_scope)
{
    // preorder
    // create scope and add parameters into the newly created scope
    if (root->type == NodeType::FUNC_DEC || root->type == NodeType::MAIN_DEC)
    {
        current_scope = ChildLiteral(root, 1);

        CreateScope(current_scope);

        // for each formal of formals
        for (auto c : root->children[2]->children)
        {
            if (AssertNotDefinedInCurrentScope(current_scope, Child(c, 1)))
            {
                InsertLocalVar(current_scope, ChildLiteral(c, 1), NodeToData(ChildType(c, 0)), Child(c, 1));
            }
        }
    } // if the node is a varaiable, add into scope
    else if (root->type == NodeType::VAR_DEC)
    {
        if (AssertNotDefinedInCurrentScope(current_scope, Child(root, 1)))
        {
            InsertLocalVar(current_scope, ChildLiteral(root, 1), NodeToData(ChildType(root, 0)), Child(root, 1));
        }
    }
    else if (root->type == NodeType::IDENTIFIER)
    {
        IdentifierDefined(current_scope, root);
    }

    // recurse
    for (auto c : root->children)
    {
        BuildSymbolTable(c, current_scope);
    }

    TypeCheck(root);
}

#define isEqual(x, y) x->type == NodeType::y

DataType TypeLookup(AST *root)
{

    if (isEqual(root, FUNC_CALL))
    {
        return Child(root, 0)->f_record->returnType;
    }

    if (isEqual(root, NUMBER))
    {
        return DataType::INT;
    }

    if (isEqual(root, BIN_ARITHMETIC) || isEqual(root, UN_ARITHMETIC) || isEqual(root, NUMBER))
    {
        return DataType::INT;
    }

    if (isEqual(root, BIN_LOGIC) || isEqual(root, UN_LOGIC) || isEqual(root, BOOLEAN) || isEqual(root, TRUE) || isEqual(root, FALSE) || isEqual(root, BIN_RELATION))
    {
        return DataType::BOOL;
    }

    // if it is simply an Identifier, look it up in the scope
    if (root->type == NodeType::IDENTIFIER)
    {
        // grab the literal
        if (root->id_record)
        {
            return root->id_record->type;
        }
        SemanticError(root->attribute->line, root->attribute->literal + " is not defined");
    }

    if (root->type == NodeType::STRING)
    {
        return DataType::STRING;
    }

    if (root->type == NodeType::VOID)
    {
        return DataType::VOID;
    }

    if (root->type == NodeType::ASSIGN)
    {
        return TypeLookup(Child(root, 0));
    }

    return DataType::VOID;
}

void TypeCheck(AST *root)
{
    // check if assignment match the pair
    if (isEqual(root, ASSIGN))
    {
        DataType lhs = TypeLookup(Child(root, 0));
        DataType rhs = TypeLookup(Child(root, 1));

        if (lhs != rhs)
        {
            SemanticError(root->attribute->line, ChildLiteral(root, 0) + "can not be assigned to be " + DataTypeToString.find(rhs)->second);
        }
    }

    if (isEqual(root, BIN_ARITHMETIC))
    {
        DataType lhs = TypeLookup(Child(root, 0));
        DataType rhs = TypeLookup(Child(root, 1));

        if (lhs != DataType::INT)
        {
            SemanticError(root->attribute->line, "binary arithmetic operator " + root->symbol + " has Non NUMBER type on LHS.");
        }
        if (rhs != DataType::INT)
        {
            SemanticError(root->attribute->line, "binary arithmetic operator " + root->symbol + " has Non NUMBER type on RHS.");
        }
    }

    if (isEqual(root, UN_ARITHMETIC))
    {
        DataType c = TypeLookup(Child(root, 0));

        if (c != DataType::INT)
        {
            SemanticError(root->attribute->line, "unary arithmetic operator " + root->symbol + " has Non NUMBER type.");
        }
    }

    if (isEqual(root, BIN_LOGIC))
    {
        DataType lhs = TypeLookup(Child(root, 0));
        DataType rhs = TypeLookup(Child(root, 1));

        if (lhs != DataType::BOOL)
        {
            SemanticError(root->attribute->line, "binary boolean operator " + root->symbol + " has Non BOOLEAN type on LHS.");
        }
        else if (rhs != DataType::BOOL)
        {

            SemanticError(root->attribute->line, "binary boolean operator " + root->symbol + " has Non BOOLEAN type on RHS.");
        }
    }

    if (isEqual(root, UN_LOGIC))
    {
        DataType c = TypeLookup(Child(root, 0));

        SemanticError(root->attribute->line, "binary boolean operator " + root->symbol + " has Non BOOLEAN type.");
    }

    if (isEqual(root, BIN_RELATION))
    {

        DataType lhs = TypeLookup(Child(root, 0));
        DataType rhs = TypeLookup(Child(root, 1));

        if (lhs != DataType::INT)
        {
            SemanticError(root->attribute->line, "binary relation operator " + root->symbol + " has Non NUMBER type on LHS.");
        }
        else if (rhs != DataType::INT)
        {

            SemanticError(root->attribute->line, "binary relation operator " + root->symbol + " has Non NUMBER type on RHS.");
        }
    }

    if (isEqual(root, WHILE))
    {
        DataType condition = TypeLookup(root->children[0]);

        if (condition != DataType::BOOL)
        {
            SemanticError(ChildLine(root, 0), "WHILE has non BOOLEAN condition");
        }
    }

    if (isEqual(root, IF))
    {
        DataType condition = TypeLookup(root->children[0]);

        if (condition != DataType::BOOL)
        {
            SemanticError(ChildLine(root, 0), "IF has non BOOLEAN condition.");
        }
    }

    if (isEqual(root, IF_ELSE))
    {
        DataType condition = TypeLookup(root->children[0]);

        if (condition != DataType::BOOL)
        {
            SemanticError(ChildLine(root, 0), "IF_ELSE has non BOOLEAN condition.");
        }
    }

    if (isEqual(root, FUNC_CALL))
    {
        if (!ChildLiteral(root, 0).empty() && ChildLiteral(root, 0) == MAIN_ID)
        {
            SemanticError(ChildLine(root, 0), "program attempted to call MAIN");
        }

        if (Child(root, 0)->f_record)
        {
            ActualsMatchFormals(Child(root, 0), Child(root, 1));
        }
        else
        {
            SemanticError(ChildLine(root, 0), "function " + ChildLiteral(root, 0) + " was not defined");
        }
    }
}

void FinalCheck(AST *root, std::string current_scope)
{

    if (root->type == NodeType::FUNC_DEC || root->type == NodeType::MAIN_DEC)
    {
        current_scope = ChildLiteral(root, 1);

        if (GLOBAL_FUNC.find(current_scope)->second.returnType != DataType::VOID)
        {
            if (!ContainReturn(root))
            {
                SemanticError(ChildLine(root, 1), "non-void function " + current_scope + " does not return");
            }
        }
    }

    for (auto c : root->children)
    {
        FinalCheck(c, current_scope);
    }

    // check if a break statement is inside WHILE loop
    if (root->type == NodeType::BREAK)
    {
        BreakInWhile(root);
    }

    // check if return type is correct
    if (root->type == NodeType::RETURN)
    {
        DataType returnValue;

        if (root->children.empty())
        {
            returnValue = DataType::VOID;
        }
        else
        {
            returnValue = TypeLookup(root->children[0]);
        }

        if (returnValue != GLOBAL_FUNC.find(current_scope)->second.returnType)
        {
            SemanticError(root->attribute->line, "function " + current_scope + " returns wrong type");
        }
    }
}

void dummy_break_point()
{
    std::cout << "Enter" << std::endl;
    int v = 5;
    std::cout << "Exit" << std::endl;
}
