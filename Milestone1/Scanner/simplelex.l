%option c++
%option noyywrap



%{

%}



%%
. {std::cout << YYText();}

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
