#include "AST.h"


ATR::ATR(int l)
{
    line = l;
    literal = "None";
}

ATR::ATR(int l, std::string s)
{
    line = l;
    literal = s;
}

AST::AST(NodeType t, std::string str)
{
    type = t;
    symbol = str;
}

AST::AST(NodeType t,std::string str, ATR* atr)
{
    type = t;
    attribute = atr;
    symbol = str;
}

AST::AST(NodeType t,std::string str, AST *a)
{
    type = t;

    symbol = str;
    AttachChildren(a);
}

AST::AST(NodeType t,std::string str, AST *a, AST *b)
{
    type = t ;

    symbol = str;
    AttachChildren(a,b);
}

AST::AST(NodeType t,std::string str, AST *a, AST *b, AST *c)
{

    type = t ;

    symbol = str;
    AttachChildren(a,b,c);
}


AST::AST(NodeType t,std::string str, AST *a, AST *b, AST *c, AST*d)
{

    type = t ;

    symbol = str;
    AttachChildren(a,b,c);
    AttachChildren(d);
}

AST::AST(NodeType t,std::string str, ATR* atr, AST *a)
{
    type = t;
    attribute = atr;

    symbol = str;
    AttachChildren(a);
}

AST::AST(NodeType t,std::string str, ATR* atr, AST *a, AST *b)
{

    type = t;
    attribute = atr;

    symbol = str;
    AttachChildren(a,b);
}

AST::AST(NodeType t,std::string str, ATR* atr, AST *a, AST *b, AST *c)
{

    type = t;
    attribute = atr;

    symbol = str;
    AttachChildren(a,b,c);
}

void AST::PrettyPrint(int level)
{
    for(int i=0;i<level;i++)
    {
        std::cout << "    ";
    }

    std::cout << symbol;

    if(attribute)
    {
        std::cout << "{ line: " << attribute->line <<" ," <<"literal: " << attribute->literal << " }";
    }

    std::cout << std::endl;

    for(auto c:children)
    {
        c->PrettyPrint(level+1);
    }
}

void AST::AttachChildren(AST *a)
{
    children.push_back(a);
    a->parent = this;
}

void AST::AttachChildren(AST *a, AST *b)
{
    AttachChildren(a);
    AttachChildren(b);
}

void AST::AttachChildren(AST *a, AST *b, AST *c)
{

    AttachChildren(a, b);
    AttachChildren(c);
}

void AST::StealChildren(AST *a)
{
    for (auto c : a->children)
    {
        children.push_back(c);
        c->parent = this->parent;
    }
}

void AST::BecomeSibling(AST *a)
{
    this->parent->AttachChildren(a);
}

void AST::BecomeSibling(AST *a, AST *b)
{

    this->parent->AttachChildren(a, b);
}

void AST::BecomeSibling(AST *a, AST *b, AST *c)
{

    this->parent->AttachChildren(a, b, c);
}

bool AST::isLeaf()
{
    return children.size()==0;
}