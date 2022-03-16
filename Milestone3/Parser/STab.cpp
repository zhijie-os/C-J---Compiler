#include "STab.h"
#include "AST.h"

std::unordered_map<std::string, FuncRecord> GLOBAL_FUNC;
std::unordered_map<std::string, DataType> GLOBAL_VAR;
std::unordered_map<std::string, std::unordered_map<std::string, DataType>> SYMBOL_TABLE;

const std::unordered_map<std::string, FuncRecord> LIB{
    {"getchar", {{DataType::INT}, {}}},
    {"halt", {{DataType::VOID}, {DataType::VOID}}},
    {"printb", {{DataType::VOID}, {DataType::BOOL}}},
    {"printc", {{DataType::VOID}, {DataType::INT}}},
    {"printi", {{DataType::VOID}, {DataType::INT}}},
    {"prints", {{DataType::VOID}, {DataType::STRING}}},
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
    for (auto c : root->children[2]->children)
    {
        // this formal's first child is the type, push it in to the toReturn
        toReturn.push_back(NodeTypeToDataType.find(c->children[0]->type)->second);
    }

    return toReturn;
}

#define ChildType(p, i) p->children[i]->type
#define ChildLiteral(p, i) p->children[i]->attribute->literal
#define NodeToData(x) NodeTypeToDataType.find(x)->second

// should be the 1st pass
void CollectGlobal(AST *root)
{
    // if the current node is global variable
    if (root->type == NodeType::GLOBAL_VAR_DEC)
    {
        if(GLOBAL_FUNC.find(ChildLiteral(root, 1))!=GLOBAL_FUNC.end())
        {
            std::cerr << root->children[1]->attribute->literal << " was double definted at or near line "
                          << root->children[1]->attribute->line
                          << std::endl;
                exit(EXIT_FAILURE);
        }
    
        // insert into global var table, second child's literal would be the identifier (key),
        // the first child would be the type of the identifier
        GLOBAL_VAR.insert({ChildLiteral(root, 1),
                           NodeToData(ChildType(root, 0))});
    }

    else if (root->type == NodeType::FUNC_DEC || root->type == NodeType::MAIN_DEC)
    {

        if(GLOBAL_FUNC.find(ChildLiteral(root,1))!=GLOBAL_FUNC.end())
        {

        std::cerr << root->children[1]->attribute->literal << " was double definted at or near line "
                          << root->children[1]->attribute->line
                          << std::endl;
                exit(EXIT_FAILURE);
        }

        // insert into global function table
        // second child's literal would be the identifier (key)
        // the first child would be the return type
        // the formals would be the children of third child
        GLOBAL_FUNC.insert({ChildLiteral(root, 1),
                            {NodeToData(ChildType(root, 0)), ParseFormals(root)}});
    }

    for (auto c : root->children)
    {
        // recurse
        CollectGlobal(c);
    }
}

#define CreateScope(x) SYMBOL_TABLE.insert({x, {}});

// BuildSymbolTable, also check if each identifier is defined in the scope
void BuildSymbolTable(AST *root, std::string current_scope)
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
                std::cerr << c->children[1]->attribute->literal << " was double definted at or near line "
                          << c->children[1]->attribute->line
                          << std::endl;
                exit(EXIT_FAILURE);
            }

            // find the table of current_scope
            SYMBOL_TABLE.find(current_scope)->second.insert({c->children[1]->attribute->literal,                      // formal's 2nd child is the identifier
                                                             NodeTypeToDataType.find(c->children[0]->type)->second}); // formal's 1st child has the type
        }
    }

    // if the node is a varaiable, add into scope
    if (root->type == NodeType::VAR_DEC)
    {
        if (SYMBOL_TABLE.find(current_scope)->second.find(root->children[1]->attribute->literal) != SYMBOL_TABLE.find(current_scope)->second.end())
        {
            std::cerr << root->children[1]->attribute->literal << " was double definted at or near line"
                      << root->children[1]->attribute->line
                      << std::endl;
            exit(EXIT_FAILURE);
        }

        SYMBOL_TABLE.find(current_scope)->second.insert({root->children[1]->attribute->literal, NodeTypeToDataType.find(root->children[0]->type)->second});
    }

    // recurse
    for (auto c : root->children)
    {
        BuildSymbolTable(c, current_scope);
    }

    // postorder, check if a identifier already defined before using
    if (root->type == NodeType::IDENTIFIER)
    {
        // find the scope of the identifier, if any
        auto current_table = SYMBOL_TABLE.find(current_scope)->second;

        if (current_table.find(root->attribute->literal) == current_table.end())
        {
            // if there is no scope for the identifier as local variable, try global
            if (GLOBAL_VAR.find(root->attribute->literal) == GLOBAL_VAR.end()      // if it is global variable
                && GLOBAL_FUNC.find(root->attribute->literal) == GLOBAL_FUNC.end() // if it is global function
                && LIB.find(root->attribute->literal) == LIB.end())                // if it is predefined
            {
                // otherwise, the identifier is not defined!
                std::cerr << "Identifier: " << root->attribute->literal << " at or near line " << root->attribute->line
                          << " is undefined in current scope.\n"
                          << std::endl;
                exit(EXIT_FAILURE);
            }
        }
    }
}

