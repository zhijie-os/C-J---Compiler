#include "scanner.h";

// scanner counters an error, ignore if the total number of errors is acceptable; otherwise, abort;
void error_general()
{
    fprintf(stderr,"warning: ignoring bad character at or near line %d \n",line_num);
    num_error ++;
    if(num_error>=10)
    {
        printf("Too many errors, abort....\n");
        exit(EXIT_FAILURE);
    }
}

// scanner counters an error in string which is unrecoverable, abort.
void error_string(const char* info)
{
    fprintf(stderr,"error: %s at or near line %d\n", info,line_num);
    exit(EXIT_FAILURE);
}


// scanner scans a non-string token
void scan_general(enum TOKEN_NAME tok_n)
{
    // construct token with global variables
    struct TOKEN tk;
    tk.token_name = tok_n;
    tk.attribute = (char*)malloc(yyleng);
    memmove(tk.attribute,yytext,yyleng);
    tk.attr_length = yyleng; 
    tk.line = line_num; 

}


void scan_reserved(enum TOKEN_NAME tok_n)
{
    // construct token with global variables
    struct TOKEN tk;
    tk.token_name = tok_n;
    tk.attribute = "None"; 
    tk.attr_length = 4;
    tk.line = line_num; 
}

