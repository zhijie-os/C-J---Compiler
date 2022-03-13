#pragma once
#include <vector>
#include <initializer_list>


enum class NonTerminal{NT_ADD, NT_SUB, 
    NT_MUL, NT_DIV, NT_MOD, NT_MINUS, NT_AND, NT_OR, NT_NOT,
    NT_LT, NT_GT, NT_LE, NT_GE, NT_EQ, NT_NE, NT_ASSIGN};

enum class Terminal{T_ID, T_STRING, T_NUMBER};

class AST
{
public:
    AST *parent;
    std::vector<AST*> children;
};

class Record
{

};

class Node : public AST 
{
public:
    NonTerminal non_terminal;

    Node(NonTerminal,std::initializer_list<AST*>);

    ~Node();

    virtual void PrettyPrint(int)=0;
};


class Leaf : public AST 
{
public:
    Terminal terminal;
    Record* stab;
    Leaf(Terminal, Record *);

    ~Leaf();
};

