%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "simplest.h"
%}

%union{
        struct  ast *node;   
        struct  info *attribute;     
};

%token <node>   NUM
%type  <node>   line, exp

%%
line    :   exp             {print_tree($1,0);}
        ;


exp     :   NUM             {$$=new_ast("exp",1,new_num("NUM",yylval.attribute));}
        |   exp '+' exp     {$$=new_ast("exp",3,$1,new_reserved("+"),$3);}
        |   exp '-' exp     {$$=new_ast("exp",3,$1,new_reserved("-"),$3);}
        ;

%%


