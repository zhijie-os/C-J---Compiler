#pragma once

#include <vector>
#include <string>
#include <stdarg.h>
#include <iostream>
#include <unordered_map>

enum class NodeType
{
    PROGRAM,
    GLOBAL_VAR_DEC,
    VAR_DEC,
    FUNC_DEC,
    MAIN_DEC,
    FORMALS,
    FORMAL,
    ACTUALS,
    ACTUAL,
    VOID,
    BLOCK,
    NULL_STMT,
    STMT_EXPR,
    IF,
    IF_ELSE,
    TRUE,
    FALSE,
    WHILE,
    FUNC_CALL,
    BIN_ARITHMETIC,
    UN_ARITHMETIC,
    BIN_LOGIC,
    UN_LOGIC,
    ASSIGN,
    INT,
    RETURN,
    BREAK,
    BOOLEAN,
    NUMBER,
    STRING,
    IDENTIFIER,
};

class ATR
{
public:
    int line;
    std::string literal;

    ATR();

    ATR(int);
    ATR(int, std::string);
};

class AST
{
public:
    AST *parent;

    NodeType type;
    std::vector<AST *> children;
    std::string symbol;
    int line;

    ATR *attribute;

    AST(NodeType, std::string);

    AST(NodeType, std::string, ATR *);

    AST(NodeType, std::string, AST *);

    AST(NodeType, std::string, AST *, AST *);

    AST(NodeType, std::string, AST *, AST *, AST *);


    AST(NodeType, std::string, AST *, AST *, AST *, AST *);

    AST(NodeType, std::string, ATR *, AST *);

    AST(NodeType, std::string, ATR *, AST *, AST *);

    AST(NodeType, std::string, ATR *, AST *, AST *, AST *);


    void PrettyPrint(int);

    void AttachChildren(AST *);

    void AttachChildren(AST *, AST *);

    void AttachChildren(AST *, AST *, AST *);

    void StealChildren(AST *);

    void BecomeSibling(AST *);

    void BecomeSibling(AST *, AST *);

    void BecomeSibling(AST *, AST *, AST *);

    bool isLeaf();
};