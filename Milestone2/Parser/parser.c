#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "parser.h"




void yyerror(char const *s)
{
    fprintf(stderr, "ERROR: %s, probably at or near \"%s\" on line %d\n", s,  yylval->symbol, yylval->line_num);
}


struct ast *new_ast(const char *symbol, int num_of_children, ...)
{
    struct ast *a = (struct ast *)malloc(sizeof(struct ast));

    a->symbol = strdup(symbol);
    a->num_of_children = num_of_children;



    a->children = (struct ast **)malloc(a->num_of_children*sizeof(struct ast*));
    va_list ptr;
    va_start(ptr, num_of_children);

    for(int i=0;i<a->num_of_children;i++)
    {
        a->children[i]=va_arg(ptr, struct ast*);
    }
    va_end(ptr);

    return a;
};


struct ast *atomic_ast(const char *symbol,int line_num, const char *atr)
{
    struct ast *a = (struct ast *)malloc(sizeof(struct ast));
    a->symbol = strdup(symbol);
    a->num_of_children = 0;
    a->line_num = line_num;
    a->attribute = strdup(atr);

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
        printf(" { lineno: %d, attribute: '%s'}", root->line_num, root->attribute);
    }
    
    printf("\n");
    
    for (int i = 0; i < root->num_of_children;i++)
    {   

        print_tree(root->children[i], level + 1);
    }
}



// scanner counters an error in string which is unrecoverable, abort.
void lexer_string_error(const char* info)
{
    fprintf(stderr,"error: %s at or near line %d\n", info,yylineno);
    exit(EXIT_FAILURE);
}



// scanner counters an error, ignore if the total number of errors is acceptable; otherwise, abort;
void lexer_general_error()
{
    fprintf(stderr,"warning: ignoring bad character at or near line %d \n",yylineno);
    num_lexer_error ++;
    if(num_lexer_error>=10)
    {
        printf("Too many errors, abort....\n");
        exit(EXIT_FAILURE);
    }
}




int main(int argc, char *argv[])
{
    if(argc==2)
    {
        yyin = fopen(argv[1],"r");
        if(yyin==NULL)
        {
            fprintf(stderr, "Faile to open %s\n",argv[1]);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        perror("Usage:./parser <file path>\n");
        exit(EXIT_FAILURE);
    }

    return yyparse();
}
