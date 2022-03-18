#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include "Type.h"
#include "AST.h"
#include <iostream>



extern const std::unordered_map<NodeType, DataType> NodeTypeToDataType;
extern const std::unordered_map<DataType, std::string> DataTypeToString;
std::vector<DataType> ParseFormals(AST *root);


void ActualsMatchFormals(AST *root, std::string scope);

void BreakInWhile(AST *root);

void InsertGlobalFunc(std::string literal, DataType returnType, std::vector<DataType> paramType, AST* node);
void InsertGlobalVar(std::string literal, DataType type, AST* node);
bool NotGlobalDefined(std::string id, AST *ptr);
void CollectGlobal(AST *root);
void BuildSymbolTable(AST *root, std::string current_scope,int level);
void TypeCheck(AST* root, std::string current_scope);
DataType TypeLookup(AST* root, std::string);
void FinalCheck(AST* root, std::string);
void SemanticError(int, std::string);
void MainDefined();
bool ContainReturn(AST* root);

// int NumMain(AST*root, int num);
void dummy_break_point();
extern std::unordered_map<std::string, FuncRecord> GLOBAL_FUNC;
extern std::unordered_map<std::string, IdentifierRecord> GLOBAL_VAR;
extern std::unordered_map<std::string, std::unordered_map<std::string, IdentifierRecord>> SYMBOL_TABLE;


extern std::string MAIN_ID;