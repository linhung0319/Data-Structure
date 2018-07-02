#include <iostream>
#include "LinkList.h"
#include "Polynomial.h"
using namespace std;

int main()
{
  //LinkList<int> list1(1);
  //list1.push_back(1);
  //list1.push_back(2);
  //list1.push_back(3);
  //list1.deleteNode(list1.first()->rPtr->rPtr);
  //list1.insertAfter(list1.first(), 10);
  //cout << (list1.first()->rPtr)->data << endl;
  //cout << (list1.first()->rPtr->rPtr)->data << endl;
  //cout << (list1.first()->rPtr->rPtr->rPtr)->data << endl;
  //list1.deleteAll();
  PolyElement e1(1, 10);
  PolyElement e2(-3, 5);
  PolyElement e3(7, 12);

  Polynomial p;
  p.attach(e1);
  p.attach(e2);
  p.attach(e3);
  cout << p << endl;
}
