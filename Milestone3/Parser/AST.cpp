#include "AST.h"
#include "STab.h"

ATR::ATR(int l)
{
    line = l;
    literal = "";
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

AST::AST(NodeType t, std::string str, ATR *atr)
{
    type = t;
    attribute = atr;
    symbol = str;
}

AST::AST(NodeType t, std::string str, AST *a)
{
    type = t;

    symbol = str;
    AttachChildren(a);
}

AST::AST(NodeType t, std::string str, AST *a, AST *b)
{
    type = t;

    symbol = str;
    AttachChildren(a, b);
}

AST::AST(NodeType t, std::string str, AST *a, AST *b, AST *c)
{

    type = t;

    symbol = str;
    AttachChildren(a, b, c);
}

AST::AST(NodeType t, std::string str, AST *a, AST *b, AST *c, AST *d)
{

    type = t;

    symbol = str;
    AttachChildren(a, b, c);
    AttachChildren(d);
}

AST::AST(NodeType t, std::string str, ATR *atr, AST *a)
{
    type = t;
    attribute = atr;

    symbol = str;
    AttachChildren(a);
}

AST::AST(NodeType t, std::string str, ATR *atr, AST *a, AST *b)
{

    type = t;
    attribute = atr;

    symbol = str;
    AttachChildren(a, b);
}

AST::AST(NodeType t, std::string str, ATR *atr, AST *a, AST *b, AST *c)
{

    type = t;
    attribute = atr;

    symbol = str;
    AttachChildren(a, b, c);
}

void PrettyPrint(AST *root, std::string scope, int level)
{
    for (int i = 0; i < level; i++)
    {
        std::cout << "    ";
    }
    if (root->type == NodeType::FUNC_DEC || root->type == NodeType::MAIN_DEC)
    {
        scope = root->children[1]->attribute->literal;
    }

    std::cout << root->symbol;

    if (root->attribute)
    {
        std::cout << " { line: " << root->attribute->line;
        if (!root->attribute->literal.empty())
        {
            std::cout << ", "
                      << "literal: " << root->attribute->literal;
        }
        if (root->type == NodeType::IDENTIFIER)
        {
            std::cout << ", "
                      << "address: ";
            if (!scope.empty() && SYMBOL_TABLE.find(scope)->second.find(root->attribute->literal) != SYMBOL_TABLE.find(scope)->second.end())
            {
                std::cout << &SYMBOL_TABLE.find(scope)->second.find(root->attribute->literal)->second;
            }
            else
            {
                if (GLOBAL_FUNC.find(root->attribute->literal) != GLOBAL_FUNC.end())
                {
                    std::cout << &GLOBAL_FUNC.find(root->attribute->literal)->second;
                }
                else
                {
                    std::cout << &GLOBAL_VAR.find(root->attribute->literal)->second;
                }
            }
        }

        std::cout << " }";
    }

    std::cout << std::endl;

    for (auto c : root->children)
    {
        PrettyPrint(c, scope, level + 1);
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
    return children.size() == 0;
}