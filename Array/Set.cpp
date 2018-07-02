#include <iostream>
#include "Set.h"

Set::Set(int n)
:_num(n)
{
  route = new int[_num];
  for (int i = 0 ; i < _num ; i++)
  {
    route[i] = -1;
  }
}

Set::~Set()
{
  delete [] route;
}

int Set::num()
{
  return _num;
}

void Set::unionSet(int x, int y)
{
  int index = route[y];
  while (index >= 0)
  {
    y = index;
    index = route[y];
  }

  index = route[x];
  while (index >= 0)
  {
    x = index;
    index = route[x];
  }

  if (route[x] <= route[y])
  {
    route[x] += route[y];
    route[y] = x;
  }
  else
  {
    route[y] += route[x];
    route[x] = y;
  }
}

int Set::findSet(int x)
{
  int trace = x;
  int index = route[trace];
  while (index >= 0)
  {
    trace = index;
    index = route[trace];
  }
  route[x] = trace; //Collatpsing
  return trace;
}

void Set::showRoute()
{
  std::cout << "Index Route:\n";
  for (int i = 0 ; i < _num ; i++)
  {
    std::cout << i << "      " << route[i] << "\n";
  }
}