#define isEqual(x, y) x->type == NodeType::y

DataType TypeLookup(AST *root, std::string scope)
{
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
                return SYMBOL_TABLE.find(scope)->second.find(id)->second;
            }
        }

        // otherwise, try to find in the global scope
        if (GLOBAL_VAR.find(id) != GLOBAL_VAR.end())
        {
            // if found, return
            return GLOBAL_VAR.find(id)->second;
        }
    }

    // not found
    std::cerr << root->symbol << " at or near line " << root->attribute->line
              << " is undefined in current scope.\n"
              << std::endl;
    exit(EXIT_FAILURE);
}

void TypeCheck(AST *root, std::string current_scope)
{

    if (isEqual(root, FUNC_DEC) || isEqual(root, MAIN_DEC))
    {
        // change into a local scope
        current_scope = root->children[1]->attribute->literal;
    }

    // bottom up, i.e, postorder for soundness
    for (auto c : root->children)
    {
        TypeCheck(c, current_scope);
    }

    // check if assignment match the pair
    if (isEqual(root, ASSIGN))
    {
        DataType lhs = TypeLookup(root->children[0], current_scope);
        DataType rhs = TypeLookup(root->children[1], current_scope);
        if (lhs != rhs)
        {
            std::cerr << "Failed to Type Assignment "
                      << " for " << root->children[0]->attribute->literal
                      << " and "
                      << root->children[1]->symbol
                      << " at or near line " << root->attribute->line
                      << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    if (isEqual(root, BIN_ARITHMETIC))
    {
        DataType lhs = TypeLookup(root->children[0], current_scope);
        DataType rhs = TypeLookup(root->children[1], current_scope);

        if (lhs != DataType::INT || rhs != DataType::INT)
        {
            std::cerr << "Fail to Type Binary Arithmetic "
                      << root->symbol
                      << " for "
                      << root->children[0]->symbol
                      << " and "
                      << root->children[1]->symbol
                      << " at or near line " << root->attribute->line
                      << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    if (isEqual(root, UN_ARITHMETIC))
    {
        DataType c = TypeLookup(root->children[0], current_scope);

        if (c != DataType::INT)
        {
            std::cerr << "Fail to Type Unary Arithmetic "
                      << root->symbol
                      << " for "
                      << root->children[0]->symbol
                      << " at or near line " << root->attribute->line
                      << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    if (isEqual(root, BIN_LOGIC))
    {
        DataType lhs = TypeLookup(root->children[0], current_scope);
        DataType rhs = TypeLookup(root->children[1], current_scope);

        if (lhs != DataType::BOOL || rhs != DataType::BOOL)
        {
            std::cerr << "Fail to Type Binary LOGIC "
                      << root->symbol
                      << " for "
                      << root->children[0]->symbol
                      << " and "
                      << root->children[1]->symbol
                      << " at or near line " << root->attribute->line
                      << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    if (isEqual(root, UN_LOGIC))
    {
        DataType c = TypeLookup(root->children[0], current_scope);

        if (c != DataType::BOOL)
        {
            std::cerr << "Fail to Type Unary LOGIC"
                      << " for "
                      << root->children[0]->symbol
                      << " at or near line " << root->attribute->line
                      << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    if (isEqual(root, WHILE))
    {
    }
}



// int NumMain(AST*root)
// {
//     if()

//     int occurrence = 0;

//     for(auto c:root->children)
//     {
//         NumMain(c,)
//     }
// }


void dummy_break_point()
{
    std::cout << "Enter" << std::endl;
    int v = 5;
    std::cout << "Exit" << std::endl;
}
