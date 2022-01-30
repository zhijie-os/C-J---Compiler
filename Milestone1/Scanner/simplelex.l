%option c++
%option noyywrap



%{
  #include <fstream>
%}



%%
. {std::cout << YYText();}

%%

int main(int argc, char *argv[])
{

    std::ifstream file_in(argv[1],std::ifstream::in);

    FlexLexer* lexer = new yyFlexLexer(&file_in);
    while(lexer->yylex()!=0);
}
