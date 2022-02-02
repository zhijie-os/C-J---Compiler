/********************************
 * Example C Lexical Analyzer
 * Written for CPSC 411 Tutorial
 * File: scanner.c
 * Shankar Ganesh
 * *****************************/

#include "scanner.h"
#include <stdlib.h>
#include <errno.h>

char const* getName(int tok);

int main(int argc, char **argv) {

    if (argc == 2) {
        yyin = fopen(argv[1], "r");

        if (!yyin) {
            fprintf(stderr, "\033[1m\033[31mfatal error: \x1B[0mFailed to open file %s\n", argv[1]);
            perror("Error: ");
            return EXIT_FAILURE;
        }
    }
	// Start lexer!
    int tok;

	// Get tokens till EOF
    while ((tok = yylex()) != 0) {
        fprintf(stdout, "line: %d token %s; Lexeme: %s\n", yylineno, getName(tok), yytext);
    }

    return EXIT_SUCCESS;
}

char const* getName(int tok){
	switch (tok)
    {
	case T_ID:
		return "ID";
		
    case T_BEGIN:
        return "BEGIN";
    
    case T_END:
        return "END";

    case T_NUM:
        return "NUM";

    case T_ADD:
        return "+";

    case T_SUB:
        return "-";

    case T_DIV:
        return "/";

    case T_MULT:
        return "*";

    case T_LT:
        return "<";

    case T_GT:
        return ">";

    case T_LE:
        return "<=";
    
    case T_GE:
        return ">=";

    default:
        return "";
    }
}


