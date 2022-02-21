#ifndef SIMPLEST_H
#define SIMPLEST_H

extern int yylineno;    /* from lexer*/
void yyerror(char const *s);


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



struct ast *new_ast(const char *symbol, int num, ...);
struct ast *new_reserved(const char *symbol);
struct ast *new_num(const char *symbol, struct info *attribute);
struct info *create_atr(int lineno, const char *literal);
void print_tree(struct ast *root, int level);

#endif