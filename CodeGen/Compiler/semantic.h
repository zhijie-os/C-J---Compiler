#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include "Type.h"
#include "AST.h"
#include <iostream>

// macros used in the Semantic.cpp
#define CreateScope(x) SYMBOL_TABLE.insert({x, {}});
#define Child(p, i) p->children[i]
#define ChildType(p, i) p->children[i]->type
#define ChildLiteral(p, i) p->children[i]->attribute->literal
#define ChildLine(p, i) p->children[i]->attribute->line
#define NodeToData(x) NodeTypeToDataType.find(x)->second
#define DataToString(x) DataTypeToString.find(x)->second
#define isEqual(x, y) x->type == NodeType::y

extern const std::unordered_map<NodeType, DataType> NodeTypeToDataType;
extern const std::unordered_map<DataType, std::string> DataTypeToString;
std::vector<DataType> ParseFormals(AST *root);


void ActualsMatchFormals(AST *root, std::string scope);

void BreakInWhile(AST *root);

void InsertGlobalFunc(std::string literal, DataType returnType, std::vector<DataType> paramType, AST* node);
void InsertGlobalVar(std::string literal, DataType type, AST* node);
void InsertLocalVar(std::string scope, std::string literal, DataType type, AST *node);


bool AssertNotDefinedInCurrentScope(std::string scope, AST *ptr);
bool NotGlobalDefined(std::string id, AST *ptr);
void IdentifierDefined(std::string scope,AST *node);
void CollectGlobal(AST *root);
void BuildSymbolTable(AST *root, std::string current_scope);
void TypeCheck(AST* root);
DataType TypeLookup(AST* root);
void FinalCheck(AST* root, std::string);
void SemanticError(int, std::string);
void MainDefined();
bool ContainReturn(AST* root);

void yysemantic(AST *root);

// int NumMain(AST*root, int num);
void dummy_break_point();
extern std::unordered_map<std::string, FuncRecord> GLOBAL_FUNC;
extern std::unordered_map<std::string, IdentifierRecord> GLOBAL_VAR;
extern std::unordered_map<std::string, std::unordered_map<std::string, IdentifierRecord>> SYMBOL_TABLE;


extern std::string MAIN_ID;