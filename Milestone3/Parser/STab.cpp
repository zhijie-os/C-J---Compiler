#include "STab.h"
#include "AST.h"

#define ChildType(p, i) p->children[i]->type
#define ChildLiteral(p, i) p->children[i]->attribute->literal
#define NodeToData(x) NodeTypeToDataType.find(x)->second

std::string MAIN_ID = "";
std::unordered_map<std::string, FuncRecord> GLOBAL_FUNC
{
    {"getchar", {{DataType::INT}, {}}},
    {"halt",    {{DataType::VOID}, {}}},
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

const std::unordered_map<std::string, FuncRecord> LIB{
   
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
        toReturn.push_back(NodeTypeToDataType.find(c->children[0]->type)->second);
    }

    return toReturn;
}

void ActualsMatchFormals(AST *root, std::string scope)
{
    std::vector<DataType> formals = GLOBAL_FUNC.find(ChildLiteral(root, 0))->second.paramType;
    std::vector<DataType> actuals;

    // for each actual in actuals
    for (auto c : root->children[1]->children)
    {
        // this actual's first child
        actuals.push_back(TypeLookup(c, scope));
    }

    if (formals.size() != actuals.size())
    {
        SemanticError(root->children[0]->attribute->line, ChildLiteral(root, 0) + ": ACTUALS does not match FORMALS by size");
    }

    for (int i = 0; i < formals.size(); i++)
    {
        if (formals[i] != actuals[i])
        {
            SemanticError(root->children[0]->attribute->line, ChildLiteral(root, 0) + ": ACTUALS does not match FORMALS by type");
        }
    }
}


