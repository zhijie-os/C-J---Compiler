#include <iostream>
#include "main.h"
#include <FlexLexer.h>

void pretty_print(std::string attr,std::string lexeme, int line_num)
{
    std::cout << attr << ", " << lexeme << ", " << line_num <<std::endl;
}

// scanner counters an error in string which is unrecoverable, abort.
void lexer_string_error(std::string info, int line_num)
{
    std::cerr << "error: " << info <<  "at or near line " << line_num << std::endl;
    exit(EXIT_FAILURE);
}

// scanner counters an error, ignore if the total number of errors is acceptable; otherwise, abort;
void lexer_general_error(int line_num)
{
    std::cerr<<"warning: ignoring bad character at or near line " << line_num << std::endl;
    num_lexer_error++;
    if (num_lexer_error >= 10)
    {
        std::cerr <<"Too many errors, abort...."<<std::endl;
        exit(EXIT_FAILURE);
    }
}




int main(int argc, char **argv)
{
    FlexLexer* l = new yyFlexLexer(std::cin, std::cerr);
    l->yylex();
    delete l;
    return 0;
}