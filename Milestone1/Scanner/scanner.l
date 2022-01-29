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
<STRING>(\\.|[^"\\\r\r<<EOF>>])*        {scan_string();}
<STRING>"\""                            {BEGIN(0);}
<STRING>[\r\n]                          {string_error();}
<STRING><<EOF>>                         {string_error();}


\n                                      {++line_num;}
{ws}                                    {/* delete whitespaces */}

true

.               {ECHO;}

%%

void error()
{
    std::cerr << "warning: ignoring bad character at or near line " << line_num << std::endl;
    num_error++;
    if(num_error>=10)
    {
        std::cerr << "Too many errors... Abort... << std::endl;
        exit(FAIL_FAILURE);
    }
}

void string_error()
{
    std::cerr << "error: string missing closing quote at or near line " << line_num << std::endl;
    exit(FAIL_FAILURE);
}


void scan_string()
{
    tokens.push_back(Token(STRING,yytext,line_num));
}

void scan_reserved(Type type)
{

}


int main(int argc, char *argv[])
{

}
