#include <string>
#include <sstream>
#include "token.h"
#include "token_type.h"

std::string Token::toString() {
  std::ostringstream oss;
  oss << type << " " << lexeme << " " << literal;
  std::string output = oss.str();
  return output;
}
