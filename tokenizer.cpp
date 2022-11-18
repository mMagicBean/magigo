#include "tokenizer.h"
#include <iostream>


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

const char* open_bracket[] = {
  "{", "(", "[", 
};

const char* closed_bracket[] = {
  "}", ")", "]"
};

const char* integer[] = {
  "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"
};

const char* operators[] = {
  "=", "+", "-", "*", "/", "++", "+=", "--", "-=", "%" 
};


// the token returned from here is gonna be appended
// to an array or some other data structure i write in
// the future
Token* create_token(std::string name, std::string id, int val) {
  Token* t = new Token;
 
  t->name = name;
  t->token_id = id;
  t->val = val;

  std::cout << "Token: " << name << ", id : " << id << ", val : "<< val <<"\n";
  
  return t;
}

Token* check_if_keyword(std::string lexeme) {
  lexeme = remove_crap_symbols_for_keyword(lexeme);

  for (int i=0; i < sizeof(keyword) / sizeof(*keyword); i++) {
    if (lexeme.length() == 0) {
      return NULL;
    }
    
    if (strcmp(keyword[i], lexeme.c_str()) == 0) {
      Token* t = create_token(lexeme, "keyword", NULL);
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
      Token* t = create_token(lexeme, "type", NULL);
      return t;
    } 
  }
  
  return NULL;
}


Token* check_if_open_bracket(std::string lexeme) {
  for (int i=0; i < sizeof(open_bracket) / sizeof(*open_bracket); i++) {
    if (lexeme.length() == 0) {
      return NULL;
    }

    if (strcmp(open_bracket[i], lexeme.c_str()) == 0) {
      Token* t = create_token(lexeme, "open_bracket", NULL);
      return t;
    }
  }

  return NULL;
}


// NOTE: i might need to check whether the bracket is open or not 
Token* check_if_closed_bracket(std::string lexeme) {
  for (int i=0; i < sizeof(closed_bracket) / sizeof(*closed_bracket); i++) {
    if (lexeme.length() == 0) {
      return NULL;
    }
    
    if (strcmp(closed_bracket[i], lexeme.c_str()) == 0) {
      Token* t = create_token(lexeme, "bracket", NULL);
      return t;
    }
  }

  return NULL;
}

Token* check_if_operator(std::string lexeme) {
  // TODO: for increment/decrement operators i need to exclude the
  // identifier that comes before, i'll do dat later doe... 
  for (int i=0; i < sizeof(operators) / sizeof(*operators); i++) {
    if (lexeme.length() == 0) {
      return NULL;
    }

    if (strcmp(operators[i], lexeme.c_str()) == 0) {
      Token* t = create_token(lexeme, "operator", NULL);
      return t;
    }
  }
  
  return NULL;
}

Token* check_if_int_literal(std::string lexeme) {
  for (int i=0; i < sizeof(integer) / sizeof(*integer); i++) {
    if (lexeme.length() == 0) {
      return NULL;
    }

    if (strcmp(integer[i], lexeme.c_str()) == 0) {
      Token* t = create_token(lexeme, "integer_literal", atoi(lexeme.c_str()));
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
      check_if_open_bracket(lexeme);
      check_if_closed_bracket(lexeme);
      check_if_operator(lexeme);
      check_if_int_literal(lexeme);
      
      lexeme = ""; // reset lexeme
    }
      
    lexeme += src_code[i];
  }
}

std::string remove_crap_symbols(std::string lexeme) {
  lexeme.erase(std::remove(lexeme.begin(), lexeme.end(), '\n'), lexeme.cend());
  lexeme.erase(std::remove(lexeme.begin(), lexeme.end(), '\t'), lexeme.cend());
  lexeme.erase(std::remove(lexeme.begin(), lexeme.end(), ' '), lexeme.cend());
  return lexeme;
}
 
std::string remove_crap_symbols_for_keyword(std::string lexeme) {
  lexeme.erase(std::remove(lexeme.begin(), lexeme.end(), '}'), lexeme.cend());
  lexeme.erase(std::remove(lexeme.begin(), lexeme.end(), '{'), lexeme.cend());  
  return lexeme;
}
