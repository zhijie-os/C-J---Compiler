%option yywrap
%option c++


%{
    class Token{
    public:
        Type lexeme;
        std::string attribute;
        int line;

        Token(Type lex, const char* attr, int num)
        {
            lexeme = lex;
            attribute = attr;
            line = num;
        }
        
        ~Token() = default;
    };


    enum Type{
        ID=1,
        STRING,
        NUMBER, TRUE, FALSE, BOOLEAN, INT, VOID,
        IF, ELSE, WHILE, BREAK, RETURN,
        OP_ADD, OP_SUB, OP_MUL, OP_DIV, OP_MOD,
        OP_LT, OP_GT, OP_LE, OP_GE, OP_EQ, OP_NE,
        OP_ASSIGN,
        OP_NOT, OP_AND, OP_OR,
        L_PAR, R_PAR, L_BRA, R_BRA,
        SMCOL, COMMA,
    };    


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

"//"                                    {BEGIN(STRING);}
<STRING>(\\.|[^"\\\r\r<<EOF>>])*        {scan_string();}
<STRING>"\""                            {BEGIN(0);}
<STRING>[\r\n]                          {string_error();}
<STRING><<EOF>>                         {string_error();}

.      {ECHO;}

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

void scan_reserved()
{

}


int main(int argc, char *argv[])
{

}
