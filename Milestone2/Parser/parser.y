%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "parser.h"
%}



%define api.value.type {struct ast*}

%token  NUMBER STRING_Y TRUE FALSE BOOLEAN INT ID VOID BREAK RETURN IF ELSE WHILE LE GE NE EQ AND OR


%%

dummy_start     : start                 {print_tree($1,0);}

start           : /* empty */
                | globaldeclarations    {$$=rename_ast("PROGRAM:",$1);}
                ;

literal         : NUMBER                {$$=$1;}
                | STRING_Y              {$$=$1;}
                | TRUE                  {$$=$1;}
                | FALSE                 {$$=$1;}
                ;       

type            : BOOLEAN               {$$=$1;}
                | INT                   {$$=$1;}
                ;

globaldeclarations      : globaldeclaration                             {$$=fold_ast_base($1);}
                        | globaldeclarations globaldeclaration          {$$=fold_ast($1, $2);}
                        ;

globaldeclaration       : variabledeclaration                           {$$=rename_ast("GLOBAL_VAR_DECL",$1);}
                        | functiondeclaration                           {$$=$1;}
                        | mainfunctiondeclaration                       {$$=$1;}
                        ;

variabledeclaration     : type identifier ';'                           {$$=new_ast("VAR_DECL:", 2,$1,$2);}
                        ;

identifier              : ID                                            {$$=$1;}
                        ;

functiondeclaration     : functionheader block                          {$$=rename_ast("FUNCDEC:", attach_new_children($1,1,$2));}
                        ;

functionheader          : type functiondeclarator                       {$$=steal_children(new_ast("FUNCTIONHEADER:",1,$1),$2);}
                        | VOID functiondeclarator                       {$$=steal_children(new_ast("FUNCTIONHEADER:",1,$1),$2);}
                        ;

functiondeclarator      : identifier '(' formalparameterlist ')'        {$$=new_ast("FUNCTIONDECLARATOR:", 2, $1,rename_ast("FORMALS:",$3));}
                        | identifier '(' ')'                            {$$=new_ast("FUNCTIONDECLARATOR:", 2, $1, new_ast("FORMALS:",0));}
                        ;

formalparameterlist     : formalparameter                               {$$=fold_ast_base($1);}
                        | formalparameterlist ',' formalparameter       {$$=fold_ast($1,$3);}
                        ;

formalparameter         : type identifier                               {$$=new_ast("FORMAL:", 2, $1, $2);}
                        ;

mainfunctiondeclaration : mainfunctiondeclarator block                  {$$=new_ast("MAINDECL:", 4, new_ast("VOID:",0),$1,new_ast("FORMALS:",0) ,$2);}
                        ;

mainfunctiondeclarator  : identifier '(' ')'                            {$$=$1;}
                        ;

block                   : '{' blockstatements '}'                       {$$=rename_ast("BLOCK:",$2);}
                        | '{' '}'                                       {$$=new_ast("BLOCK:",0);}
                        ;

blockstatements         : blockstatement                                {$$=fold_ast_base($1);}
                        | blockstatements blockstatement                {$$=fold_ast($1, $2);}
                        ;

blockstatement          : variabledeclaration                           {$$=$1;}
                        | statement                                     {$$=$1;}
                        ;

statement               : block                                             {$$=$1;}
                        | ';'                                               {$$=atomic_ast("nullStmt",$1->line_num,"None");}
                        | statementexpression ';'                           {$$=new_ast("STMTEXPR",1,$1);}
                        | BREAK ';'                                         {$$=$1;}
                        | RETURN expression ';'                             {$$=attach_new_children($1,1,$2);}
                        | RETURN ';'                                        {$$=$1;}
                        | IF '(' expression ')' statement                   {$$=new_ast("IF:", 2,  $3, $5);}
                        | IF '(' expression ')' statement ELSE statement    {$$=new_ast("IF_ELSE:", 3, $3, $5, $7);}
                        | WHILE '(' expression ')' statement                {$$=new_ast("WHILE:", 3, $1, $3, $5); }
                        ;




statementexpression     : assignment                                        {$$=$1;}
                        | functioninvocation                                {$$=$1;}
                        ;

primary                 : literal                                           {$$=$1;}
                        | '(' expression ')'                                {$$=$2;}
                        | functioninvocation                                {$$=$1;}
                        ;

argumentlist            : expression                                        {$$=fold_ast_base($1);}
                        | argumentlist ',' expression                       {$$=fold_ast($1, $3);}
                        ;

functioninvocation      : identifier '(' argumentlist ')'                   {$$=new_ast("FUNC_CALL:", 2, $1, rename_ast("ACTUALS:",$3));}
                        | identifier '(' ')'                                {$$=new_ast("FUNC_CALL:", 2, $1, new_ast("ACTUALS:",0));}
                        ;

postfixexpression       : primary                                           {$$=$1;}
                        | identifier                                        {$$=$1;}
                        ;

unaryexpression         : '-' unaryexpression                               {$$=attach_new_children($1, 1, $2);}
                        | '!' unaryexpression                               {$$=attach_new_children($1, 1, $2);}
                        | postfixexpression                                 {$$=$1;}
                        ;

multiplicativeexpression: unaryexpression                                   {$$=$1;}
                        | multiplicativeexpression '*' unaryexpression      {$$=attach_new_children($2, 2, $1, $3);}
                        | multiplicativeexpression '/' unaryexpression      {$$=attach_new_children($2, 2, $1, $3);}
                        | multiplicativeexpression '%' unaryexpression      {$$=attach_new_children($2, 2, $1, $3);}
                        ;

additiveexpression      : multiplicativeexpression                          {$$=$1;}
                        | additiveexpression '+' multiplicativeexpression   {$$=attach_new_children($2, 2, $1, $3);}
                        | additiveexpression '-' multiplicativeexpression   {$$=attach_new_children($2, 2, $1, $3);}
                        ;

relationalexpression    : additiveexpression                                {$$=$1;}
                        | relationalexpression '<' additiveexpression       {$$=attach_new_children($2, 2, $1, $3);}
                        | relationalexpression '>' additiveexpression       {$$=attach_new_children($2, 2, $1, $3);}
                        | relationalexpression LE additiveexpression        {$$=attach_new_children($2, 2, $1, $3);}
                        | relationalexpression GE additiveexpression        {$$=attach_new_children($2, 2, $1, $3);}
                        ;

equalityexpression      : relationalexpression                              {$$=$1;}
                        | equalityexpression EQ relationalexpression        {$$=attach_new_children($2, 2, $1, $3);}
                        | equalityexpression NE relationalexpression        {$$=attach_new_children($2, 2, $1, $3);}
                        ;

conditionalandexpression: equalityexpression                                {$$=$1;}
                        | conditionalandexpression AND equalityexpression   {$$=attach_new_children($2, 2, $1, $3);}
                        ;

conditionalorexpression : conditionalandexpression                              {$$=$1;}
                        | conditionalorexpression OR conditionalandexpression   {$$=attach_new_children($2, 2, $1, $3);}
                        ;



assignmentexpression    : conditionalorexpression           {$$=$1;}
                        | assignment                        {$$=$1;}
                        ;       

assignment              : identifier '=' assignmentexpression   {$$=attach_new_children($2, 2, $1, $3);}
                        ;

expression              : assignmentexpression              {$$=$1;}
                        ;


%%