#pragma once

#include <vector>
#include <string>
#include <stdarg.h>
#include <iostream>
#include <unordered_map>
#include "Type.h"

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

    void AttachChildren(AST *);

    void AttachChildren(AST *, AST *);

    void AttachChildren(AST *, AST *, AST *);

    void StealChildren(AST *);

    void BecomeSibling(AST *);

    void BecomeSibling(AST *, AST *);

    void BecomeSibling(AST *, AST *, AST *);

    bool isLeaf();
};

void PrettyPrint(AST*, std::string, int);