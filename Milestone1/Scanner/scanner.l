%option noyywrap
%option c++


%{

    #include "types.hpp"

    int num_error = 0;
    int line_num = 1;

%}



/* regular expression */

delim                                   [ \t\r]
ws                                      {delim}+
letter                                  [A-Za-z]
letter_                                 [A-Za-z_]
digit                                   [0-9]
id                                      {letter_}({letter_}|{digit})*
number                                  {digit}+

%x COMMENT
%x STRING


%%

"//"                                    {BEGIN(COMMENT);}
<COMMENT>[^\r\n]                        {/* eats up the COMMENT */}
<COMMENT>[\r\n]                         {BEGIN(0);}
<COMMENT><<EOF>>                        {BEGIN(0);}

"\""                                    {BEGIN(STRING);}
<STRING>(\\.|[^"\\\r\r<<EOF>>])*        {scan_general(STRING);}
<STRING>"\""                            {BEGIN(0);}
<STRING>[\r\n]                          {string_error();}
<STRING><<EOF>>                         {string_error();}


\n                                      {++line_num;}
{ws}                                    {/* delete whitespaces */}

true

.               {ECHO;}

%%




int main(int argc, char *argv[])
{
    if(argc!=2)
    {
      std::cerr << "Usage: ./scanner <path to file>" << std::endl;
      exit(EXIT_FAILURE);
    }

    std::ifstream file_in(argv[1],std::ifstream::in);
    if(!file_in.is_open())
    {
      std::cerr << "Fail to open \""<< argv[1] << "\"" << std::endl;
      exit(EXIT_FAILURE);
    }

    FlexLexer* lexer = new yyFlexLexer(&file_in);
    while(lexer->yylex()!=0);
}
