#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <istream>
#include <fstream>
#include <sstream>


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

void check_if_keyword(std::string token) {
  token = remove_crap_symbols_for_keyword(token);
  
  for (int i=0; i < sizeof(keyword) / sizeof(*keyword); i++) {
    if (token.length() == 0) {
      return;
    }
    
    if (strcmp(keyword[i], token.c_str()) == 0) {
      std::cout << "keyword : " << token << ", " << " length: " << token.length() << "\n";
      return;
    }
  }
}

void check_if_type(std::string token) {
  for (int i=0; i < sizeof(type) / sizeof(*type); i++) {
    if (strcmp(type[i], token.c_str()) == 0) {
      std::cout << "type : " << token << ", " <<" length: " << token.length() <<"\n";
    } 
  }
}

void check_if_bracket(std::string token) {
  for (int i=0; i < sizeof(bracket) / sizeof(*bracket); i++) {
    if (strcmp(bracket[i], token.c_str()) == 0) {
      std::cout << "bracket : " << token << ", " <<" length: "<< token.length() <<"\n";
    }
  }
}

void analyze_source_code(std::string src_code) {
    std::string token = "";

    for (int i = 0; i < src_code.length(); i++) {
      if (isspace(src_code[i]) && token.length() != 0) {
	token = remove_crap_symbols(token);
	check_if_keyword(token);
	check_if_type(token);
	check_if_bracket(token);
	
	token = "";
      }
      
      token += src_code[i];
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

    analyze_source_code(src_code);
}
