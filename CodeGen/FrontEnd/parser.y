%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "parser.h"
    #include "AST.h"
    #include "semantic.h"
    AST *root;
%}


%defines "parser.bison.h"
%output "parser.bison.cpp"
%expect 1
%define api.value.type {AST *}

%token  NUMBER STRING_Y TRUE FALSE BOOLEAN INT ID VOID BREAK RETURN IF ELSE WHILE LE GE NE EQ AND OR



%%



start           : /* empty */
                | globaldeclarations    {root=$1;
                                        }
                ;

literal         : NUMBER                {$$=$1;}
                | STRING_Y              {$$=$1;}
                | TRUE                  {$$=$1;}
                | FALSE                 {$$=$1;}
                ;       

type            : BOOLEAN               {$$=$1;}
                | INT                   {$$=$1;}
                ;

globaldeclarations      : globaldeclaration                             {$$=new AST(NodeType::PROGRAM, "PROGRAM",$1);}
                        | globaldeclarations globaldeclaration          {$1->AttachChildren($2);$$=$1;}
                        ;

globaldeclaration       : variabledeclaration                           {$1->type=NodeType::GLOBAL_VAR_DEC;$1->symbol="GLOBAL_VAR_DEC";$$=$1;}
                        | functiondeclaration                           {$$=$1;}
                        | mainfunctiondeclaration                       {$$=$1;}
                        ;

variabledeclaration     : type identifier ';'                           {$$=new AST(NodeType::VAR_DEC,"VAR_DEC",$1,$2);}
                        ;

identifier              : ID                                            {$$=$1;}
                        ;

functiondeclaration     : functionheader block                          {$1->AttachChildren($2);$$=$1;}
                        ;

functionheader          : type functiondeclarator                       {$2->children.insert($2->children.begin(),$1);$$=$2;}
                        | VOID functiondeclarator                       {$2->children.insert($2->children.begin(), new AST(NodeType::VOID,"VOID"));$$=$2;}
                        ;

functiondeclarator      : identifier '(' formalparameterlist ')'        {$$=new AST(NodeType::FUNC_DEC, "FUNC_DEC",  $1, $3);}
                        | identifier '(' ')'                            {$$=new AST(NodeType::FUNC_DEC, "FUNC_DEC",  $1, new AST(NodeType::FORMALS,"FORMALS"));}
                        ;

formalparameterlist     : formalparameter                               {$$=new AST(NodeType::FORMALS,"FORMALS",$1);}
                        | formalparameterlist ',' formalparameter       {$1->AttachChildren($3);$$=$1;}
                        ;

formalparameter         : type identifier                               {$$=new AST(NodeType::FORMAL, "FORMAL",$1, $2);}
                        ;

mainfunctiondeclaration : mainfunctiondeclarator block                  {$$=new AST(NodeType::MAIN_DEC, "MAIN_DEC", new AST(NodeType::VOID, "VOID"),$1,new AST(NodeType::FORMALS,"FORMALS"),$2);}
                        ;

mainfunctiondeclarator  : identifier '(' ')'                            {$$=$1;}
                        ;

block                   : '{' blockstatements '}'                       {$$=$2;}
                        | '{' '}'                                       {$$=new AST(NodeType::BLOCK,"BLOCK");}
                        ;

blockstatements         : blockstatement                                {$$=new AST(NodeType::BLOCK, "BLOCK",$1);}
                        | blockstatements blockstatement                {$1->AttachChildren($2);$$=$1;};
                        ;

blockstatement          : variabledeclaration                           {$$=$1;}
                        | statement                                     {$$=$1;}
                        ;

statement               : block                                             {$$=$1;}
                        | ';'                                               {$$=new AST(NodeType::NULL_STMT,"nullStmt");}
                        | statementexpression ';'                           {$$=new AST(NodeType::STMT_EXPR,"STMTEXPR",$1);}
                        | BREAK ';'                                         {$$=$1;}
                        | RETURN expression ';'                             {$1->AttachChildren($2); $$=$1;}
                        | RETURN ';'                                        {$$=$1;}
                        | IF '(' expression ')' statement                   {$1->AttachChildren($3,$5);$$=$1;}
                        | IF '(' expression ')' statement ELSE statement    {$1->type=NodeType::IF_ELSE;$1->AttachChildren($3,$5,$7);$$=$1;}
                        | WHILE '(' expression ')' statement                {$1->AttachChildren($3,$5);$$=$1; }
                        ;




