#ifndef TOKENS_H
#define TOKENS_H
#include <stdlib.h>

typedef enum {
  RETURN,
  LET,
  CONST,
  VAR,
  IF,
  ELSE,
  FOR,
  WHILE,
  BREAK,
  CONTINUE,
  FUN,

  INT,
  STRING,
  BOOL,
  ARRAY,

  LEFTPARAMS,
  RIGHTPARAMS,
  LEFTBRACKET,
  RIGHTBRACKET,
  SEMICOLON,
  DOUBLEQUOTES,

  PLUS,
  MINUS,
  DIVIDE,
  MUNIPLY,

  GREATER,
  SMALLER,
  EQUALS,
  NOT,

  INDENTIFIER,
  TOKEN_EOF,
  PRINT,
  PRINTLN,
} TokenType;
typedef struct {
  TokenType tokenType;
  char *value;
} Token;
#endif
