#include "parser.h"
#include <iostream>


void assign(std::string a, std::string b) {
  
}

void parse_statement(std::vector<Token*> tokens) {
  std::cout << tokens[3]->name << "\n"; 
  
  if (tokens[0]->token_id != "keyword") {
    std::cout << "Error: NO KEYWORD" << "\n";
  } else {
    std::cout << "KEYWORD PRESENT!" << "\n";
  }
  
  if (tokens[1]->token_id != "keyword") {
    std::cout << "Error: NO KEYWORD" << "\n";
  } else {
    std::cout << "KEYWORD PRESENT!" << "\n";
  }

  if (tokens[2]->token_id != "open_bracket") {
    std::cout << "Error: Function missing open bracket" << "\n";
  } else {
    std::cout << "KEYWORD PRESENT!" << "\n";
  }
  
  if (tokens[3]->name != "return" && tokens[3]->token_id != "keyword") {
    std::cout << "main function is not void" << "\n";
  } else {
    std::cout << "RETURN PRESENT!" << "\n";
  }

  //if (token[4]->token_id != 
}
