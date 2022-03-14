#pragma once 

#include <vector>
#include <string>
#include <stdarg.h>
#include <iostream>


enum class NodeType  
{
    PROGRAM,GLOBAL_VAR_DEC,VAR_DEC,FUNC_DEC,MAIN_DEC,FORMALS,
    FORMAL,VOID,BLOCK,NULL_STMT,STMT_EXPR,IF,IF_ELSE,TRUE, FALSE,
    WHILE,FUNC_CALL,BIN_ARITHEMTIC, UN_ARITHMETIC, BIN_LOGIC, UN_LOGIC,
    ASSIGN,INT,RETURN,BREAK,BOOLEAN,
    NUMBER,STRING,IDENTIFIER,
};




class AST
{
public:
    AST *parent;

    NodeType type;
    std::vector<AST *> children;
    std::string symbol;
    int line;

    AST(NodeType,std::string, int);

    AST(NodeType,std::string, int, int,...);

    void PrettyPrint(int);

    void AttachChildren(int ,...);

    void StealChildren(AST *);

    void BecomeSibling(int , ...);

    bool isTerminal();

};