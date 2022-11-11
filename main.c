#include <stdio.h>
#include <stdlib.h>


void lexer(char* source_file[]) {
  char c;
  FILE *fptr;

  if ((fptr = fopen(source_file, "r")) == NULL) {
    printf("Error opening file");
    exit(1);
  }

  int size = sizeof(source_file);

  for(int i=0; i < size; i++) {
    fscanf(fptr, "%c", &c);
    printf("%c", c);
  }
  
  //printf("value of c=%c", c);
  fclose(fptr);
}

int main(int argc, char* argv[]) {
  char* src_file = argv[1];

  lexer(src_file);
  
}
