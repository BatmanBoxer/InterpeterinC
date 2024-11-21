#include "../lexer/lexer.h"
#include "../lexer/tokens.h"
#include <stdio.h>
int main() {
  printf("this is start\n");
  Token tokens = tokenize();
  if (tokens.tokenType == RETURN) {
    printf("return");
  }
}
