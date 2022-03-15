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



void CollectGlobal(AST *root)
{
    if (root->type == NodeType::GLOBAL_VAR_DEC)
    {
        GLOBAL_VAR.insert({root->children[1]->attribute->literal,
                           NodeTypeToDataType.find(root->children[0]->type)->second});
    }
    else if (root->type == NodeType::FUNC_DEC || root->type == NodeType::MAIN_DEC)
    {
        GLOBAL_FUNC.insert({root->children[1]->attribute->literal,
                            {NodeTypeToDataType.find(root->children[0]->type)->second, ParseFormals(root)}});
    }

    for (auto c : root->children)
    {
        CollectGlobal(c);
    }
}

void BuildSymbolTable(AST *root, std::string current_scope)
{
    // preorder
    if (root->type == NodeType::FUNC_DEC || root->type == NodeType::MAIN_DEC)
    {
        current_scope = root->children[1]->attribute->literal;

        SYMBOL_TABLE.insert({current_scope, {}});

        for (auto c : root->children[2]->children)
        {

            SYMBOL_TABLE.find(current_scope)->second.insert({c->children[1]->attribute->literal, NodeTypeToDataType.find(c->children[0]->type)->second});
        }
    }
    if (root->type == NodeType::VAR_DEC)
    {
        SYMBOL_TABLE.find(current_scope)->second.insert({root->children[1]->attribute->literal, NodeTypeToDataType.find(root->children[0]->type)->second});
    }

    for (auto c : root->children)
    {
        BuildSymbolTable(c, current_scope);
    }

    if (root->type == NodeType::IDENTIFIER && !current_scope.empty())
    {
        auto current_table = SYMBOL_TABLE.find(current_scope)->second;
        if (current_table.find(root->attribute->literal) == current_table.end())
        {
            if (GLOBAL_VAR.find(root->attribute->literal) == GLOBAL_VAR.end() && GLOBAL_FUNC.find(root->attribute->literal) == GLOBAL_FUNC.end() && LIB.find(root->attribute->literal) == LIB.end())
            {

                std::cerr << "Identifier: " << root->attribute->literal << " at or near line " << root->attribute->line
                          << " is undefined in current scope.\n"
                          << std::endl;
                exit(EXIT_FAILURE);
            }
        }
    }
}

void dummy_break_point()
{
    std::cout << "Enter" << std::endl;
    int v = 5;
    std::cout << "Exit" << std::endl;
}
