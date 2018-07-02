#ifndef TRANS2POSTFIX_H
#define TRANS2POSTFIX_H

#include <string>
#include "Token.h"

void trans2Postfix(const std::string &, std::string &);
TokenType getOneToken(const std::string &, int);


#endif
