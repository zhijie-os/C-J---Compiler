%option yywrap
%option c++


%{


    int num_error = 0;
    int line_num = 1;

    std::vector<Token> tokens;
%}

%x COMMENT
%x STRING

/* regular expression */

delim                                   [ \t\r]
ws                                      {delim}+
letter                                  [A-Za-z]
letter_                                 [A-Za-z_]
digit                                   [0-9]
id                                      {letter_}({letter_}|{digit})*
number                                  {digit}+

%%

"//"                                    {BEGIN(COMMENT);}
<COMMENT>[^\r\n]                        {/* eats up the comment */}
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

}
