#include "tokenizer.h"


void deduce_vals(std::string lval) {
  
}

// the token returned from here is gonna be appended
// to an array or some other data structure i write in
// the future
Token* create_token(std::string name, std::string id) {
  Token* t = new Token;
 
  t->name = name;
  t->token_id = id;
  
  return t;
}
  
