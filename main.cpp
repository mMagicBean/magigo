#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <istream>
#include <fstream>
#include <sstream>
#include "tokenizer.h"
 

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
    
