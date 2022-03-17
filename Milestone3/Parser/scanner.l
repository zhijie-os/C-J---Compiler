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

"\""                                                  {BEGIN(STRING_L);}
<STRING_L>(\\[bftrn'"\\]|[^"\\\r\n])*                 {yylval=new AST(NodeType::STRING, "string" ,new ATR(yylineno,yytext)); return STRING_Y;}
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
true        {yylval=new AST(NodeType::TRUE, "true",new ATR(yylineno)); return TRUE;}
false       {yylval=new AST(NodeType::FALSE, "false",new ATR(yylineno)); return FALSE;}
boolean     {yylval=new AST(NodeType::BOOLEAN, "bool",new ATR(yylineno)); return BOOLEAN;}
int         {yylval=new AST(NodeType::INT, "int",new ATR(yylineno)); return INT;}
void        {yylval=new AST(NodeType::VOID, "void",new ATR(yylineno)); return VOID;}
if          {yylval=new AST(NodeType::IF,"while", new ATR(yylineno)); return IF;}
else        {yylval=new AST(NodeType::IF_ELSE,"while", new ATR(yylineno)); return ELSE;}
while       {yylval=new AST(NodeType::WHILE,"while", new ATR(yylineno));return WHILE;}
break       {yylval=new AST(NodeType::BREAK, "break",new ATR(yylineno)); return BREAK;}
return      {yylval=new AST(NodeType::RETURN, "return",new ATR(yylineno)); return RETURN;}
"+"         {yylval=new AST(NodeType::BIN_ARITHMETIC,"+", new ATR(yylineno));return '+';}
"-"         {yylval=new AST(NodeType::BIN_ARITHMETIC,"-", new ATR(yylineno));return '-';}
"*"         {yylval=new AST(NodeType::BIN_ARITHMETIC,"*", new ATR(yylineno));return '*';}
"/"         {yylval=new AST(NodeType::BIN_ARITHMETIC,"/", new ATR(yylineno));return '/';}
"%"         {yylval=new AST(NodeType::BIN_ARITHMETIC,"%", new ATR(yylineno));return '%';}
"<"         {yylval=new AST(NodeType::BIN_RELATION,"<", new ATR(yylineno));return '<';}
">"         {yylval=new AST(NodeType::BIN_RELATION,">", new ATR(yylineno));return '>';}
"<="        {yylval=new AST(NodeType::BIN_RELATION,"<=", new ATR(yylineno));return LE;}
">="        {yylval=new AST(NodeType::BIN_RELATION,">=", new ATR(yylineno));return GE;}
"=="        {yylval=new AST(NodeType::BIN_RELATION,"==", new ATR(yylineno));return EQ;}
"!="        {yylval=new AST(NodeType::BIN_RELATION,"!=", new ATR(yylineno));return NE;}
"="         {yylval=new AST(NodeType::ASSIGN,"=", new ATR(yylineno));return '=';}
"!"         {yylval=new AST(NodeType::UN_LOGIC,"!", new ATR(yylineno));return '!';}
"&&"        {yylval=new AST(NodeType::BIN_LOGIC,"&&", new ATR(yylineno));return AND;}
"||"        {yylval=new AST(NodeType::BIN_LOGIC,"||", new ATR(yylineno));return OR;}
"("         {return '(';}
")"         {return ')';}
"{"         {return '{';}
"}"         {return '}';}
";"         {return ';';}
","         {return ',';}
{number}    {yylval=new AST(NodeType::NUMBER,"number", new ATR(yylineno,yytext)); return NUMBER;}
{id}        {yylval=new AST(NodeType::IDENTIFIER, "identifier",new ATR(yylineno,yytext)); return ID;}

.           {lexer_general_error();}

%%
