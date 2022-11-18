#pragma once

#include <string>

struct Token {
  std::string name;
  std::string token_id;
  int val;
};


Token* create_token(std::string name, std::string id, int val);
Token* check_if_keyword(std::string lexeme);
Token* check_if_type(std::string lexeme);
Token* check_if_bracket(std::string lexeme);
Token* check_if_operator(std::string lexeme);
void tokenize_source_code(std::string src_code);
std::string remove_crap_symbols(std::string lexeme);
std::string remove_crap_symbols_for_keyword(std::string lexeme);



