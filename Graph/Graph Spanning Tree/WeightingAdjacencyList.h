#ifndef WEIGHTINGADJACENCYLIST_H
#define WEIGHTINGADJACENCYLIST_H

struct Element
{
  int w; //in edge weighting
  int v; //value
  Element *next;
};

class WeightingAdjacencyList
{
public:
  WeightingAdjacencyList(int n);
  ~WeightingAdjacencyList();
  int nodeNum();
  void add_edge(int src, int des, int weight);
  Element *operator[](int i);
private:
  Element **_list;
  int _nodeNum;
};

#endif
