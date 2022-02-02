%option noyywrap
%option yylineno

/* Declarations */
%{
    // Declarations go here
    #include "scanner.h"
    // int lineno = 1;
%}

/* Definitions here */
alpha       [a-zA-Z]
digit       [0-9]
alnum       [a-zA-Z0-9]

num     {digit}{digit}*
ID      {alpha}{alnum}*

/* Comment States */
%x COMMENT

%% 

 /* Rules here */
[ \t\r]+    ;       /* Ignore whitespace */       
\n          ;       /* Track line number */

">"         return T_GT;
"<"         return T_LT;
">="        return T_GE;
"<="        return T_LE;
"+"         return T_ADD;
"-"         return T_SUB;
"/"         return T_DIV;
"*"         return T_MULT;
"begin"     return T_BEGIN;
"end"       return T_END;

{ID}        return T_ID;
{num}       return T_NUM;


"#"             BEGIN(COMMENT);
<COMMENT>. 
<COMMENT>\n     {BEGIN(INITIAL); printf("Caught comment at line %d\n", yylineno);}
.               fprintf(stderr, "Illegal char at line %d\n", yylineno);

%% 

/* User routines here*/
// int yywrap() { return 1; }


