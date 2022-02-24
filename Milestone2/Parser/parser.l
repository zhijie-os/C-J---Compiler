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
<STRING>(\\[bftrn'"\\]|[^"\\\r\n<<EOF>>])*          {yylval=atomic_ast("string", yylineno,yytext); return STRING_Y;}
<STRING>"\""                                        {BEGIN(0);}
<STRING>\\[^bftrn'"\\]                              {lexer_string_error("unsupported escape character");}
<STRING>\n                                          {lexer_string_error("newline in string literal");}
<STRING>\r                                          {lexer_string_error("return in string literal");}
<STRING><<EOF>>                                     {lexer_string_error("string missing closing quote");}


"//"                                                {BEGIN(COMMENT);}
<COMMENT>[^\r\n]                                    {/* eats up the comment */};
<COMMENT>\n                                         {BEGIN(0);}



\n          {}
{ws}        {/* ignore whitespaces */}
true        {yylval=atomic_ast("true", yylineno,"None"); return TRUE;}
false       {yylval=atomic_ast("false", yylineno,"None"); return FALSE;}
boolean     {yylval=atomic_ast("boolean", yylineno,"None"); return BOOLEAN;}
int         {yylval=atomic_ast("int", yylineno,"None"); return INT;}
void        {yylval=atomic_ast("void", yylineno,"None"); return VOID;}
if          {yylval=atomic_ast("if", yylineno,"None"); return IF;}
else        {yylval=atomic_ast("else", yylineno,"None"); return ELSE;}
while       {yylval=atomic_ast("while", yylineno,"None"); ;return WHILE;}
break       {yylval=atomic_ast("break", yylineno,"None"); return BREAK;}
return      {yylval=atomic_ast("return", yylineno,"None"); return RETURN;}
"+"         {yylval=atomic_ast("+", yylineno,"None"); return '+';}
"-"         {yylval=atomic_ast("-", yylineno,"None"); return '-';}
"*"         {yylval=atomic_ast("*", yylineno,"None"); return '*';}
"/"         {yylval=atomic_ast("/", yylineno,"None"); return '/';}
"%"         {yylval=atomic_ast("%", yylineno,"None"); return '%';}
"<"         {yylval=atomic_ast("<", yylineno,"None"); return '<';}
">"         {yylval=atomic_ast(">", yylineno,"None"); return '>';}
"<="        {yylval=atomic_ast("<=", yylineno,"None"); return LE;}
">="        {yylval=atomic_ast(">=", yylineno,"None"); return GE;}
"=="        {yylval=atomic_ast("==", yylineno,"None"); return EQ;}
"!="        {yylval=atomic_ast("!=", yylineno,"None"); return NE;}
"="         {yylval=atomic_ast("=", yylineno,"None"); return '=';}
"!"         {yylval=atomic_ast("!", yylineno,"None"); return '!';}
"&&"        {yylval=atomic_ast("&&", yylineno,"None"); return AND;}
"||"        {yylval=atomic_ast("||", yylineno,"None"); return OR;}
"("         {yylval=atomic_ast("(", yylineno,"None"); return '(';}
")"         {yylval=atomic_ast(")", yylineno,"None"); return ')';}
"{"         {yylval=atomic_ast("{", yylineno,"None"); return '{';}
"}"         {yylval=atomic_ast("}", yylineno,"None"); return '}';}
";"         {yylval=atomic_ast(";", yylineno,"None"); return ';';}
","         {yylval=atomic_ast(",", yylineno,"None"); return ',';}
{number}    {yylval=atomic_ast("number", yylineno, yytext); return NUMBER;}
{id}        {yylval=atomic_ast("id", yylineno, yytext); return ID;}

.           {lexer_general_error();}

%%