bool ContainReturn(AST* root)
{
    if(root->type==NodeType::RETURN)
    {
        return true;
    }
    
    for(auto c:root->children)
    {
        if(ContainReturn(c))
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
    AST* copy = root;

    while(root->parent)
    {
        root= root->parent;
        if(root->type==NodeType::WHILE)
        {
            inWhile = true;
        }
        else if(root->type==NodeType::BLOCK)
        {
            break;
        }
    }

    if(!inWhile)
    {
        SemanticError(copy->attribute->line,"Break is not inside WHILE loop");
    }

}

bool NotGlobalDefined(std::string id, AST *ptr)
{
    if (GLOBAL_VAR.find(id) != GLOBAL_VAR.end())
    {
        std::cerr << "Line: " << ptr->attribute->line << ", "
                  << ptr->attribute->literal << " was definted at or near line "
                  << GLOBAL_VAR.find(id)->second.node->attribute->line
                  << std::endl;
        exit(EXIT_FAILURE);
    }

    if (GLOBAL_FUNC.find(id) != GLOBAL_FUNC.end())
    {
        std::cerr << "Line: " << ptr->attribute->line << ", "
                  << ptr->attribute->literal << " was definted at or near line "
                  << GLOBAL_FUNC.find(id)->second.node->attribute->line
                  << std::endl;
        exit(EXIT_FAILURE);
    }

    return true;
}

void InsertGlobalFunc(std::string literal, DataType returnType, std::vector<DataType> paramType, AST *node)
{
    GLOBAL_FUNC.insert({literal, {returnType, paramType, node}});
}

void InsertGlobalVar(std::string literal, DataType type, AST *node)
{
    GLOBAL_VAR.insert({literal, {type, node}});
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
        if (NotGlobalDefined(ChildLiteral(root, 1), root->children[1]))
        {

            // insert into global var table, second child's literal would be the identifier (key),
            // the first child would be the type of the identifier
            InsertGlobalVar(ChildLiteral(root, 1), NodeToData(ChildType(root, 0)), root->children[1]);
        }
    }

    else if (root->type == NodeType::FUNC_DEC || root->type == NodeType::MAIN_DEC)
    {
        if (NotGlobalDefined(ChildLiteral(root, 1), root->children[1]))
        {
            // insert into global function table
            // second child's literal would be the identifier (key)
            // the first child would be the return type
            // the formals would be the children of third child
            InsertGlobalFunc(ChildLiteral(root, 1), NodeToData(ChildType(root, 0)), ParseFormals(root->children[2]), root->children[1]);
            if (root->type == NodeType::MAIN_DEC)
            {
                if (MAIN_ID.empty())
                {
                    MAIN_ID = ChildLiteral(root, 1);
                }
                else
                {
                    SemanticError(root->children[1]->attribute->line, "MAIN was already defined: " 
                    + GLOBAL_FUNC.find(MAIN_ID)->second.node->attribute->literal 
                    + ", at line "+ 
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

#define CreateScope(x) SYMBOL_TABLE.insert({x, {}});

// BuildSymbolTable, also check if each identifier is defined in the scope
void BuildSymbolTable(AST *root, std::string current_scope, int level)
{
    // preorder

    // create scope and add parameters into the newly created scope
    if (root->type == NodeType::FUNC_DEC || root->type == NodeType::MAIN_DEC)
    {
        current_scope = root->children[1]->attribute->literal;

        CreateScope(current_scope);

        // for each formal of formals
        for (auto c : root->children[2]->children)
        {
            if (SYMBOL_TABLE.find(current_scope)->second.find(c->children[1]->attribute->literal) != SYMBOL_TABLE.find(current_scope)->second.end())
            {
                SemanticError(c->children[1]->attribute->line, c->children[1]->attribute->literal + "was double definted");
            }

            // find the table of current_scope
            SYMBOL_TABLE.find(current_scope)->second.insert({c->children[1]->attribute->literal,                                        // formal's 2nd child is the identifier
                                                             {NodeTypeToDataType.find(c->children[0]->type)->second, c->children[1]}}); // formal's 1st child has the type
        }
    }

    // if the node is a varaiable, add into scope
    if (root->type == NodeType::VAR_DEC)
    {
        if (SYMBOL_TABLE.find(current_scope)->second.find(root->children[1]->attribute->literal) != SYMBOL_TABLE.find(current_scope)->second.end())
        {
            SemanticError(root->children[1]->attribute->line, root->children[1]->attribute->literal + " was double definted");
        }

        SYMBOL_TABLE.find(current_scope)->second.insert({root->children[1]->attribute->literal, {NodeTypeToDataType.find(root->children[0]->type)->second, root->children[1]}});
    }

    TypeCheck(root,current_scope);

    PrettyPrint(root,current_scope,level);

        // recurse
    for (auto c : root->children)
    {
        BuildSymbolTable(c, current_scope,level+1);
    }
}

#define isEqual(x, y) x->type == NodeType::y

DataType TypeLookup(AST *root, std::string scope)
{

    if (isEqual(root,FUNC_CALL))
    {
        return GLOBAL_FUNC.find(ChildLiteral(root,0))->second.returnType;
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

    // if it is Function Call
    if (isEqual(root, FUNC_CALL))
    {
        // find the return type of the function in the function table
        return GLOBAL_FUNC.find(ChildLiteral(root, 0))->second.returnType;
    }

    // if it is simply an Identifier, look it up in the scope
    if (root->type == NodeType::IDENTIFIER)
    {
        // grab the literal
        std::string id = root->attribute->literal;

        // if the scope is not null
        if (SYMBOL_TABLE.find(scope) != SYMBOL_TABLE.end())
        {
            // try to find the identifier in the scope
            if (SYMBOL_TABLE.find(scope)->second.find(id) != SYMBOL_TABLE.find(scope)->second.end())
            {
                // if found, return the type
                return SYMBOL_TABLE.find(scope)->second.find(id)->second.type;
            }
        }

        // otherwise, try to find in the global scope
        if (GLOBAL_VAR.find(id) != GLOBAL_VAR.end())
        {
            // if found, return
            return GLOBAL_VAR.find(id)->second.type;
        }

        SemanticError(root->attribute->line,root->attribute->literal+" is not defined");
    }

    if (root->type == NodeType::STRING)
    {
        return DataType::STRING;
    }

    if (root->type == NodeType::VOID)
    {
        return DataType::VOID;
    }

    if(root->type == NodeType::ASSIGN)
    {
        return TypeLookup(root->children[0],scope);
    }

    return DataType::VOID;
}

void TypeCheck(AST *root, std::string current_scope)
{
    // check if assignment match the pair
    if (isEqual(root, ASSIGN))
    {
        DataType lhs = TypeLookup(root->children[0], current_scope);
        DataType rhs = TypeLookup(root->children[1], current_scope);

        if (lhs != rhs)
        {
            SemanticError(root->attribute->line, root->children[0]->attribute->literal + "can not be assigned to be " + DataTypeToString.find(rhs)->second);
        }
    }

    if (isEqual(root, BIN_ARITHMETIC))
    {
        DataType lhs = TypeLookup(root->children[0], current_scope);
        DataType rhs = TypeLookup(root->children[1], current_scope);

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
        DataType c = TypeLookup(root->children[0], current_scope);

        if (c != DataType::INT)
        {
            SemanticError(root->attribute->line, "unary arithmetic operator " + root->symbol + " has Non NUMBER type.");
        }
    }

    if (isEqual(root, BIN_LOGIC))
    {
        DataType lhs = TypeLookup(root->children[0], current_scope);
        DataType rhs = TypeLookup(root->children[1], current_scope);

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
        DataType c = TypeLookup(root->children[0], current_scope);

        SemanticError(root->attribute->line, "binary boolean operator " + root->symbol + " has Non BOOLEAN type.");
    }


    if (isEqual(root, BIN_RELATION))
    {

        DataType lhs = TypeLookup(root->children[0], current_scope);
        DataType rhs = TypeLookup(root->children[1], current_scope);

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
        DataType condition = TypeLookup(root->children[0], current_scope);

        if (condition != DataType::BOOL)
        {
            SemanticError(root->children[0]->attribute->line, "WHILE has non BOOLEAN condition.");
        }
    }

    if (isEqual(root, IF))
    {
        DataType condition = TypeLookup(root->children[0], current_scope);

        if (condition != DataType::BOOL)
        {
            SemanticError(root->children[0]->attribute->line, "IF has non BOOLEAN condition.");
        }
    }

    if (isEqual(root, IF_ELSE))
    {
        DataType condition = TypeLookup(root->children[0], current_scope);

        if (condition != DataType::BOOL)
        {
            SemanticError(root->children[0]->attribute->line, "IF_ELSE has non BOOLEAN condition.");
        }
    }

    if (isEqual(root, FUNC_CALL))
    {
        if (!ChildLiteral(root, 0).empty() && ChildLiteral(root, 0) == MAIN_ID)
        {
            SemanticError(root->children[0]->attribute->line, "program attempted to call MAIN");
        }

        if (GLOBAL_FUNC.find(ChildLiteral(root, 0)) != GLOBAL_FUNC.end())
        {
            ActualsMatchFormals(root, current_scope);
        }
        else
        {
            SemanticError(root->children[0]->attribute->line, "function " + ChildLiteral(root, 0) + " was not defined");
        }
    }
}

void FinalCheck(AST* root, std::string current_scope)
{
    
    if (root->type == NodeType::FUNC_DEC || root->type == NodeType::MAIN_DEC)
    {
        current_scope = root->children[1]->attribute->literal;

        if(GLOBAL_FUNC.find(current_scope)->second.returnType!=DataType::VOID)
        {
            if(!ContainReturn(root))
            {
                SemanticError(root->children[1]->attribute->line, "non-void function " + current_scope + " does not return");
            }
        }
    }

    for(auto c:root->children)
    {
        FinalCheck(c,current_scope);
    }

    // check if a break statement is inside WHILE loop
    if(root->type==NodeType::BREAK)
    {
        BreakInWhile(root);
    }


    // check if return type is correct
    if(root->type==NodeType::RETURN)
    {
        DataType returnValue;

        if(root->children.empty())
        {
            returnValue = DataType::VOID;
        }
        else
        {
            returnValue = TypeLookup(root->children[0],current_scope);
        }

        if(returnValue!=GLOBAL_FUNC.find(current_scope)->second.returnType)
        {
            SemanticError(root->attribute->line, "function "+ current_scope +" returns wrong type");
        }
    }
}

void dummy_break_point()
{
    std::cout << "Enter" << std::endl;
    int v = 5;
    std::cout << "Exit" << std::endl;
}
