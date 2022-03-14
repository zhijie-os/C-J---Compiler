%option noyywrap yylineno outfile="scanner.flex.cpp"

%{

    #include "parser.h"
    #include "parser.bison.h"

    int num_lexer_error=0;

%}



%x COMMENT
%x STRING

/* regular definition */


delim   [ \t\r]
ws      {delim}+
letter  [A-Za-z]
letter_ [A-Za-z_]
digit   [0-9]
id      {letter_}({letter_}|{digit})*
number  {digit}+
 


%% 

. {yylval=new AST(yytext, false);return NUMBER;}

%%
