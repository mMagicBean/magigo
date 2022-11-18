#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <istream>
#include <fstream>
#include <sstream>
#include "tokenizer.h"
#include "parser.h" 


std::string read_source_file(std::string source_file) {
  std::ifstream file(source_file);
  std::stringstream buffer;

  buffer << file.rdbuf();

  return buffer.str();
}


int main(int argc, char* argv[]) {
  char* src_file = argv[1];

  std::string src_code = read_source_file(src_file);

  std::vector<Token*> tokens = tokenize_source_code(src_code);
  
  parse_statement(tokens);
}
    
