%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "parser.h"
%}


%union
{
    struct  ast *node;   
    struct  info *attribute; 
}

%token  <node> NUMBER STRING TRUE FALSE BOOLEAN INT ID VOID BREAK RETURN IF ELSE WHILE LE GE NE EQ AND OR
%type   <node> start literal type globaldeclarations globaldeclaration variabledeclaration identifier
%type   <node> functiondeclaration  functionheader functiondeclarator formalparameterlist formalparameter
%type   <node> mainfunctiondeclaration mainfunctiondeclarator block blockstatements blockstatement
%type   <node> statement statementexpression primary argumentlist functioninvocation postfixexpression unaryexpression
%type   <node> multiplicativeexpression additiveexpression relationalexpression equalityexpression
%type   <node> conditionalandexpression conditionalorexpression assignmentexpression assignment expression


%%

dummy_start     : start                 {print_tree($1,0);}

start           : /* empty */
                | globaldeclarations    {$$=new_nonterminal("start",1,$1);}
                ;

literal         : NUMBER                {$$=new_nonterminal("literal",1,new_terminal("NUMBER",yylval.attribute));}
                | STRING                {$$=new_nonterminal("literal",1,new_terminal("STRING",yylval.attribute));}
                | TRUE                  {$$=new_nonterminal("literal",1,new_reserved("TRUE"));}
                | FALSE                 {$$=new_nonterminal("literal",1,new_reserved("FALSE"));}
                ;       

type            : BOOLEAN               {$$=new_nonterminal("literal",1,new_reserved("BOOLEAN"));}
                | INT                   {$$=new_nonterminal("literal",1,new_reserved("INT"));}
                ;

globaldeclarations      : globaldeclaration                             {$$=new_nonterminal("globaldeclarations",1,$1);}
                        | globaldeclarations globaldeclaration          {$$=new_nonterminal("globaldeclarations", 2, $1, $2);}
                        ;

globaldeclaration       : variabledeclaration                           {$$=new_nonterminal("globaldeclaration",1,$1);}
                        | functiondeclaration                           {$$=new_nonterminal("globaldeclaration",1,$1);}
                        | mainfunctiondeclaration                       {$$=new_nonterminal("globaldeclaration",1,$1);}
                        ;

variabledeclaration     : type identifier ';'                           {$$=new_nonterminal("globaldeclaration",3,$1,$2, new_reserved(";"));}
                        ;

identifier              : ID                                            {$$=new_nonterminal("identifier",1,new_terminal("ID",yylval.attribute));}
                        ;

functiondeclaration     : functionheader block                          {$$=new_nonterminal("functiondeclaration",2,$1,$2);}
                        ;

functionheader          : type functiondeclarator                       {$$=new_nonterminal("functionheader", 2, $1, $2);}
                        | VOID functiondeclarator                       {$$=new_nonterminal("functionheader", 2, new_reserved("VOID"), $2);}
                        ;

functiondeclarator      : identifier '(' formalparameterlist ')'        {$$=new_nonterminal("functiondeclarator", 4, $1, new_reserved("("), $3, new_reserved(")"));}
                        | identifier '(' ')'                            {$$=new_nonterminal("functiondeclarator", 3, $1, new_reserved("("), new_reserved(")"));}
                        ;

formalparameterlist     : formalparameter                               {$$=new_nonterminal("formalparameterlist", 1, $1);}
                        | formalparameterlist ',' formalparameter       {$$=new_nonterminal("formalparameterlist", 3, $1, new_reserved(","),$3);}
                        ;

formalparameter         : type identifier                               {$$=new_nonterminal("formalparameter", 2, $1, $2);}
                        ;

mainfunctiondeclaration : mainfunctiondeclarator block                  {$$=new_nonterminal("mainfunctiondeclaration", 2, $1, $2);}
                        ;

mainfunctiondeclarator  : identifier '(' ')'                            {$$=new_nonterminal("mainfunctiondeclarator", 3, $1, new_reserved("("), new_reserved(")"));}
                        ;

block                   : '{' blockstatements '}'                       {$$=new_nonterminal("block", 3, new_reserved("{"), $2, new_reserved("}"));}
                        | '{' '}'                                       {$$=new_nonterminal("block", 2, new_reserved("{"), new_reserved("}"));}
                        ;

blockstatements         : blockstatement                                {$$=new_nonterminal("blockstatements", 1, $1);}
                        | blockstatements blockstatement                {$$=new_nonterminal("blockstatements", 2, $1, $2);}
                        ;

blockstatement          : variabledeclaration                           {$$=new_nonterminal("blockstatement", 1, $1);}
                        | statement                                     {$$=new_nonterminal("blockstatement", 1, $1);}
                        ;

statement               : block                                             {$$=new_nonterminal("statement", 1, $1);}
                        | ';'                                               {$$=new_nonterminal("statement", 1, new_reserved(";"));}
                        | statementexpression ';'                           {$$=new_nonterminal("statement", 2, $1, new_reserved(";"));}
                        | BREAK ';'                                         {$$=new_nonterminal("statement", 2, new_reserved("BREAK"), new_reserved(";"));}
                        | RETURN expression ';'                             {$$=new_nonterminal("statement", 3, new_reserved("RETURN"), $2, new_reserved(";"));}
                        | RETURN ';'                                        {$$=new_nonterminal("statement", 2, new_reserved("RETURN"), new_reserved(";"));}
                        | IF '(' expression ')' statement                   {$$=new_nonterminal("statement", 5, new_reserved("IF"), new_reserved("("), $3, new_reserved(")"), $5);}
                        | IF '(' expression ')' statement ELSE statement    {$$=new_nonterminal("statement", 7, new_reserved("IF"), new_reserved("("), $3, new_reserved(")"), $5, new_reserved("ELSE"), $7);}
                        | WHILE '(' expression ')' statement                {$$=new_nonterminal("statement", 5, new_reserved("WHILE"), new_reserved("("), $3, new_reserved(")"), $5);}
                        ;

