
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
  int size_of_tokens = 256;
  int size_of_text = strlen(texts);
  text_size = size_of_text;
  int token_count = 0;

  Token *tokens = malloc(sizeof(Token) * size_of_tokens);

  char buff[256];
  buff[0]='\0';
  int buff_counter = 0;

  while (peak(0) != NULL) {
    // Reallocating tokens array cause no mutable array
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
      while (isalnum(*peak(0))) {
        ch = *consume();
        buff[buff_counter] = ch;
        buff_counter++;
      }
      buff[buff_counter] = '\0';
      // just sad that we cannot compare string in switch
      if (strcmp(buff, "return") == 0) {
        tokens[token_count].tokenType = RETURN;
      } else if (strcmp(buff, "fun")== 0) {
        tokens[token_count].tokenType = FUN;
      } else if (strcmp(buff, "var")== 0) {
        tokens[token_count].tokenType = VAR;
      } else if (strcmp(buff, "const")== 0) {
        tokens[token_count].tokenType = CONST;
      } else if (strcmp(buff, "continue")== 0) {
        tokens[token_count].tokenType = CONTINUE;
      } else if (strcmp(buff, "break")== 0) {
        tokens[token_count].tokenType = BREAK;
      } else if (strcmp(buff, "int")== 0) {
        tokens[token_count].tokenType = INT;
      } else if (strcmp(buff, "string")== 0) {
        tokens[token_count].tokenType = STRING;
      } else if (strcmp(buff, "print")== 0) {
        tokens[token_count].tokenType = PRINT;
      } else if (strcmp(buff, "println")== 0) {
        tokens[token_count].tokenType = PRINTLN;
      } else if (strcmp(buff, "if")== 0) {
        tokens[token_count].tokenType = IF;
      } else if (strcmp(buff, "else")== 0) {
        tokens[token_count].tokenType = ELSE;
      } else if (strcmp(buff, "while")== 0) {
        tokens[token_count].tokenType = WHILE;
      } else if (strcmp(buff, "for")== 0) {
        tokens[token_count].tokenType = FOR;
      } else {
        tokens[token_count].tokenType = STRING;
        tokens[token_count].value = malloc(sizeof(strlen(buff)+1));
        tokens[token_count].value[0] = '\0';
        strcat(tokens[token_count].value, buff);
      }
      buff_counter = 0;
      token_count = token_count + 1;
    } else if (*peak(0) == ' ' || *peak(0) == '\n') {
      consume();
      continue;
    } else if (isdigit(*peak(0))) {
      while (isdigit(*peak(0))) {
        char ch = *consume();
        buff[buff_counter] = ch;
        buff_counter++;
      }

      buff[buff_counter] = '\0';

      tokens[token_count].tokenType = INT;
      strcat(tokens[token_count].value, buff);
      buff_counter = 0;

    } else if (*peak(0) == '"') {
      consume();
      tokens[token_count].tokenType = DOUBLEQUOTES;
      token_count++;
    } else if (*peak(0) == '(') {
      consume();
      tokens[token_count].tokenType = LEFTBRACKET;
      token_count++;

    } else if (*peak(0) == ')') {
      consume();
      tokens[token_count].tokenType = RIGHTBRACKET;
      token_count++;

    } else if (*peak(0) == '{') {
      consume();
      tokens[token_count].tokenType = LEFTPARAMS;
      token_count++;

    } else if (*peak(0) == '}') {
      consume();
      tokens[token_count].tokenType = RIGHTPARAMS;
      token_count++;

    } else if (*peak(0) == ';') {
      consume();
      tokens[token_count].tokenType = SEMICOLON;
      token_count++;

    } else if (*peak(0) == '+') {
      consume();
      tokens[token_count].tokenType = PLUS;
      token_count++;

    } else if (*peak(0) == '-') {
      consume();
      tokens[token_count].tokenType = MINUS;
      token_count++;

    } else if (*peak(0) == '*') {
      consume();
      tokens[token_count].tokenType = MUNIPLY;
      token_count++;

    } else if (*peak(0) == '/') {
      consume();
      tokens[token_count].tokenType = DIVIDE;
      token_count++;

    } else if (*peak(0) == '=') {
      consume();
      tokens[token_count].tokenType = EQUALS;
      token_count++;

    } else if (*peak(0) == '!') {
      consume();
      tokens[token_count].tokenType = NOT;
      token_count++;

    } else {
      printf("reached here ");
      consume();
      continue;
    }
  }
  buff[buff_counter] = '\0';
  printf("%s\n", buff);
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

