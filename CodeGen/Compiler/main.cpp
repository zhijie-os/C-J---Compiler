#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "parser.h"
#include "semantic.h"
#include "codeGen.h"


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

    // parsing
    yyparse();

    // yet another semantic analysis
    yysemantic(root);

    // yet another code generator
    yycodegen(root);

}
