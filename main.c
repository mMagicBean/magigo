#include <stdio.h>
#include <stdlib.h>


char *keyword[] = {
  "break", "default", "func", "interface",
  "select", "case", "defer", "go", "map",
  "struct", "chan", "else", "goto", "package",
  "switch", "const", "fallthrough", "if", "range",
  "type", "continue", "for", "import", "return", "var"
};

char *type[] = {
  "int8", "uint8", "byte", "int16", "uint16", "int32",
  "rune", "uint32", "int64", "uint64", "int", "uint", "uintptr",
  "float32", "float64", "complex64", "complex128"
};

char *bracket[] = {
  "{", "}", "(", ")", "[", "]"
};


void identify_token(char stream, int size) {
  // allocate memory for the incoming char stream
  char lexeme[];

  char lexeme[] += stream;

  printf("%s", lexeme);
}

// TODO: identify tokens in the accepted file
void lexer(char* source_file) {
  char c;
  FILE *fptr;
  
  if ((fptr = fopen(source_file, "r")) == NULL) {
    printf("Error opening file");
    exit(1);
  }
  
  // get total size of the file 
  fseek(fptr, 0, SEEK_END);
  int size = ftell(fptr);
  fseek(fptr, 0, SEEK_SET);
  
  printf("size of source_file = %d\n", size);
  
  for(int i=0; i < size; i++) {
    fscanf(fptr, "%c", &c);
    //printf("%c", c);
    identify_token(c);
  }
  
  fclose(fptr);
}


int main(int argc, char* argv[]) {
  char* src_file = argv[1];

  identify_token(src_file);
}
