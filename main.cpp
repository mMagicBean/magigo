#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <istream>
#include <fstream>
#include <sstream>
#include "tokenizer.h"
 

const char* keyword[] = {
  "break", "default", "func", "interface",
  "select", "case", "defer", "go", "map",
  "struct", "chan", "else", "goto", "package",
  "switch", "const", "fallthrough", "if", "range",
  "type", "continue", "for", "import", "return", "var"
};

const char* type[] = {
  "int8", "uint8", "byte", "int16", "uint16", "int32",
  "rune", "uint32", "int64", "uint64", "int", "uint", "uintptr",
  "float32", "float64", "complex64", "complex128"
};

const char* bracket[] = {
  "{", "}", "(", ")", "[", "]"
};

const char* integer[] = {
  "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"
};


std::string remove_crap_symbols(std::string token) {
  token.erase(std::remove(token.begin(), token.end(), '\n'), token.cend());
  token.erase(std::remove(token.begin(), token.end(), '\t'), token.cend());
  token.erase(std::remove(token.begin(), token.end(), ' '), token.cend());
  return token;
}
 
std::string remove_crap_symbols_for_keyword(std::string token) {
  token.erase(std::remove(token.begin(), token.end(), '}'), token.cend());
  token.erase(std::remove(token.begin(), token.end(), '{'), token.cend());  
  return token;
}

// NOTE: should i call tokens lexemes?
Token* check_if_keyword(std::string lexeme) {
  lexeme = remove_crap_symbols_for_keyword(lexeme);

  for (int i=0; i < sizeof(keyword) / sizeof(*keyword); i++) {
    if (lexeme.length() == 0) {
      return NULL;
    }
    
    if (strcmp(keyword[i], lexeme.c_str()) == 0) {
      Token* t = create_token(lexeme, "keyword");
      std::cout << "Token: " << t->name <<", id : " << t->token_id <<"\n";
      return t;
    }
  }
  
  return NULL;
}

Token* check_if_type(std::string lexeme) {
  Token* t = new Token;
  
  for (int i=0; i < sizeof(type) / sizeof(*type); i++) {
    if (lexeme.length() == 0) {
      return NULL;
    }
    
    if (strcmp(type[i], lexeme.c_str()) == 0) {
      Token* t = create_token(lexeme, "type");
      std::cout << "Token: " << t->name <<", id : " << t->token_id <<"\n";
      return t;
    } 
  }
  
  return NULL;
}

// NOTE: i might need to check whether the bracket is open or not 
Token* check_if_bracket(std::string lexeme) {
  for (int i=0; i < sizeof(bracket) / sizeof(*bracket); i++) {
    if (lexeme.length() == 0) {
      return NULL;
    }
    
    if (strcmp(bracket[i], lexeme.c_str()) == 0) {
      Token* t = create_token(lexeme, "bracket");
      std::cout << "Token: " << t->name <<", id : " << t->token_id <<"\n"; 
      return t;
    }
  }

  return NULL;
}

void tokenize_source_code(std::string src_code) {
  std::string lexeme = "";
  
  for (int i = 0; i < src_code.length(); i++) {
    if (isspace(src_code[i]) && lexeme.length() != 0) {
      lexeme = remove_crap_symbols(lexeme);
      check_if_keyword(lexeme);
      check_if_type(lexeme);
      check_if_bracket(lexeme);
	
      lexeme = "";
    }
      
    lexeme += src_code[i];
  }
}

// TODO: identify tokens in the accepted file
std::string read_source_file(std::string source_file) {
  std::ifstream file(source_file);
  std::stringstream buffer;

  buffer << file.rdbuf();

  return buffer.str();
}


int main(int argc, char* argv[]) {
  char* src_file = argv[1];

  std::string src_code = read_source_file(src_file);

  tokenize_source_code(src_code);
}
    
