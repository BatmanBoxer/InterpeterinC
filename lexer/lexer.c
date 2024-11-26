#include "tokens.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *global_texts;
int texts_count = 0;
int text_size;

char *peak(int i);
char *consume(int i);

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

  while (peak(0) != NULL) {
    token_count += 1;

    // reallcating memory to array because C is ancient and doesn`t have a
    // wapper for mutable array
    if (size_of_tokens <= token_count) {
      size_of_tokens *= 2;
      Token *temp = realloc(tokens, sizeof(Token) * size_of_tokens);

      if (temp == NULL) {
        free(tokens);
        perror("Assigining Memory to Heap failed");
        exit(1);
      }
      tokens = temp;
    }
    printf("%c", *consume(0));
  }
  // I am lazy to setup a debugger so here is the solution just print it simple
  //printf("text count is %d", texts_count);
  //printf("text size is %d", text_size);
  return tokens;
}

char *peak(int i) {
  char *text;
  if (texts_count + 1 > text_size) {
    printf("reached here");
    return NULL;
  }
  return &global_texts[texts_count + i];
}

char *consume(int i) {
  char *text;
  if (texts_count + 1 > text_size) {
    printf("reached here");
    return NULL;
  }
  char *temp = &global_texts[texts_count + i];
  texts_count++;
  return temp;
}
