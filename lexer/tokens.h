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

  PLUS,
  MINUS,
  DIVIDE,
  MUNIPLY,

  GREATER,
  SMALLER,
  EQUALS,

  INDENTIFIER,
  TOKEN_EOF,
} TokenType;
typedef struct {
  TokenType tokenType;
  char *value;
} Token;
#endif
