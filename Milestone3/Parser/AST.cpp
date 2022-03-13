#include "AST.h"
#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<NonTerminal,std::string> NonTerminalLiteral
{
    {NonTerminal::NT_ADD, "+"}, {NonTerminal::NT_SUB, "-"}, 
    {NonTerminal::NT_MUL, "*"}, {NonTerminal::NT_DIV, "/"}, 
    {NonTerminal::NT_MOD, "%"}, {NonTerminal::NT_MINUS, "-"},
    {NonTerminal::NT_AND, "&&"}, {NonTerminal::NT_OR, "||"},
    {NonTerminal::NT_NOT, "!"}, {NonTerminal::NT_LT, "<"},
    {NonTerminal::NT_GT, ">"},  {NonTerminal::NT_LE, "<="},
    {NonTerminal::NT_GE, ">="}, {NonTerminal::NT_EQ, "=="},
    {NonTerminal::NT_NE, "!="}, {NonTerminal::NT_ASSIGN, "="},
};



Node::Node(NonTerminal nt, std::initializer_list<AST *> cs)
{
    this->non_terminal = nt;

    for(auto c:cs)
    {
        this->children.push_back(c);
        c->parent = this;
    }
}

Node::~Node()
{
    for(auto c: this->children)
    {
        delete c;
    }
}

void Node::PrettyPrint(int level)
{
    // indentation
    for(int i=0;i<level;i++)
    {
        std::cout<<"    ";
    }

};

Leaf::Leaf(Terminal t, Record *ptr){};

Leaf::~Leaf(){};
