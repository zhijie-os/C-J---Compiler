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
<STRING>(\\[bftrn'"\\]|[^"\\\r\n<<EOF>>])*          {yylval.attribute=create_atr(yylineno,yytext); return STRING;}
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
true        {yylval.attribute=create_atr(yylineno,yytext); return TRUE;}
false       {yylval.attribute=create_atr(yylineno,yytext); return FALSE;}
boolean     {yylval.attribute=create_atr(yylineno,yytext); return BOOLEAN;}
int         {yylval.attribute=create_atr(yylineno,yytext); return INT;}
void        {yylval.attribute=create_atr(yylineno,yytext); return VOID;}
if          {yylval.attribute=create_atr(yylineno,yytext); return IF;}
else        {yylval.attribute=create_atr(yylineno,yytext); return ELSE;}
while       {yylval.attribute=create_atr(yylineno,yytext); printf("While");return WHILE;}
break       {yylval.attribute=create_atr(yylineno,yytext); return BREAK;}
return      {yylval.attribute=create_atr(yylineno,yytext); return RETURN;}
"+"         {yylval.attribute=create_atr(yylineno,yytext); return '+';}
"-"         {yylval.attribute=create_atr(yylineno,yytext); return '-';}
"*"         {yylval.attribute=create_atr(yylineno,yytext); return '*';}
"/"         {yylval.attribute=create_atr(yylineno,yytext); return '/';}
"%"         {yylval.attribute=create_atr(yylineno,yytext); return '%';}
"<"         {yylval.attribute=create_atr(yylineno,yytext); return '<';}
">"         {yylval.attribute=create_atr(yylineno,yytext); return '>';}
"<="        {yylval.attribute=create_atr(yylineno,yytext); return LE;}
">="        {yylval.attribute=create_atr(yylineno,yytext); return GE;}
"=="        {yylval.attribute=create_atr(yylineno,yytext); return EQ;}
"!="        {yylval.attribute=create_atr(yylineno,yytext); return NE;}
"="         {yylval.attribute=create_atr(yylineno,yytext); return '=';}
"!"         {yylval.attribute=create_atr(yylineno,yytext); return '!';}
"&&"        {yylval.attribute=create_atr(yylineno,yytext); return AND;}
"||"        {yylval.attribute=create_atr(yylineno,yytext); return OR;}
"("         {yylval.attribute=create_atr(yylineno,yytext); return '(';}
")"         {yylval.attribute=create_atr(yylineno,yytext); return ')';}
"{"         {yylval.attribute=create_atr(yylineno,yytext); return '{';}
"}"         {yylval.attribute=create_atr(yylineno,yytext); return '}';}
";"         {yylval.attribute=create_atr(yylineno,yytext); return ';';}
","         {yylval.attribute=create_atr(yylineno,yytext); return ',';}
{number}    {yylval.attribute=create_atr(yylineno,yytext); return NUMBER;}
{id}        {yylval.attribute=create_atr(yylineno,yytext); return ID;}

.           {lexer_general_error();}

%%
