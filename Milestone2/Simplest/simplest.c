#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "simplest.h"

void yyerror(char const *s)
{
    fprintf(stderr, "%s\n", s);
}

struct ast *new_ast(const char *symbol, int num, ...)
{
    struct ast *a = (struct ast *)malloc(sizeof(struct ast));
    a->symbol = strdup(symbol);
    a->num_of_children = num;
    a->children = (struct ast **)malloc(a->num_of_children*sizeof(struct ast*));
    va_list ptr;
 
    // Initializing argument to the
    // list pointer
    va_start(ptr, num);
 
    for (int i = 0; i < num; i++)
 
        // Accessing current variable
        // and pointing to next one
        a->children[i] = va_arg(ptr, struct ast *);
 
    // Ending argument list traversal
    va_end(ptr);
 

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