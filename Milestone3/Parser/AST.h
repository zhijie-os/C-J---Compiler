#pragma once 

#include <vector>
#include <string>
#include <stdarg.h>
#include <iostream>


class AST
{
public:
    AST *parent;

    std::string symbol;
    std::vector<AST *> children;

    bool isLeaf;

    AST(std::string, bool);

    AST(std::string, bool,int,...);

    virtual void PrettyPrint(int);

    virtual void AttachChildren(int ,...);

    virtual void StealChildren(AST *);

    virtual void BecomeSibling(int , ...);
};