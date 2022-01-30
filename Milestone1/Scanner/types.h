#ifndef TYPES_H
#define TYPES_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

extern int num_error;
extern int line_num;
extern int num_tokens;
extern int array_size;

enum TOKEN_NAME
{
    ID = 1,
    STRING,
    NUMBER,
    TRUE,
    FALSE,
    BOOLEAN,
    INT,
    VOID,
    IF,
    ELSE,
    WHILE,
    BREAK,
    RETURN,
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_MOD,
    OP_LT,
    OP_GT,
    OP_LE,
    OP_GE,
    OP_EQ,
    OP_NE,
    OP_ASSIGN,
    OP_NOT,
    OP_AND,
    OP_OR,
    L_PAR,
    R_PAR,
    L_BRA,
    R_BRA,
    SMCOL,
    COMMA,
};


struct TOKEN{
    enum TOKEN_NAME token_name;
    char *attribute;
    int attr_length;
    int line;
};

// store all the tokens
extern struct TOKEN *tokens;


void array_doubling()
{
    // double the size of the array
    array_size *= 2;
    tokens = (struct TOKEN *)realloc(tokens, array_size*sizeof(struct TOKEN));
}

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

void error_string()
{
    fprintf(stderr,"error: string missing closing quote at or near line %d\n",line_num);
    exit(EXIT_FAILURE);
}

void scan_general(enum TOKEN_NAME tok_n)
{
    if(num_tokens >= array_size)
    {
        array_doubling();
    }

    struct TOKEN tk;
    tk.token_name = tok_n;
    tk.attribute = yytext;
    tk.attr_length = yyleng; 
    tk.line = line_num; 

    tokens[num_tokens] = tk;
    num_tokens++;
}


void scan_reserved(enum TOKEN_NAME tok_n)
{
    if(num_tokens >= array_size)
    {
        array_doubling();
    }

    struct TOKEN tk;
    tk.token_name = tok_n;
    tk.attribute = "None"; 
    tk.attr_length = 0;
    tk.line = line_num; 

    tokens[num_tokens] = tk;
    num_tokens++;
}

void print_tokens()
{
    for(int i=0;i<num_tokens;i++)
    {
        printf("%d\n",tokens[i].token_name);
    }
}


#endif