statementexpression     : assignment                                        {$$=new_nonterminal("statementexpression", 1, $1);}
                        | functioninvocation                                {$$=new_nonterminal("statementexpression", 1, $1);}
                        ;

primary                 : literal                                           {$$=new_nonterminal("primary", 1, $1);}
                        | '(' expression ')'                                {$$=new_nonterminal("primary", 3, new_reserved("("), $2, new_reserved(")"));}
                        | functioninvocation                                {$$=new_nonterminal("primary", 1, $1);}
                        ;

argumentlist            : expression                                        {$$=new_nonterminal("argumentlist", 1, $1);}
                        | argumentlist ',' expression                       {$$=new_nonterminal("argumentlist", 3, $1, new_reserved(","), $3);}
                        ;

functioninvocation      : identifier '(' argumentlist ')'                   {$$=new_nonterminal("functioninvocation", 4, $1, new_reserved("("), $3, new_reserved(")"));}
                        | identifier '(' ')'                                {$$=new_nonterminal("functioninvocation", 3, $1, new_reserved("("), new_reserved(")"));}
                        ;

postfixexpression       : primary                                           {$$=new_nonterminal("postfixexpression", 1, $1);}
                        | identifier                                        {$$=new_nonterminal("postfixexpression", 1, $1);}
                        ;

unaryexpression         : '-' unaryexpression                               {$$=new_nonterminal("unaryexpression", 2, new_reserved("-"), $2);}
                        | '!' unaryexpression                               {$$=new_nonterminal("unaryexpression", 2, new_reserved("!"), $2);}
                        | postfixexpression                                 {$$=new_nonterminal("unaryexpression", 1, $1);}
                        ;

multiplicativeexpression: unaryexpression                                   {$$=new_nonterminal("multiplicativeexpression", 1, $1);}
                        | multiplicativeexpression '*' unaryexpression      {$$=new_nonterminal("multiplicativeexpression", 3, $1, new_reserved("*"), $3);}
                        | multiplicativeexpression '/' unaryexpression      {$$=new_nonterminal("multiplicativeexpression", 3, $1, new_reserved("/"), $3);}
                        | multiplicativeexpression '%' unaryexpression      {$$=new_nonterminal("multiplicativeexpression", 3, $1, new_reserved("%"), $3);}
                        ;

additiveexpression      : multiplicativeexpression                          {$$=new_nonterminal("additiveexpression", 1, $1);}
                        | additiveexpression '+' multiplicativeexpression   {$$=new_nonterminal("additiveexpression", 3, $1, new_reserved("+"), $3);}
                        | additiveexpression '-' multiplicativeexpression   {$$=new_nonterminal("additiveexpression", 3, $1, new_reserved("-"), $3);}
                        ;

relationalexpression    : additiveexpression                                {$$=new_nonterminal("relationalexpression", 1, $1);}
                        | relationalexpression '<' additiveexpression       {$$=new_nonterminal("relationalexpression", 3, $1, new_reserved("<"), $3);}
                        | relationalexpression '>' additiveexpression       {$$=new_nonterminal("relationalexpression", 3, $1, new_reserved(">"), $3);}
                        | relationalexpression LE additiveexpression        {$$=new_nonterminal("relationalexpression", 3, $1, new_reserved("<="), $3);}
                        | relationalexpression GE additiveexpression        {$$=new_nonterminal("relationalexpression", 3, $1, new_reserved(">="), $3);}
                        ;

equalityexpression      : relationalexpression                              {$$=new_nonterminal("equalityexpression", 1, $1);}
                        | equalityexpression EQ relationalexpression        {$$=new_nonterminal("equalityexpression", 3, $1, new_reserved("=="), $3);}
                        | equalityexpression NE relationalexpression        {$$=new_nonterminal("equalityexpression", 3, $1, new_reserved("!="), $3);}
                        ;

conditionalandexpression: equalityexpression                                {$$=new_nonterminal("conditionalandexpression", 1, $1);}
                        | conditionalandexpression AND equalityexpression   {$$=new_nonterminal("conditionalandexpression", 3, $1, new_reserved("&&"), $3);}
                        ;

conditionalorexpression : conditionalandexpression                              {$$=new_nonterminal("conditionalorexpression", 1, $1);}
                        | conditionalorexpression OR conditionalandexpression   {$$=new_nonterminal("conditionalorexpression", 3, $1, new_reserved("||"), $3);}
                        ;

assignmentexpression    : conditionalorexpression           {$$=new_nonterminal("assignmentexpression", 1, $1);}
                        | assignment                        {$$=new_nonterminal("assignmentexpression", 1, $1);}
                        ;       

assignment              : identifier '=' assignmentexpression   {$$=new_nonterminal("assignment", 3, $1, new_reserved("="), $3);}
                        ;

expression              : assignmentexpression              {$$=new_nonterminal("expression", 1, $1);}
                        ;


%%