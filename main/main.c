#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "../lexer/getfile.h"
int main(int argc, char *argv[]) {
  printf("Starting Interpreter...\n");
  ulong buffer_size = 256;
  char* text_in_file = malloc(buffer_size); 

  readFile(argv[1],&text_in_file, &buffer_size);

  printf("%s",text_in_file);
  return 0;
}
