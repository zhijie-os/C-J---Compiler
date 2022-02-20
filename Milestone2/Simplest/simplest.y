%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "simplest.h"
%}

%union{
        int     val;
        char    *str;
        struct  ast *node;   
        struct  info *attribute;     
};

%token <val>    NUM    
%type <node> line
%type <node> exp

%%
line    :   exp             {print_tree($1,0);}
        ;


exp     :   NUM             {$$=new_num("NUM",yylval.attribute);}
        |   exp '+' exp     {$$=new_nonterminal("exp",$1,new_reserved("+"),$3);}
        |   exp '-' exp     {$$=new_nonterminal("exp",$1,new_reserved("-"),$3);}
        ;

%%


