#include <stddef.h>
#include "WeightingAdjacencyList.h"

WeightingAdjacencyList::WeightingAdjacencyList(int n)
{
  _nodeNum = n;
  _list = new Element*[n];
  for (int i = 0 ; i < n ; i++)
  {
    //可以使用(*this)[i]給值
    //無法使用(*this)[i]賦值
    //因為(*this)[i]是一個function return的value
    _list[i] = NULL;
  }
}

WeightingAdjacencyList::~WeightingAdjacencyList()
{
  for (int i = 0 ; i < _nodeNum ; i++)
  {
    Element *tmp;
    Element *ptr = _list[i];
    while (ptr != NULL)
    {
      tmp = ptr;
      ptr = ptr->next;
      delete tmp;
    }
  }
  delete [] _list;
}

int WeightingAdjacencyList::nodeNum()
{
  return _nodeNum;
}

void WeightingAdjacencyList::add_edge(int src, int des, int weight)
{
  Element *e = new Element;
  e->w = weight;
  e->v = des;
  e->next = _list[src];
  _list[src] = e;
}

Element *WeightingAdjacencyList::operator[](int i)
{
  return _list[i];
}
