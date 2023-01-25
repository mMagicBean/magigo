#include "parser.h"
#include <iostream>
#include <cstdlib>


AST_Node* create_node() {
  AST_Node* _node = (AST_Node*) malloc(sizeof(AST_Node));
  
  _node->right = 0;
  _node->left  = 0;

  return _node;
}


void parse_tokens(std::vector<Token*> tokens) {
  AST_Node* root_node   = create_node(); 
  AST_Node* first_node  = create_node();
  AST_Node* second_node = create_node();
  
  AST_Node* nodes[3] = {root_node, first_node, second_node};
  
  for (int i=0; i < tokens.size(); i++) {
    if (tokens[i]->id == "operator") {
      if (tokens[i-1]->id == "integer_literal" && tokens[i+1]->id == "integer_literal") {
	
	root_node->value = tokens[i]->value;     // *
	first_node->value = tokens[i-1]->value;  // 2
	second_node->value = tokens[i+1]->value; // 3
	
	root_node->left = first_node;           // * -> 2
	root_node->right = second_node;         // |
	                                        //  --> 3
      }
    } else {
      continue;
    }	 
  }
   
  std::cout << "root_node: "<< root_node->value << "first_node: " << first_node->value << "second_node: " << second_node->value << "\n";
}


/*
void parse_statement(std::vector<Token*> tokens) {
  //std::cout << tokens[3]->name << "\n"; 
  
  if (tokens[0]->id != "keyword") {
    std::cout << "Error: NO KEYWORD" << "\n";
  } else {
    std::cout << "KEYWORD PRESENT!" << "\n";
  }
  
  if (tokens[1]->id != "keyword") {
    std::cout << "Error: NO KEYWORD" << "\n";
  } else {
    std::cout << "KEYWORD PRESENT!" << "\n";
  }

  if (tokens[2]->id != "open_bracket") {
    std::cout << "Error: Function missing open bracket" << "\n";
  } else {
    std::cout << "KEYWORD PRESENT!" << "\n";
  }
  
  if (tokens[3]->name != "return" && tokens[3]->id != "keyword") {
    std::cout << "main function is not void" << "\n";
  } else {
    std::cout << "RETURN PRESENT!" << "\n";
  }
}


void convert_operator_token(std::string op, int& a, int& b) {
  if (op == "+") {
    
  }
}
*/
