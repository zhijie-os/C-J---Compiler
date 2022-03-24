#pragma once
#include "AST.h"


void yycodegen(AST *root);
void GenGlobalVar(AST *root);

void GenMain(AST *root);
void GenText();
int CountLocal(AST* root);
void GenFunc(AST *root);
