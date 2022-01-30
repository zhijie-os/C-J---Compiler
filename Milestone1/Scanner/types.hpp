#ifndef TYPES_H
#define TYPES_H


#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>



extern int num_error;
extern int line_num;

extern FlexLexer* lexer;

enum Token_Type{
    ID=1,
    STRING,
    NUMBER, TRUE, FALSE, BOOLEAN, INT, VOID,
    IF, ELSE, WHILE, BREAK, RETURN,
    OP_ADD, OP_SUB, OP_MUL, OP_DIV, OP_MOD,
    OP_LT, OP_GT, OP_LE, OP_GE, OP_EQ, OP_NE,
    OP_ASSIGN,
    OP_NOT, OP_AND, OP_OR,
    L_PAR, R_PAR, L_BRA, R_BRA,
    SMCOL, COMMA,
};



class Token{
public:
    Token_Type token_name;
    std::string attribute;
    int line;

    Token(Token_Type tok, const char* attr, int num)
    {
        token_name = tok;
        attribute = attr;
        line = num;
    }

    Token(Token_Type tok, int num)
    {
      token_name = tok;
      attribute = "None";
      line = num;
    }

    ~Token() = default;

    std::string to_string()
    {
      std::stringstream result;
      std::string tok_name;

      switch(token_name)
      {
        case ID:
          tok_name="id";
          break;
        case STRING:
          tok_name="string";
          break;
        case NUMBER:
          tok_name="number";
          break;
        case TRUE:
          tok_name="true";
          break;
        case FALSE:
          tok_name="false";
          break;
        case BOOLEAN:
          tok_name="boolean";
          break;
        case INT:
          tok_name="int";
          break;
        case VOID:
          tok_name="void";
          break;
        case IF:
          tok_name="if";
          break;
        case ELSE:
          tok_name="else";
          break;
        case WHILE:
          tok_name="while";
          break;
        case BREAK:
          tok_name="break";
          break;
        case RETURN:
          tok_name="return";
          break;
        case OP_ADD:
          tok_name="+";
          break;
        case OP_SUB:
          tok_name="-";
          break;
        case OP_MUL:
          tok_name="*";
          break;
        case OP_DIV:
          tok_name="/";
          break;
        case OP_MOD:
          tok_name="%";
          break;
        case OP_LT:
          tok_name="<";
          break;
        case OP_GT:
          tok_name=">";
          break;
        case OP_LE:
          tok_name="<=";
          break;
        case OP_GE:
          tok_name=">=";
          break;
        case OP_EQ:
          tok_name="==";
          break;
        case OP_NE:
          tok_name="!=";
          break;
        case OP_ASSIGN:
          tok_name="=";
          break;
        case OP_NOT:
          tok_name="!";
          break;
        case OP_AND:
          tok_name="&&";
          break;
        case OP_OR:
          tok_name="||";
          break;
        case L_PAR:
          tok_name="(";
          break;
        case R_PAR:
          tok_name=")";
          break;
        case L_BRA:
          tok_name="{";
          break;
        case R_BRA:
          tok_name="}";
          break;
        case SMCOL:
          tok_name=";";
          break;
        case COMMA:
          tok_name=",";
          break;
      }

      result << "Token(" << tok_name << ", " << std::to_string(line) << ", " << attribute << ")";

      return result.str();
    }
};



extern std::vector<Token> tokens_vector;



void error()
{
    std::cerr << "warning: ignoring bad character at or near line " << line_num << std::endl;
    num_error++;
    if(num_error>=10)
    {
        std::cerr << "Too many errors... Abort..." << std::endl;
        exit(EXIT_FAILURE);
    }
}

void string_error()
{
    std::cerr << "error: string missing closing quote at or near line " << line_num << std::endl;
    exit(EXIT_FAILURE);
}


void scan_general(Token_Type type)
{
    tokens.push_back(Token(type,lexer->YYText(),line_num));
}

void scan_reserved(Token_Type type)
{
    tokens.push_back(Token(type,line_num));
}



#endif
