#pragma once

#include "tokenizer.h"
#include <string>
#include <vector>

struct AST_Node {
  int value;
  
  AST_Node* right = nullptr;
  AST_Node* left = nullptr;
};

AST_Node* create_ast_node(AST_Node* ast, AST_Node* lnode = nullptr,
			  AST_Node* rnode = nullptr);
void parse_tokens(AST_Node* ast, std::vector<Token*> tokens); 

