#include "tokens.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *global_texts;
int texts_count = 0;
int text_size;

char *peak(int i);
char *consume();

Token *tokenize(char *texts) {
  global_texts = texts;
  printf("Tokenizing...\n");
  int size_of_tokens = 1;
  int size_of_text = strlen(texts);
  text_size = size_of_text;
  int token_count = 0;

  Token *tokens = malloc(sizeof(Token) * size_of_tokens);

  tokens[0].value = "batman";
  tokens[0].tokenType = STRING;

  char buff[256] = {0}; // Initialize buffer to zero
  int buff_counter = 0;

  while (peak(0) != NULL) {
    // Reallocating tokens array if necessary
    if (size_of_tokens <= token_count) {
      size_of_tokens *= 2;
      Token *temp = realloc(tokens, sizeof(Token) * size_of_tokens);
      if (temp == NULL) {
        free(tokens);
        perror("Memory allocation failed during reallocation");
        exit(1);
      }
      tokens = temp;
    }

    if (isalpha(*peak(0))) {
      char ch = *consume();
      buff[buff_counter] = ch;
      buff_counter++;
    } else {
      consume();
    }
  }
  buff[buff_counter] = '\0';
  printf("%s\n",buff);
  if (strcmp("fundarwinvariintprinti",buff) == 0) {
    printf("true");
  } else {
    printf("flase");
  }
  return tokens;
}

char *peak(int i) {
  char *text;
  if (texts_count + 1 > text_size) {
    return NULL;
  }
  return &global_texts[texts_count + i];
}

char *consume() {
  char *text;
  if (texts_count + 1 > text_size) {
    return NULL;
  }
  char *temp = &global_texts[texts_count];
  texts_count++;
  return temp;
}
