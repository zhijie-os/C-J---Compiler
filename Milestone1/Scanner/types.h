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
    tk.attr_length = 4;
    tk.line = line_num; 

    tokens[num_tokens] = tk;
    num_tokens++;
}



void print_string(int index)
{
    int length = tokens[index].attr_length;
    char buff[length+1];
    memset(buff,0,length+1);

    int j=0;
    for(int i=0;i<length;i++)
    {
        if(tokens[index].attribute[i]!='\0')
        {
            buff[j]=tokens[index].attribute[i];
            j++;
        }
    }

    printf("Token(string, %d, %s)",tokens[index].line, buff);
}

void print_general(int index)
{
    int length = tokens[index].attr_length;
    char name[20];
    char attr[length+1];
    memset(name,0,20);
    memset(attr,0,length+1);
    strncpy(attr,tokens[index].attribute,length);

    switch(tokens[index].token_name)
    {
        case ID:
            strcpy(name,"id");
            break;
        case NUMBER:
            strcpy(name,"number");
            break;
        case TRUE:
            strcpy(name,"true");
            break;
        case FALSE:
            strcpy(name,"false");
            break;  
        case BOOLEAN:
            strcpy(name,"boolean");
            break;  
        case INT:
            strcpy(name,"int");
            break;  
        case VOID:
            strcpy(name,"void");
            break;  
        case IF:
            strcpy(name,"if");
            break;  
        case ELSE:
            strcpy(name,"else");
            break;  
        case WHILE:
            strcpy(name,"while");
            break;  
        case BREAK:
            strcpy(name,"break");
            break;  
        case RETURN:
            strcpy(name,"return");
            break;  
        case OP_ADD:
            strcpy(name,"+");
            break;  
        case OP_SUB:
            strcpy(name,"-");
            break;  
        case OP_MUL:
            strcpy(name,"*");
            break;  
        case OP_DIV:
            strcpy(name,"/");
            break;  
        case OP_MOD:
            strcpy(name,"%");
            break;  
        case OP_LT:
            strcpy(name,"<");
            break; 
        case OP_GT:
            strcpy(name,">");
            break; 
        case OP_LE:
            strcpy(name,"<=");
            break; 
        case OP_GE:
            strcpy(name,">=");
            break; 
        case OP_EQ:
            strcpy(name,"=");
            break;
        case OP_NE:
            strcpy(name,"!=");
            break; 
        case OP_ASSIGN:
            strcpy(name,"=");
            break; 
        case OP_NOT:
            strcpy(name,"!");
            break; 
        case OP_AND:
            strcpy(name,"&&");
            break; 
        case OP_OR:
            strcpy(name,"||");
            break; 
        case L_PAR:
            strcpy(name,"(");
            break; 
        case R_PAR:
            strcpy(name,")");
            break; 
        case L_BRA:
            strcpy(name,"{");
            break;  
        case R_BRA:
            strcpy(name,"}");
            break; 
        case SMCOL:
            strcpy(name,";");
            break; 
        case COMMA:
            strcpy(name,",");
            break;
    }

    printf("Token(%s, %d, %s)", name ,tokens[index].line, attr);
}

// print every tokens at the end
void print_tokens()
{
    printf("[");
    for(int i=0;i<num_tokens;i++)
    {
        if(tokens[i].token_name == STRING)
            print_string(i);
        else
            print_general(i);
        if(i<num_tokens-1)
            printf(", ");
    }
    printf("]\n");
}


#endif