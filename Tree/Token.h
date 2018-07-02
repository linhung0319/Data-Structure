#ifndef TOKEN_H
#define TOKEN_H

enum TokenType{LPAREN=0, RPAREN, PLUS, MINUS, TIMES, DEVIDES, EOE, OPERAND};
constexpr char TOKEN[6] = {'(', ')', '+', '-', '*', '/'};
const int ISP[7] = {0, 19, 12, 12, 13, 0};
const int ICP[7] = {20, 19, 12, 12, 13, 0};

#endif
