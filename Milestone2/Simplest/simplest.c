#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "simplest.h"

void yyerror(char const *s)
{
    fprintf(stderr, "%s\n", s);
}

struct ast *new_nonterminal(const char *symbol, struct ast *c1, struct ast *c2, struct ast *c3)
{
    struct ast *a = (struct ast *)malloc(sizeof(struct ast));

    a->symbol = strdup(symbol);

    a->num_of_children = 0;
    if (c1 != NULL)
    {
        a->num_of_children += 1;
    }
    if (c2 != NULL)
    {
        a->num_of_children += 1;
    }
    if (c3 != NULL)
    {
        a->num_of_children += 1;
    }



    a->children = (struct ast **)malloc(a->num_of_children*sizeof(struct ast*));

  
    a->children[0] = c1;
    a->children[1] = c2;
    a->children[2] = c3;

    return a;
};

struct ast *new_reserved(const char *symbol)
{
    struct ast *a = (struct ast *)malloc(sizeof(struct ast));

    a->symbol = strdup(symbol);

    a->num_of_children = 0;
    return a;
};

struct ast *new_num(const char *symbol, struct info *attribute)
{
    struct ast *a = (struct ast *)malloc(sizeof(struct ast));
    a->symbol = strdup(symbol);
    a->attribute = attribute;

    a->num_of_children = 0;

    return a;
}

struct info *create_atr(int lineno, const char *literal)
{
    struct info *a = (struct info *)malloc(sizeof(struct info));

    a->lineno = lineno;
    a->literal = strdup(literal);

    return a;
}

void print_tree(struct ast *root, int level)
{
    for (int i = 0; i < level;i++)
    {
        printf("  ");
    }

    printf("%s", root->symbol);

    if (root->attribute)
    {
        printf("{lineno:%d, literal:%s}", root->attribute->lineno, root->attribute->literal);
    }
    
    printf("\n");
    
    for (int i = 0; i < root->num_of_children;i++)
    {   

        print_tree(root->children[i], level + 1);
    }
}

int main()
{
    return yyparse();
}