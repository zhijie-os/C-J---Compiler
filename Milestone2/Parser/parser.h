#ifndef PARSER_H
#define PARSER_H

#include <stdlib.h>

extern FILE *yyin;
extern int yylineno;    /* from lexer*/
void yyerror(char const *s);

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
struct ast *atomic_ast(const char *symbol, int line_num, const char *atr);
void print_tree(struct ast *root, int level);

void lexer_string_error(const char* info);
void lexer_general_error();

#endif