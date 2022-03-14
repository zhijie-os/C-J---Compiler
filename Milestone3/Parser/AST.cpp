#include "AST.h"



AST::AST(std::string s, bool t)
{
    symbol = s;
    isLeaf = t;
}

AST::AST(std::string s, bool t,int num_of_children,...)
{
    AST(s,t);

    va_list ptr;
    va_start(ptr, num_of_children);

    for (int i = 0; i < num_of_children; i++)
    {
        children.push_back(va_arg(ptr, AST*));
    }
    va_end(ptr);
}

void AST::AttachChildren(int num_of_children,...)
{
    va_list ptr;
    va_start(ptr, num_of_children);

    for (int i = 0; i < num_of_children; i++)
    {
        children.push_back(va_arg(ptr, AST*));
    }
    va_end(ptr);
}


void AST::StealChildren(AST *b)
{
    for(auto c: b->children)
    {
        children.push_back(c);
        c->parent = parent;
    }
}

void AST::BecomeSibling(int num, ...)
{
    va_list ptr;
    va_start(ptr, num);

    for (int i = 0; i < num; i++)
    {
        AST*b = va_arg(ptr, AST*);
        b->parent = parent;
        children.push_back(b);
    }
    va_end(ptr);
}


void AST::PrettyPrint(int level)
{
    for(int i=0;i<level;i++)
    {
        std::cout << "    ";
    }

    std::cout << symbol <<std::endl;
}