statementexpression     : assignment                                        {$$=$1;}
                        | functioninvocation                                {$$=$1;}
                        ;

primary                 : literal                                           {$$=$1;}
                        | '(' expression ')'                                {$$=$2;}
                        | functioninvocation                                {$$=$1;}
                        ;

argumentlist            : expression                                        {$$=new AST(NodeType::ACTUALS,"ACTUALS",$1);}
                        | argumentlist ',' expression                       {$1->AttachChildren($3);$$=$1;}
                        ;

functioninvocation      : identifier '(' argumentlist ')'                   {$$=new AST(NodeType::FUNC_CALL, "FUNC_CALL",$1, $3);;}
                        | identifier '(' ')'                                {$$=new AST(NodeType::FUNC_CALL, "FUNC_CALL",$1, new AST(NodeType::ACTUALS,"ACTUALS"));}
                        ;

postfixexpression       : primary                                           {$$=$1;}
                        | identifier                                        {$$=$1;}
                        ;

unaryexpression         : '-' unaryexpression                               {$1->type=NodeType::UN_ARITHMETIC;$1->AttachChildren($2);$$=$1;}
                        | '!' unaryexpression                               {$1->AttachChildren($2);$$=$1;}
                        | postfixexpression                                 {$$=$1;}
                        ;

multiplicativeexpression: unaryexpression                                   {$$=$1;}
                        | multiplicativeexpression '*' unaryexpression      {$2->AttachChildren($1,$3);$$=$2;}
                        | multiplicativeexpression '/' unaryexpression      {$2->AttachChildren($1,$3);$$=$2;}
                        | multiplicativeexpression '%' unaryexpression      {$2->AttachChildren($1,$3);$$=$2;}
                        ;

additiveexpression      : multiplicativeexpression                          {$$=$1;}
                        | additiveexpression '+' multiplicativeexpression   {$2->AttachChildren($1,$3);$$=$2;}
                        | additiveexpression '-' multiplicativeexpression   {$2->AttachChildren($1,$3);$$=$2;}
                        ;

relationalexpression    : additiveexpression                                {$$=$1;}
                        | relationalexpression '<' additiveexpression       {$2->AttachChildren($1,$3);$$=$2;}
                        | relationalexpression '>' additiveexpression       {$2->AttachChildren($1,$3);$$=$2;}
                        | relationalexpression LE additiveexpression        {$2->AttachChildren($1,$3);$$=$2;}
                        | relationalexpression GE additiveexpression        {$2->AttachChildren($1,$3);$$=$2;}
                        ;

equalityexpression      : relationalexpression                              {$$=$1;}
                        | equalityexpression EQ relationalexpression        {$2->AttachChildren($1,$3);$$=$2;}
                        | equalityexpression NE relationalexpression        {$2->AttachChildren($1,$3);$$=$2;}
                        ;

conditionalandexpression: equalityexpression                                {$$=$1;}
                        | conditionalandexpression AND equalityexpression   {$2->AttachChildren($1,$3);$$=$2;}
                        ;

conditionalorexpression : conditionalandexpression                              {$$=$1;}
                        | conditionalorexpression OR conditionalandexpression   {$2->AttachChildren($1,$3);$$=$2;}
                        ;



assignmentexpression    : conditionalorexpression           {$$=$1;}
                        | assignment                        {$$=$1;}
                        ;       

assignment              : identifier '=' assignmentexpression   {$2->AttachChildren($1,$3);$$=$2;}
                        ;

expression              : assignmentexpression              {$$=$1;}
                        ;


%%


// define yyerror for bison
void yyerror(char const *s)
{
    // print out the token that cannot be shifted or reduced and its line number
    fprintf(stderr, "Syntax Error around:  %s, at or near %d", yytext, yylineno);
    exit(EXIT_FAILURE);
}
