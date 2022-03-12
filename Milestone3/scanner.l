%option c++
%option yylineno
%option noyywrap


%{
    #include <iostream>  
    #include "main.h"
    int num_lexer_error=0; 
    #define pprint(x) pretty_print(x,YYText(),lineno());
%}


%x COMMENT_
%x STRING_

/* regular definition */


delim   [ \t\r]
ws      {delim}+
letter  [A-Za-z]
letter_ [A-Za-z_]
digit   [0-9]
id      {letter_}({letter_}|{digit})*
number  {digit}+
 


%%

"\""                                                {BEGIN(STRING_);}
<STRING_>(\\[bftrn'"\\]|[^"\\\r\n<<EOF>>])*          {pprint("STRING");}
<STRING_>"\""                                        {BEGIN(0);}
<STRING_>\\[^bftrn'"\\]                              {lexer_string_error("unsupported escape character",lineno());}
<STRING_>\n                                          {lexer_string_error("newline in string literal",lineno());}
<STRING_>\r                                          {lexer_string_error("return in string literal",lineno());}
<STRING_><<EOF>>                                     {lexer_string_error("string missing closing quote",lineno());}


"//"                                                {BEGIN(COMMENT_);}
<COMMENT_>[^\r\n]                                    {/* eats up the comment */};
<COMMENT_>\n                                         {BEGIN(0);}


\n          {}
{ws}        {/* ignore whitespaces */}
true        {pprint("TRUE");}
false       {pprint("FALSE");}
boolean     {pprint("BOOLEAN");}
int         {pprint("INT");}
void        {pprint("VOID");}
if          {pprint("IF");}
else        {pprint("ELSE");}
while       {pprint("WHILE");}
break       {pprint("BREAK");}
return      {pprint("RETURN");}
"+"         {pprint("+");}
"-"         {pprint("-");}
"*"         {pprint("*");}
"/"         {pprint("/");}
"%"         {pprint("%");}
"<"         {pprint("<");}
">"         {pprint(">");}
"<="        {pprint("<=");}
">="        {pprint(">=");}
"=="        {pprint("==");}
"!="        {pprint("!=");}
"="         {pprint("=");}
"!"         {pprint("!");}
"&&"        {pprint("&&");}
"||"        {pprint("||");}
"("         {pprint("(");}
")"         {pprint(")");}
"{"         {pprint("{");}
"}"         {pprint("}");}
";"         {pprint(";");}
","         {pprint(",");}
{number}    {pprint("NUMBER");}
{id}        {pprint("ID");}



.           {lexer_general_error(lineno());}


%%

