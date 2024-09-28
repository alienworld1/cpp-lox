#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include "token_type.h"

class Token {
  private:
    const TokenType type;
    const std::string lexeme;
    const void* literal;
    const int line;
  
  public:
    Token(TokenType type, std::string lexeme, void* literal, int line)
      : type(type), lexeme(std::move(lexeme)), literal(literal), line(line) {};
    std::string toString();
};

#endif
