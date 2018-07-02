#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include "LinkList.h"

struct PolyElement
{
  PolyElement(int p, int e):param(p), exp(e){};
  PolyElement(){}; //Provided for the LinkList<PolyElement> instantiation
  int param;
  int exp;
};

const int POLYNOMIAL_MAX_LENGTH = 10;

class Polynomial
{
  //Polynomial has to be iterated through pointer in the boject,
  //thus const Polynomial can not be passed as argument in operator<<  
  friend std::ostream &operator<<(std::ostream &, Polynomial &);
public:
  Polynomial(int polyLength):polyList(polyLength){};
  Polynomial():polyList(POLYNOMIAL_MAX_LENGTH){};

  void attach(PolyElement);
private:
  LinkList<PolyElement> polyList;
};

#endif
