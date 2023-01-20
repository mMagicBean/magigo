#pragma once

#include <string>
#include <vector>

struct Token {
  std::string name;
  std::string id;
  int value;
  bool is_term;
};

Token* create_token(std::string name, std::string id, int val);
Token* check_if_keyword(std::string lexeme);
Token* check_if_type(std::string lexeme);
Token* check_if_bracket(std::string lexeme);
Token* check_if_operator(std::string lexeme);
std::vector<Token*> generate_tokens(std::string src_code);
std::string remove_crap_symbols(std::string lexeme);
std::string remove_crap_symbols_for_keyword(std::string lexeme);

