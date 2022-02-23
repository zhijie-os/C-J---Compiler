%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "parser.h"
%}



%define api.value.type {struct ast*}

%token  NUMBER STRING TRUE FALSE BOOLEAN INT ID VOID BREAK RETURN IF ELSE WHILE LE GE NE EQ AND OR


%%

dummy_start     : start                 {print_tree($1,0);}

start           : /* empty */
                | globaldeclarations    {$$=new_ast("PROGRAM:",1,$1);}
                ;

literal         : NUMBER                {$$=$1;}
                | STRING                {$$=$1;}
                | TRUE                  {$$=$1;}
                | FALSE                 {$$=$1;}
                ;       

type            : BOOLEAN               {$$=$1;}
                | INT                   {$$=$1;}
                ;

globaldeclarations      : globaldeclaration                             {$$=$1;}
                        | globaldeclarations globaldeclaration          {$$=new_ast("GLOBALDECLARATIONS:",2,$1, $2);}
                        ;

globaldeclaration       : variabledeclaration                           {$$=$1;}
                        | functiondeclaration                           {$$=$1;}
                        | mainfunctiondeclaration                       {$$=$1;}
                        ;

variabledeclaration     : type identifier ';'                           {$$=new_ast("VARIABLEDECLARATION:", 2,$1,$2);}
                        ;

identifier              : ID                                            {$$=$1;}
                        ;

functiondeclaration     : functionheader block                          {$$=new_ast("FUNCTIONDECLARATION:",2,$1,$2);}
                        ;

functionheader          : type functiondeclarator                       {$$=new_ast("FUNCTIONHEADER:", 2, $1, $2);}
                        | VOID functiondeclarator                       {$$=new_ast("FUNCTIONHEADER:", 2, $1, $2);}
                        ;

functiondeclarator      : identifier '(' formalparameterlist ')'        {$$=new_ast("FUNCTIONDECLARATOR:", 2, $1,$3);}
                        | identifier '(' ')'                            {$$=$1;}
                        ;

formalparameterlist     : formalparameter                               {$$=$1;}
                        | formalparameterlist ',' formalparameter       {$$=new_ast("FORMALPARAMETERLIST:", 2, $1,$3);}
                        ;

formalparameter         : type identifier                               {$$=new_ast("FORMALPARAMETER:", 2, $1, $2);}
                        ;

mainfunctiondeclaration : mainfunctiondeclarator block                  {$$=new_ast("MAINFUNCTIONDECLARATION:", 2, $1, $2);}
                        ;

mainfunctiondeclarator  : identifier '(' ')'                            {$$=$1;}
                        ;

block                   : '{' blockstatements '}'                       {$$=new_ast("BLOCK:",1,$2);}
                        | '{' '}'                                       {$$=new_ast("BLOCK:",0);}
                        ;

blockstatements         : blockstatement                                {$$=$1;}
                        | blockstatements blockstatement                {$$=new_ast("BLOCKSTATEMENTS:", 2, $1, $2);}
                        ;

blockstatement          : variabledeclaration                           {$$=$1;}
                        | statement                                     {$$=$1;}
                        ;

statement               : block                                             {$$=$1;}
                        | ';'                                               {$$=$1;}
                        | statementexpression ';'                           {$$=$1;}
                        | BREAK ';'                                         {$$=$1;}
                        | RETURN expression ';'                             {$$=new_ast("statement", 2, $1, $2);}
                        | RETURN ';'                                        {$$=$1;}
                        | IF '(' expression ')' statement                   {$$=new_ast("if", 2, $3, $5);}
                        | IF '(' expression ')' statement ELSE statement    {$$=new_ast("ifElse", 3, $3, $5, $7);}
                        | WHILE '(' expression ')' statement                {$$=new_ast("while", 2, $3, $5); }
                        ;




statementexpression     : assignment                                        {$$=$1;}
                        | functioninvocation                                {$$=$1;}
                        ;

primary                 : literal                                           {$$=$1;}
                        | '(' expression ')'                                {$$=$2;}
                        | functioninvocation                                {$$=$1;}
                        ;

argumentlist            : expression                                        {$$=$1;}
                        | argumentlist ',' expression                       {$$=new_ast("ARGUMENTLIST:", 2, $1, $3);}
                        ;

functioninvocation      : identifier '(' argumentlist ')'                   {$$=new_ast("FUNCTIONINVOCATION:", 2, $1, $3);}
                        | identifier '(' ')'                                {$$=$1;}
                        ;

postfixexpression       : primary                                           {$$=$1;}
                        | identifier                                        {$$=$1;}
                        ;

unaryexpression         : '-' unaryexpression                               {$$=new_ast("UNARYEXPRESSION", 2, $1, $2);}
                        | '!' unaryexpression                               {$$=new_ast("UNARYEXPRESSION", 2, $1, $2);}
                        | postfixexpression                                 {$$=$1;}
                        ;

multiplicativeexpression: unaryexpression                                   {$$=$1;}
                        | multiplicativeexpression '*' unaryexpression      {$$=new_ast("MULTIPLICATIVEEXPRESSION:", 3, $1, $2, $3);}
                        | multiplicativeexpression '/' unaryexpression      {$$=new_ast("MULTIPLICATIVEEXPRESSION:", 3, $1, $2, $3);}
                        | multiplicativeexpression '%' unaryexpression      {$$=new_ast("MULTIPLICATIVEEXPRESSION:", 3, $1, $2, $3);}
                        ;

additiveexpression      : multiplicativeexpression                          {$$=$1;}
                        | additiveexpression '+' multiplicativeexpression   {$$=new_ast("ADDITIVEEXPRESSION:", 3, $1, $2, $3);}
                        | additiveexpression '-' multiplicativeexpression   {$$=new_ast("ADDITIVEEXPRESSION:", 3, $1, $2, $3);}
                        ;

relationalexpression    : additiveexpression                                {$$=$1;}
                        | relationalexpression '<' additiveexpression       {$$=new_ast("RELATIONALEXPRESSION:", 3, $1, $2, $3);}
                        | relationalexpression '>' additiveexpression       {$$=new_ast("RELATIONALEXPRESSION:", 3, $1, $2, $3);}
                        | relationalexpression LE additiveexpression        {$$=new_ast("RELATIONALEXPRESSION:", 3, $1, $2, $3);}
                        | relationalexpression GE additiveexpression        {$$=new_ast("RELATIONALEXPRESSION:", 3, $1, $2, $3);}
                        ;

equalityexpression      : relationalexpression                              {$$=$1;}
                        | equalityexpression EQ relationalexpression        {$$=new_ast("EQUALITYEXPRESSION:", 3, $1, $2, $3);}
                        | equalityexpression NE relationalexpression        {$$=new_ast("EQUALITYEXPRESSION:", 3, $1, $2, $3);}
                        ;

conditionalandexpression: equalityexpression                                {$$=$1;}
                        | conditionalandexpression AND equalityexpression   {$$=new_ast("CONDITIONALANDEXPRESSION:", 3, $1, $2, $3);}
                        ;

conditionalorexpression : conditionalandexpression                              {$$=$1;}
                        | conditionalorexpression OR conditionalandexpression   {$$=new_ast("CONDITIONALOREXPRESSION:", 3, $1, $2, $3);}
                        ;



assignmentexpression    : conditionalorexpression           {$$=$1;}
                        | assignment                        {$$=$1;}
                        ;       

assignment              : identifier '=' assignmentexpression   {$$=new_ast("ASSIGNMENT:", 3, $1, $2,  $3);}
                        ;

expression              : assignmentexpression              {$$=$1;}
                        ;


%%