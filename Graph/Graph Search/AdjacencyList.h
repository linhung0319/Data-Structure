#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

struct Element
{
  int v;
  Element *next;
};

class AdjacencyList
{
public:
  AdjacencyList(int n);
  ~AdjacencyList();
  int nodeNum();
  void add_edge(int src, int des);
  Element *operator[](int i);
private:
  Element **_list;
  int _nodeNum;
};

#endif
