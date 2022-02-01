/**
 * @author Zhijie Xia
 * @date 2022-01-29, Winter 2022
 * @brief scanner for J--
*/


#ifndef SCANNER_H
#define SCANNER_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

extern int num_error;
extern int line_num;

// number of tokens in the array
extern int num_tokens;
// the size of the array which contains every token
extern int array_size;


// enum class for differentiating different token types
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


// Token struct, looks like <token name, attribute, line number> 
struct TOKEN{
    enum TOKEN_NAME token_name;
    char *attribute;
    int attr_length;
    int line;
};

// store all the tokens
extern struct TOKEN *tokens;


// double the array size 
void array_doubling()
{
    // double the size of the array
    array_size *= 2;
    tokens = (struct TOKEN *)realloc(tokens, array_size*sizeof(struct TOKEN));
}

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
void error_string()
{
    fprintf(stderr,"error: string missing closing quote at or near line %d\n",line_num);
    exit(EXIT_FAILURE);
}


// scanner scans a non-string token
void scan_general(enum TOKEN_NAME tok_n)
{
    // check if the array size is big enough to append 
    if(num_tokens >= array_size)
    {
        // if not, double the array size
        array_doubling();
    }


    // construct token with global variables
    struct TOKEN tk;
    tk.token_name = tok_n;
    tk.attribute = (char*)malloc(yyleng);
    strncpy(tk.attribute,yytext,yyleng);
    tk.attr_length = yyleng; 
    tk.line = line_num; 

    // add the token into the array
    tokens[num_tokens] = tk;

    // increase array size
    num_tokens++;
}


void scan_reserved(enum TOKEN_NAME tok_n)
{

    // check if the array size is big enough to append 
    if(num_tokens >= array_size)
    {
        // if not, double the array size
        array_doubling();
    }


    // construct token with global variables
    struct TOKEN tk;
    tk.token_name = tok_n;
    tk.attribute = "None"; 
    tk.attr_length = 4;
    tk.line = line_num; 


    // add the token into the array
    tokens[num_tokens] = tk;

    // increase array size
    num_tokens++;
}


// print string token on stdout (handles \0)
void print_string(int index)
{
    // create buff for printable string
    int length = tokens[index].attr_length;
    char buff[length+1];
    memset(buff,0,length+1);

    int j=0;
    for(int i=0;i<length;i++)
    {
        // if char is not null, append into buff
        if(tokens[index].attribute[i]!='\0')
        {
            buff[j]=tokens[index].attribute[i];
            j++;
        }
    }

    // print printable string
    printf("Token(string, %d, %s)",tokens[index].line, buff);
}

void print_general(int index)
{
    // name holds the token's "token name", attr holds the token's "attribute"
    int length = tokens[index].attr_length;
    char name[20];
    char attr[length+1];
    memset(name,0,20);
    memset(attr,0,length+1);
    strncpy(attr,tokens[index].attribute,length);

    // find the right token_name
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


void free_attributes()
{
     for(int i=0;i<num_tokens;i++)
    {
        free(tokens[i].attribute);
    }
}


#endif