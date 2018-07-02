#include <iostream>
#include <cstddef>
#include "Trans2Postfix.h"
#include "Stack.h"
using namespace std;

void trans2Postfix(const string &trans, string &postfix)
{
  Stack<TokenType> stack(trans.length());
  stack.push(EOE);
  TokenType t;
  for (size_t i = 0 ; i < trans.length() ; i++)
  {
    t = getOneToken(trans, i);
    if (t == OPERAND) postfix += trans[i];
    else
    {
      if (t == RPAREN)
      {
        while (stack[stack.top()] != LPAREN)
        {
          postfix += TOKEN[stack.pop()];
        }
        stack.pop();
      }
      else
      {
        while (ISP[ stack[stack.top()] ] >= ICP[t])
        {
          postfix += TOKEN[stack.pop()];
        }
        stack.push(t);
      }
    }
  }

  while( (t = stack.pop()) != EOE )
  {
    postfix += TOKEN[t];
  }
}

TokenType getOneToken(const string &s, int index)
{
  char c = s[index];
  switch(c)
  {
    case TOKEN[LPAREN]: return LPAREN;
    case TOKEN[RPAREN]: return RPAREN;
    case TOKEN[PLUS]: return PLUS;
    case TOKEN[MINUS]: return MINUS;
    case TOKEN[TIMES]: return TIMES;
    case TOKEN[DEVIDES]: return DEVIDES;
    default: return OPERAND;
  }
}
