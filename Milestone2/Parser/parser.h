#ifndef PARSER_H
#define PARSER_H

#include <stdlib.h>

enum TOKEN_TYPE
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

struct ast
{
    int num_of_children;
    struct ast *children;
};



struct ast *newast(TOKEN_TYPE type, struct ast *c1);

struct ast *newast(TOKEN_TYPE type, struct ast *c1, struct ast *c2);

struct ast *newast(TOKEN_TYPE type, struct ast *c1, struct ast *c2, struct ast *c3);

struct ast *newast(TOKEN_TYPE type, struct ast *c1, struct ast *c2, struct ast *c3, struct ast *c4);

#endif