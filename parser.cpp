#include "parser.h"
#include <iostream>
#include <cstdlib>


AST_Node* create_node() {
  AST_Node* _node = (AST_Node*) malloc(sizeof(AST_Node));

  if (_node) {
    _node->value  = 0;
    _node->right  = nullptr;
    _node->left   = nullptr;
    _node->parent = nullptr;
    
    return _node;
  } else {
    return nullptr;
  }
}

void destroy_node(AST_Node* node) {
  node->value  = NULL;
  node->right  = NULL;
  node->left   = NULL;
  node->parent = NULL;
  
  free(node);
}

AST_Node* parse_expressions(std::vector<Token*> tokens, int index) {
  if (tokens[index-1]->id == "integer_literal" && tokens[index+1]->id == "integer_literal") {
    AST_Node* node1 = create_node();
    AST_Node* node2 = create_node();
    AST_Node* node3 = create_node();

    node1->value = tokens[index]->value;
    node2->value = tokens[index-1]->value;
    node3->value = tokens[index+1]->value;

    node1->left  = node2;
    node1->right = node3;

    node2->parent = node1;
    node3->parent = node1;
    
    std::cout << "root_node: "<< node1->value << "first_node: " << node2->value << "second_node: " << node3->value << "\n";

    return node1;
  }
  
  return nullptr;
}

void parse_tokens(std::vector<Token*> tokens) {
  for (int i=0; i < tokens.size(); i++) {
    if (tokens[i]->id == "operator" && tokens[i]->name == "*") {
      parse_expressions(tokens, i);
    }
  }
}

void traverse_nodes(AST_Node* node) {
  bool is_traversing = true;

  AST_Node* curr_node = create_node();
  AST_Node* next_node = node;

  while(is_traversing) {
    if (next_node->left != nullptr) {
      next_node = next_node->left;
    }

    if (next_node->left == nullptr) {
      next_node = next_node->parent;
      
      if (next_node->right != nullptr) {
	next_node = next_node->right;
		
	if (next_node->right == nullptr) {
	  is_traversing = false;
	}
      }
    }
  }
}
