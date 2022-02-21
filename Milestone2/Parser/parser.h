#ifndef PARSER_H
#define PARSER_H

#include <stdlib.h>


extern int yylineno;    /* from lexer*/
void yyerror(char const *s);

extern int num_lexer_error;
extern int line_num;

struct info{
    int lineno;
    char *literal;
};

struct ast
{
    char *symbol;
    int num_of_children;
    struct info *attribute;
    struct ast **children;
};



struct ast *new_nonterminal(const char *symbol, int num_of_children, ...);
struct ast *new_reserved(const char *symbol);
struct ast *new_terminal(const char *symbol, struct info *attribute);
struct info *create_atr(int lineno, const char *literal);
void print_tree(struct ast *root, int level);

void lexer_string_error(const char* info);
void lexer_general_error();

#endif