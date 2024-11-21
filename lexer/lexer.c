#include "tokens.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Token tokenize() {

  printf("this is tokenize\n");
  Token token;

  token.value = "batman";
  token.tokenType = STRING;

  return token;
}
