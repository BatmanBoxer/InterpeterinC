#include "tokens.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Token *tokenize(char *texts) {
  printf("Tokenizing...\n");
  int size_of_tokens = 1;
  int size_of_text = strlen(texts);
  int token_count = 0;

  Token *tokens = malloc(sizeof(Token) * size_of_tokens);

  tokens[0].value = "batman";
  tokens[0].tokenType = STRING;

  for (int i = 0; i < size_of_text; i++) {
    token_count += 1;

    if (size_of_tokens <= token_count) {
      size_of_tokens *= 2;
      Token *temp = realloc(tokens, sizeof(Token) * size_of_tokens);

      if(temp == NULL){
        free(tokens);
        perror("Assigining Memory to Heap failed");
        exit(1);
      }

      tokens = temp;
    }

    printf("%c", texts[i]);
  }

  return tokens;
}
