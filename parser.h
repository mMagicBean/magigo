#pragma once

#include "tokenizer.h"
#include <string>
#include <vector>

struct AST_Node {
  int value;
  
  AST_Node* right;
  AST_Node* left;
  AST_Node* parent;
};

struct AST {
  AST_Node* nodes;
};
  
AST_Node* create_node();
void destroy_node(AST_Node* node);
AST_Node* parse_expressions(std::vector<Token*> tokens, int index);
void parse_tokens(std::vector<Token*> tokens); 
void traverse_nodes(AST_Node* rnode);

