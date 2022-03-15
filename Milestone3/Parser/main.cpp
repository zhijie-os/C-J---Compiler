#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "parser.h"
#include "STab.h"

// create a new AST node with a single string as the symbol and variable length of childrens


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

int main(int argc, char *argv[])
{

    // check if the number of argument is 2
    if (argc == 2)
    {
        // read file as input stream
        yyin = fopen(argv[1], "r");
        if (yyin == NULL)
        {
            // fail to open the file, it may not exist
            fprintf(stderr, "Failed to open %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        // unmatched number of arguments
        perror("Usage:./parser <file path>\n");
        exit(EXIT_FAILURE);
    }

    //yydebug = 1;

    // parsing
    return yyparse();
}
