%option noyywrap yylineno

%{
    #include "simplest.h"
    #include "simplest.tab.h"
%}



%%

[0-9]*  {yylval.attribute=create_atr(yylineno,yytext); return NUM;}
"+"     {yylval.attribute=create_atr(yylineno,yytext); return '+';}
"-"     {yylval.attribute=create_atr(yylineno,yytext); return '-';}

.       {printf("unrecognized %s",yytext);}

%%

