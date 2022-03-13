#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "parser.h"


// define yyerror for bison
void yyerror(char const *s)
{
    // print out the token that cannot be shifted or reduced and its line number
    fprintf(stderr, "ERROR: %s, probably at or near \"%s\" on line %d\n", s, yylval->symbol, yylval->line_num);
}

// create a new AST node with a single string as the symbol and variable length of childrens
struct ast *new_ast(const char *symbol, int num_of_children, ...)
{
    // allocate memory
    struct ast *a = (struct ast *)malloc(sizeof(struct ast));

    // copy symbol and number of children
    a->symbol = strdup(symbol);
    a->num_of_children = num_of_children;

    // create a list of ast node pointers
    a->children = (struct ast **)malloc(a->num_of_children * sizeof(struct ast *));

    // copy every children into the children list of a
    va_list ptr;
    va_start(ptr, num_of_children);

    for (int i = 0; i < a->num_of_children; i++)
    {
        a->children[i] = va_arg(ptr, struct ast *);
    }
    va_end(ptr);


    // return a, the newly created ast node
    return a;
};

// create AST leaf node 
struct ast *atomic_ast(const char *symbol, int line_num, const char *atr)
{
    // allocate memory
    struct ast *a = (struct ast *)malloc(sizeof(struct ast));
    a->symbol = strdup(symbol);

    // this is usually terminal symbol, so it is leaf and it has attribute but no children.
    a->num_of_children = 0;
    a->line_num = line_num;
    a->attribute = strdup(atr);
    return a;
}

// For a list of AST node L and a single AST node A, insert every B from L into A's children list.
struct ast *attach_new_children(struct ast *parent, int num_new_children, ...)
{
    // reallocate memory
    parent->children = (struct ast **)realloc(parent->children, (parent->num_of_children + num_new_children) * sizeof(struct ast *));


    // insert individual nodes
    va_list ptr;
    va_start(ptr, num_new_children);

    for (int i = 0; i < num_new_children; i++)
    {
        parent->children[i + parent->num_of_children] = va_arg(ptr, struct ast *);
    }
    va_end(ptr);

    // increase the number of children
    parent->num_of_children += num_new_children;
    return parent;
}


// For AST nodes A and B, copy every child of B into A's children list.
struct ast *steal_children(struct ast *a, struct ast *b)
{
    a->children = (struct ast **)realloc(a->children, (a->num_of_children + b->num_of_children) * sizeof(struct ast *));


    for (int i = 0; i < b->num_of_children; i++)
    {
        a->children[i + a->num_of_children] = b->children[i];
    }

    a->num_of_children += b->num_of_children;
    return a;
}



// This is the base case of folder ast, it is functional sytled. Craetes a dummy parent to the AST node B.
struct ast* fold_ast_base(struct ast *b)
{
    struct ast *a = (struct ast *)malloc(sizeof(struct ast));
    a->symbol = strdup("list");
    a->num_of_children = 1;
    a->children = (struct ast **)malloc(sizeof(struct ast *));
    a->children[0] = b;
    return a;
}


// Flatten the AST tree, so that a single parent has all the descandants
struct ast* fold_ast(struct ast *a, struct ast* b)
{
    a->num_of_children += 1;
    a->children = (struct ast **)realloc(a->children, a->num_of_children * sizeof(struct ast *));
    a->children[a->num_of_children-1] = b;
    return a;
}

// rename an AST node, i.e, change the node's symbol
struct ast *rename_ast(const char *symbol, struct ast *a)
{
    a->symbol = strdup(symbol);
    return a;
}

// recursive print out the AST, indent by the int "level".
void print_tree(struct ast *root, int level)
{
    // indentation
    for (int i = 0; i < level; i++)
    {
        printf("    ");
    }

    // print out the symbol of the node
    printf("%s", root->symbol);


    // print out attribute it is not none
    if (root->attribute)
    {
        printf(" { lineno: %d", root->line_num);

        if (strcmp(root->attribute, "None") != 0)
        {
            printf(", attribute: \"%s\"", root->attribute);
        }

        printf(" }");
    }

    printf("\n");

    // recursively print children
    for (int i = 0; i < root->num_of_children; i++)
    {
        print_tree(root->children[i], level + 1);
    }
}

// scanner counters an error in string which is unrecoverable, abort.
void lexer_string_error(const char *info)
{
    fprintf(stderr, "error: %s at or near line %d\n", info, yylineno);
    exit(EXIT_FAILURE);
}

// scanner counters an error, ignore if the total number of errors is acceptable; otherwise, abort;
void lexer_general_error()
{
    fprintf(stderr, "warning: ignoring bad character at or near line %d \n", yylineno);
    num_lexer_error++;
    if (num_lexer_error >= 10)
    {
        printf("Too many errors, abort....\n");
        exit(EXIT_FAILURE);
    }
}
