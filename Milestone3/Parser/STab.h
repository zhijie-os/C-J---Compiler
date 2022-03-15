#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include "Type.h"
#include "AST.h"
#include <iostream>

struct FuncRecord
{
    DataType returnType;
    std::vector<DataType> paramType;
};


extern const std::unordered_map<std::string, FuncRecord> LIB;

extern const std::unordered_map<NodeType, DataType> NodeTypeToDataType;
std::vector<DataType> ParseFormals(AST *root);

void CollectGlobal(AST *root);
void BuildSymbolTable(AST *root, std::string current_scope);
void TypeCheck(AST* root);
DataType StabLookup(AST* root, std::string);
void dummy_break_point();
extern std::unordered_map<std::string, FuncRecord> GLOBAL_FUNC;
extern std::unordered_map<std::string, DataType> GLOBAL_VAR;
extern std::unordered_map<std::string, std::unordered_map<std::string, DataType>> SYMBOL_TABLE;
