%option noyywrap yylineno outfile="scanner.flex.cpp"

%{
    #include "AST.h"
    #include "parser.h"
    #include "parser.bison.h"

    int num_lexer_error=0;

%}



%x COMMENT
%x STRING_L

/* regular definition */


delim   [ \t\r]
ws      {delim}+
letter  [A-Za-z]
letter_ [A-Za-z_]
digit   [0-9]
id      {letter_}({letter_}|{digit})*
number  {digit}+
 


%% 

"\""                                                    {BEGIN(STRING_L);}
<STRING_L>(\\[bftrn'"\\]|[^"\\\r\n<<EOF>>])*          {yylval=new AST(NodeType::STRING,yytext,yylineno); return STRING_Y;}
<STRING_L>"\""                                        {BEGIN(0);}
<STRING_L>\\[^bftrn'"\\]                              {lexer_string_error("unsupported escape character");}
<STRING_L>\n                                          {lexer_string_error("newline in string literal");}
<STRING_L>\r                                          {lexer_string_error("return in string literal");}
<STRING_L><<EOF>>                                     {lexer_string_error("string missing closing quote");}


"//"                                                  {BEGIN(COMMENT);}
<COMMENT>[^\r\n]                                      {/* eats up the comment */};
<COMMENT>\n                                           {BEGIN(0);}



\n          {}
{ws}        {/* ignore whitespaces */}
true        {yylval=new AST(NodeType::TRUE, "true",yylineno); return TRUE;}
false       {yylval=new AST(NodeType::FALSE, "false",yylineno); return FALSE;}
boolean     {yylval=new AST(NodeType::BOOLEAN, "bool",yylineno); return BOOLEAN;}
int         {yylval=new AST(NodeType::INT, "int",yylineno); return INT;}
void        {yylval=new AST(NodeType::VOID, "void",yylineno); return VOID;}
if          {return IF;}
else        {return ELSE;}
while       {return WHILE;}
break       {yylval=new AST(NodeType::BREAK, "break",yylineno); return BREAK;}
return      {yylval=new AST(NodeType::RETURN, "return",yylineno); return RETURN;}
"+"         {return '+';}
"-"         {return '-';}
"*"         {return '*';}
"/"         {return '/';}
"%"         {return '%';}
"<"         {return '<';}
">"         {return '>';}
"<="        {return LE;}
">="        {return GE;}
"=="        {return EQ;}
"!="        {return NE;}
"="         {return '=';}
"!"         {return '!';}
"&&"        {return AND;}
"||"        {return OR;}
"("         {return '(';}
")"         {return ')';}
"{"         {return '{';}
"}"         {return '}';}
";"         {return ';';}
","         {return ',';}
{number}    {yylval=new AST(NodeType::NUMBER, yytext, yylineno); return NUMBER;}
{id}        {yylval=new AST(NodeType::IDENTIFIER,yytext, yylineno); return ID;}

.           {lexer_general_error();}

%%
