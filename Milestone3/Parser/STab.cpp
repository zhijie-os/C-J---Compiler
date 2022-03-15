#include "STab.h"
#include "AST.h"

std::unordered_map<std::string, FuncRecord> GLOBAL_FUNC;
std::unordered_map<std::string, DataType> GLOBAL_VAR;


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
    for(auto c : root->children[2]->children)
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
    else if (root->type == NodeType::FUNC_DEC)
    {
        GLOBAL_FUNC.insert({root->children[1]->attribute->literal,
        {NodeTypeToDataType.find(root->children[0]->type)->second,ParseFormals(root)}});
    }

    for (auto c : root->children)
    {
        CollectGlobal(c);
    }
}

void dummy_break_point()
{
    std::cout <<"Enter"<<std::endl;
    int v =5;
    std::cout <<"Exit"<<std::endl;
}
