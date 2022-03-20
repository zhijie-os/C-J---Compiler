#include "AST.h"
#include "semantic.h"

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



// Pretty Print the AST
void PrettyPrint(AST *root,  int level)
{
    // print indentation
    for (int i = 0; i < level; i++)
    {
        std::cout << "    ";
    }

    // print the node symbol
    std::cout << root->symbol;


    // if attribute exists
    if (root->attribute)
    {
        // print the line number
        std::cout << " { line: " << root->attribute->line;
        if (!root->attribute->literal.empty())
        {
            // print the literal
            std::cout << ", "
                      << "literal: " << root->attribute->literal;
        }
        if (root->type == NodeType::IDENTIFIER)
        {
            // if it is identifier, print the address of symbol table entry
            std::cout << ", "
                      << "address: ";
                    //   if it is function, print both return type and parameter types
            if(root->f_record)
            {
                std::cout << root->f_record;
                std::cout << " returnType = " << DataToString(root->f_record->returnType);
                std::cout << " paramType = < ";
                for(auto c:root->f_record->paramType)
                {
                    DataToString(c);
                }
                std::cout << " > ";
            }

            // print the type of the identifier
            if(root->id_record)
            {
                std::cout << root->id_record;
                std::cout << " type = " << DataToString(root->id_record->type) ;
            }
        }

        std::cout << " }";
    }

    std::cout << std::endl;

    // recurse
    for(auto c:root->children)
    {
        PrettyPrint(c,level+1);
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