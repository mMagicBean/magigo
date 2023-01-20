#include "parser.h"
#include <iostream>


AST_Node* create_ast_node(int value, AST_Node* lnode = nullptr,
			  AST_Node* rnode = nullptr) {
  ast->value = value;
  
  return ast;
}


void parse_tokens(AST_Node* ast, std::vector<Token*> tokens) {
  for (int i=0; i < tokens.size(); i++) {
    if (tokens[i]->id == "operator") {
      //create_ast_node(ast, tokens[i]->val)
    }
  }
}
 
void parse_statement(std::vector<Token*> tokens) {
  std::cout << tokens[3]->name << "\n"; 
  
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


