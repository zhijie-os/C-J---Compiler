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



struct ast *new_nonterminal(const char *symbol,struct ast *c1, struct ast *c2, struct ast *c3);
struct ast *new_reserved(const char *symbol);
struct ast *new_num(const char *symbol, struct info *attribute);
struct info *create_atr(int lineno, const char *literal);
void print_tree(struct ast *root, int level);

#endif