#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "AST.h"

extern FILE *yyin;
extern int yydebug;
extern int yylineno;   
void yyerror(char const *s);
extern int yylex (void);
extern int yyparse (void);
extern AST* yylval;

extern int num_lexer_error;


struct ast
{
    char *symbol;
    int num_of_children;
    int line_num;
    char *attribute;
    struct ast **children;
};



struct ast *new_ast(const char *symbol, int num_of_children, ...);
struct ast *attach_new_children(struct ast* parent, int num_new_children, ...);
struct ast *steal_children(struct ast *a, struct ast *b);
struct ast *atomic_ast(const char *symbol, int line_num, const char *atr);



struct ast  *rename_ast(const char *symbol, struct ast *a);
struct ast  *fold_ast_base(struct ast *b);
struct ast  *fold_ast(struct ast *a, struct ast* b);
void print_tree(struct ast *root, int level);

void lexer_string_error(const char* info);
void lexer_general_error();

#endif