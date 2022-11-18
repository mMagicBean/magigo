#pragma once

#include "tokenizer.h"
#include <string>
#include <vector>


struct AST {
  
  
};


void parse_statement(std::vector<Token*> tokens);
void assign(std::string a, std::string b);
void ret(Token* token);
