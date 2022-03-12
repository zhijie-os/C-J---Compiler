#pragma once
#include <iostream>
#include <fstream>
#include <string>

void lexer_string_error(std::string info, int line_num);
void lexer_general_error(int line_num);
void pretty_print(std::string attr,std::string lexeme, int line_num);

extern int num_lexer_error;