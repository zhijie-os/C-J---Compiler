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

#define ChildType(p,i)  p->children[i]->type
#define ChildLiteral(p,i) p->children[i]->attribute->literal
#define NodeToData(x) NodeTypeToDataType.find(x)->second


// should be the 1st pass
void CollectGlobal(AST *root)
{
    // if the current node is global variable
    if (root->type == NodeType::GLOBAL_VAR_DEC)
    {
        // insert into global var table, second child's literal would be the identifier (key),
        // the first child would be the type of the identifier
        GLOBAL_VAR.insert({ChildLiteral(root,1),
                           NodeToData(ChildType(root,0))});
    }
    else if (root->type == NodeType::FUNC_DEC || root->type == NodeType::MAIN_DEC)
    {
        // insert into global function table
        // second child's literal would be the identifier (key)
        // the first child would be the return type
        // the formals would be the children of third child
        GLOBAL_FUNC.insert({ChildLiteral(root,1),
                            {NodeToData(ChildType(root,0)), ParseFormals(root)}});
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
            // find the table of current_scope
            SYMBOL_TABLE.find(current_scope)->second.insert(
                {c->children[1]->attribute->literal, // formal's 2nd child is the identifier
                NodeTypeToDataType.find(c->children[0]->type)->second}); // formal's 1st child has the type
        }
    }


    // if the node is a varaiable, add into scope
    if (root->type == NodeType::VAR_DEC)
    {
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
            if (GLOBAL_VAR.find(root->attribute->literal) == GLOBAL_VAR.end()  // if it is global variable
            && GLOBAL_FUNC.find(root->attribute->literal) == GLOBAL_FUNC.end() // if it is global function
            && LIB.find(root->attribute->literal) == LIB.end()) // if it is predefined
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

DataType StabLookup(AST *root, std::string scope)
{
    if (root->type == NodeType::BIN_ARITHMETIC || root->type == NodeType::UN_ARITHMETIC || root->type == NodeType::NUMBER)
    {
        return DataType::INT;
    }

    if (root->type == NodeType::BIN_LOGIC || root->type == NodeType::UN_LOGIC 
    || root->type == NodeType::BOOLEAN || root->type == NodeType::TRUE || root->type == NodeType::FALSE)
    {
        return DataType::BOOL;
    }

    if (root->type == NodeType::FUNC_DEC || root->type == NodeType::MAIN_DEC)
    {
        return GLOBAL_FUNC.find(root->children[1]->attribute->literal)->second.returnType;
    }

    if (root->type == NodeType::IDENTIFIER)
    {

        std::string id = root->attribute->literal;

        if (SYMBOL_TABLE.find(scope) != SYMBOL_TABLE.end())
        {
            if (SYMBOL_TABLE.find(scope)->second.find(id) != SYMBOL_TABLE.find(scope)->second.end())
            {
                return SYMBOL_TABLE.find(scope)->second.find(id)->second;
            }
        }

        if (GLOBAL_VAR.find(id) != GLOBAL_VAR.end())
        {
            return GLOBAL_VAR.find(id)->second;
        }
    }

    // not found
    std::cerr << "Identifier: " << root->attribute->literal << " at or near line " << root->attribute->line
              << " is undefined in current scope.\n"
              << std::endl;
    exit(EXIT_FAILURE);
}

void TypeCheck(AST *root, std::string current_scope)
{

    if (root->type == NodeType::FUNC_DEC || root->type == NodeType::MAIN_DEC)
    {
        current_scope = root->children[1]->attribute->literal;
    }

    // bottom up, i.e, postorder
    for (auto c : root->children)
    {
        TypeCheck(c, current_scope);
    }

    if (root->type == NodeType::ASSIGN)
    {
        DataType lhs = StabLookup(root->children[0], current_scope);
        DataType rhs = StabLookup(root->children[1], current_scope);
        if (lhs != rhs)
        {
            std::cerr << "Failed to match " << root->children[0]->attribute->literal 
            << " with RHS at or near line " <<  root->children[0]->attribute->line
                      << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    if (root->type == NodeType::BIN_ARITHMETIC)
    {
        DataType lhs = StabLookup(root->children[0], current_scope);
        DataType rhs = StabLookup(root->children[0], current_scope);

        if(lhs!=DataType::INT||rhs!=DataType::INT)
        {
            std::cerr << "Fail to Type Binary Arithmetic" 
                      << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    if (root->type == NodeType::UN_ARITHMETIC)
    {
        DataType lhs = StabLookup(root->children[0], current_scope);

        if(lhs!=DataType::INT)
        {
            std::cerr << "Fail to Type Binary Arithmetic" 
                      << std::endl;
            exit(EXIT_FAILURE);
        }
    }

     if (root->type == NodeType::BIN_LOGIC)
    {
        DataType lhs = StabLookup(root->children[0], current_scope);
        DataType rhs = StabLookup(root->children[0], current_scope);

        if(lhs!=DataType::BOOL||rhs!=DataType::BOOL)
        {
            std::cerr << "Fail to Type Binary LOGIC" 
                      << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    if (root->type == NodeType::UN_LOGIC)
    {
        DataType lhs = StabLookup(root->children[0], current_scope);

        if(lhs!=DataType::BOOL)
        {
            std::cerr << "Fail to Type Binary LOGIC" 
                      << std::endl;
            exit(EXIT_FAILURE);
        }
    }


}

void dummy_break_point()
{
    std::cout << "Enter" << std::endl;
    int v = 5;
    std::cout << "Exit" << std::endl;
}
