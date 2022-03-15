%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "parser.h"
    #include "AST.h"
    #include "STab.h"

%}


%defines "parser.bison.h"
%output "parser.bison.cpp"
%expect 1
%define api.value.type {AST *}

%token  NUMBER STRING_Y TRUE FALSE BOOLEAN INT ID VOID BREAK RETURN IF ELSE WHILE LE GE NE EQ AND OR



%%

dummy_start     : start                 {CollectGlobal($$);BuildSymbolTable($$,"");dummy_break_point();}
                ;

start           : /* empty */
                | globaldeclarations    {$$=$1;}
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
                        | IF '(' expression ')' statement                   {$$=new AST(NodeType::IF, "IF", $3, $5);}
                        | IF '(' expression ')' statement ELSE statement    {$$=new AST(NodeType::IF_ELSE,"IF_ELSE",$3, $5, $7);}
                        | WHILE '(' expression ')' statement                {$$=new AST(NodeType::WHILE,"WHILE", $3, $5); }
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

unaryexpression         : '-' unaryexpression                               {$$=new AST(NodeType::UN_ARITHMETIC,"-",$2);}
                        | '!' unaryexpression                               {$$=new AST(NodeType::UN_LOGIC,"!",$2);}
                        | postfixexpression                                 {$$=$1;}
                        ;

multiplicativeexpression: unaryexpression                                   {$$=$1;}
                        | multiplicativeexpression '*' unaryexpression      {$$=new AST(NodeType::BIN_ARITHMETIC,"+",$1, $3);}
                        | multiplicativeexpression '/' unaryexpression      {$$=new AST(NodeType::BIN_ARITHMETIC,"/",$1, $3);}
                        | multiplicativeexpression '%' unaryexpression      {$$=new AST(NodeType::BIN_ARITHMETIC,"%",$1, $3);}
                        ;

additiveexpression      : multiplicativeexpression                          {$$=$1;}
                        | additiveexpression '+' multiplicativeexpression   {$$= new AST(NodeType::BIN_ARITHMETIC,"+",$1, $3);}
                        | additiveexpression '-' multiplicativeexpression   {$$= new AST(NodeType::BIN_ARITHMETIC,"-",$1, $3);}
                        ;

relationalexpression    : additiveexpression                                {$$=$1;}
                        | relationalexpression '<' additiveexpression       {$$=new AST(NodeType::BIN_LOGIC,"<", $1, $3);;}
                        | relationalexpression '>' additiveexpression       {$$=new AST(NodeType::BIN_LOGIC,">", $1, $3);}
                        | relationalexpression LE additiveexpression        {$$=new AST(NodeType::BIN_LOGIC,"<=", $1, $3);}
                        | relationalexpression GE additiveexpression        {$$=new AST(NodeType::BIN_LOGIC,">=", $1, $3);}
                        ;

equalityexpression      : relationalexpression                              {$$=$1;}
                        | equalityexpression EQ relationalexpression        {$$=new AST(NodeType::BIN_LOGIC,"==", $1, $3);}
                        | equalityexpression NE relationalexpression        {$$=new AST(NodeType::BIN_LOGIC,"!=", $1, $3);}
                        ;

conditionalandexpression: equalityexpression                                {$$=$1;}
                        | conditionalandexpression AND equalityexpression   {$$=new AST(NodeType::BIN_LOGIC,"&&", $1, $3);}
                        ;

conditionalorexpression : conditionalandexpression                              {$$=$1;}
                        | conditionalorexpression OR conditionalandexpression   {$$=new AST(NodeType::BIN_LOGIC,"||", $1, $3);}
                        ;



assignmentexpression    : conditionalorexpression           {$$=$1;}
                        | assignment                        {$$=$1;}
                        ;       

assignment              : identifier '=' assignmentexpression   {$$=new AST(NodeType::ASSIGN, "=" ,$1, $3);}
                        ;

expression              : assignmentexpression              {$$=$1;}
                        ;


%%




// define yyerror for bison
void yyerror(char const *s)
{
    // print out the token that cannot be shifted or reduced and its line number
    fprintf(stderr, "ERROR: %s, probably at or near \"%s\" on line %d\n", s, yylval->symbol);
}
