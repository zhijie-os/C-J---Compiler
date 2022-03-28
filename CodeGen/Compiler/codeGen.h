#pragma once
#include "AST.h"

void yycodegen(AST *root);
void GenGlobalVar(AST *root);

void GenMain(AST *root);
int CountLocal(AST* root);
void GenFunc(AST *root);
std::string GenLabel();

void GenExpr(AST* root);
void GenCondition(AST* root);
void GenString(AST *root);
void GenBoolean(AST *root);
void GenNumber(AST *root);
void GenFuncCall(AST* root);
void GenCode(AST* root);
void GenFuncDec(AST *root);
void GenFuncLabel(AST *root);
void GenPreclude();
void Descend(AST *root);