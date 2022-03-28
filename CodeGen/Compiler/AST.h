#pragma once

#include <vector>
#include <string>
#include <stdarg.h>
#include <iostream>
#include <unordered_map>
#include "Type.h"


struct FuncRecord;
struct IdentifierRecord;

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

    FuncRecord* f_record=nullptr;
    IdentifierRecord* id_record=nullptr;

    ATR *attribute=nullptr;
    std::string break_label;

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



struct FuncRecord
{
    DataType returnType;
    std::vector<DataType> paramType;
    AST* node;
};


// record in the symbol table to store the information about an identifier
struct IdentifierRecord
{
    DataType type;
    AST *node;
    bool global;
    int stackPosition;
};


void PrettyPrint(AST *root,  int level);


extern AST* root;