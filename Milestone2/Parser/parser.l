%option noyywrap yylineno

%{
    #include "parser.h"
    #include "parser.tab.h"

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

"\""                                                {BEGIN(STRING);}
<STRING>(\\[bftrn'"\\]|[^"\\\r\n<<EOF>>])*          {atomic_ast("X", yylineno, yytext); return STRING;}
<STRING>"\""                                        {BEGIN(0);}
<STRING>\\[^bftrn'"\\]                              {lexer_string_error("unsupported escape character");}
<STRING>\n                                          {lexer_string_error("newline in string literal");}
<STRING>\r                                          {lexer_string_error("return in string literal");}
<STRING><<EOF>>                                     {lexer_string_error("string missing closing quote");}


"//"                                                {BEGIN(COMMENT);}
<COMMENT>[^\r\n]                                    {/* eats up the comment */};
<COMMENT>\n                                         {BEGIN(0);}
<COMMENT>[\r<<EOF>>]                                {BEGIN(0);}



\n          {}
{ws}        {/* ignore whitespaces */}
true        {yylval=atomic_ast("true", yylineno, yytext); return TRUE;}
false       {yylval=atomic_ast("false", yylineno, yytext); return FALSE;}
boolean     {yylval=atomic_ast("boolean", yylineno, yytext); return BOOLEAN;}
int         {yylval=atomic_ast("int", yylineno, yytext); return INT;}
void        {yylval=atomic_ast("void", yylineno, yytext); return VOID;}
if          {yylval=atomic_ast("if", yylineno, yytext); return IF;}
else        {yylval=atomic_ast("else", yylineno, yytext); return ELSE;}
while       {yylval=atomic_ast("while", yylineno, yytext); ;return WHILE;}
break       {yylval=atomic_ast("break", yylineno, yytext); return BREAK;}
return      {yylval=atomic_ast("return", yylineno, yytext); return RETURN;}
"+"         {yylval=atomic_ast("+", yylineno, yytext); return '+';}
"-"         {yylval=atomic_ast("-", yylineno, yytext); return '-';}
"*"         {yylval=atomic_ast("*", yylineno, yytext); return '*';}
"/"         {yylval=atomic_ast("/", yylineno, yytext); return '/';}
"%"         {yylval=atomic_ast("%", yylineno, yytext); return '%';}
"<"         {yylval=atomic_ast("<", yylineno, yytext); return '<';}
">"         {yylval=atomic_ast(">", yylineno, yytext); return '>';}
"<="        {yylval=atomic_ast("<=", yylineno, yytext); return LE;}
">="        {yylval=atomic_ast(">=", yylineno, yytext); return GE;}
"=="        {yylval=atomic_ast("==", yylineno, yytext); return EQ;}
"!="        {yylval=atomic_ast("!+", yylineno, yytext); return NE;}
"="         {yylval=atomic_ast("=", yylineno, yytext); return '=';}
"!"         {yylval=atomic_ast("!", yylineno, yytext); return '!';}
"&&"        {yylval=atomic_ast("&&", yylineno, yytext); return AND;}
"||"        {yylval=atomic_ast("||", yylineno, yytext); return OR;}
"("         {yylval=atomic_ast("(", yylineno, yytext); return '(';}
")"         {yylval=atomic_ast(")", yylineno, yytext); return ')';}
"{"         {yylval=atomic_ast("{", yylineno, yytext); return '{';}
"}"         {yylval=atomic_ast("}", yylineno, yytext); return '}';}
";"         {yylval=atomic_ast(";", yylineno, yytext); return ';';}
","         {yylval=atomic_ast(",", yylineno, yytext); return ',';}
{number}    {yylval=atomic_ast("number", yylineno, yytext); return NUMBER;}
{id}        {yylval=atomic_ast("id", yylineno, yytext); return ID;}

.           {lexer_general_error();}

%%
