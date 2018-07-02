#include <cmath>
#include "Polynomial.h"
using namespace std;

ostream &operator<<(ostream &output, Polynomial &p)
{
  Node<PolyElement> *ptr = p.polyList.first();
  if (ptr->rPtr == NULL) return output;

  ptr = ptr->rPtr;
  output << ptr->data.param
         << "x^"
         << ptr->data.exp
         << " ";
  ptr = ptr->rPtr;
  while (ptr != p.polyList.first())
  {
    if (ptr->data.param < 0) output << "- ";
    else output << "+ ";

    output << abs(ptr->data.param)
           << "x^"
           << ptr->data.exp
           << " ";
    ptr = ptr->rPtr;
  }
  return output;
}

void Polynomial::attach(PolyElement element)
{
  if (polyList.next(polyList.first()) == NULL) polyList.push_back(element);
  else
  {
    Node<PolyElement> *last = polyList.rear();
    while (last->data.exp < element.exp && last != polyList.first())
    {
      last = last->lPtr;
    }

    if (last == polyList.first()) polyList.insertAfter(last, element);
    else
    {
      if (last->data.exp > element.exp) polyList.insertAfter(last, element);
      else if (last->data.exp == element.exp)
      {
        last->data.param += element.param;
        if (last->data.param == 0) polyList.deleteNode(last);
      }
    }
  }
}
