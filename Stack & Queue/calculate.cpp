#include <iostream>
#include <string>
#include "Stack.h"
#include "Trans2Postfix.h"
using namespace std;

int main()
{
  string trans = "a+b*c+d";
  string postfix = "";
  trans2Postfix(trans, postfix);
  cout << postfix;
}
