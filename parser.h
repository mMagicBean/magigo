#pragma once

#include "tokenizer.h"
#include <string>
#include <vector>

struct AST_Node {
  int value = 0;
  
  AST_Node* right = nullptr;
  AST_Node* left  = nullptr;
};

AST_Node* create_node();
void parse_tokens(std::vector<Token*> tokens); 
