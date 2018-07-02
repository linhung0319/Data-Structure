#include <iostream>
#include "Set.h"
using namespace std;

int main()
{
  Set s(5);
  cout << "num: " << s.num() << endl;

  s.unionSet(1, 2);
  s.unionSet(1, 3);
  s.unionSet(2, 4);
  s.showRoute();

  cout << "2 in set: " << s.findSet(2) << endl;
}
