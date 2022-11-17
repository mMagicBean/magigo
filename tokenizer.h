#pragma once

#include <string>

struct Token {
  std::string name;
  std::string token_id;
};

Token* create_token(std::string name, std::string id);
