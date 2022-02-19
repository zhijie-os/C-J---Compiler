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

// scanner counters an error, ignore if the total number of errors is acceptable; otherwise, abort;
void error_general();

// scanner counters an error in string which is unrecoverable, abort.
void error_string(const char* info);

// scanner scans a non-string token
void scan_general(enum TOKEN_NAME tok_n);

void scan_reserved(enum TOKEN_NAME tok_n);


#endif