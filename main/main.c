#include "../lexer/lexer.h"
#include "../lexer/readfile.h"
#include "../lexer/tokens.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
  printf("Starting Interpreter...\n");
  unsigned long buffer_size = 256;
  char *text_in_file = malloc(buffer_size);
  text_in_file[0] = '\0';

  readFile(argv[1], &text_in_file, &buffer_size);

  Token *tokens = tokenize(text_in_file);
  free(text_in_file);

  return 0;
}
