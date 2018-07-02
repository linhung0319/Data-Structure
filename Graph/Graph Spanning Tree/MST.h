#ifndef MST_H
#define MST_H

#include <vector>
#include "AdjacencyMatrix.h"
#include "WeightingAdjacencyList.h"
#include "Heap.h"

class MSTbase; //Forward Declaration

enum Mode{AdMatrix, AdList};

struct Edge
{
  Edge(int s, int d, int w):src(s), des(d), weight(w){};
  int src, des, weight;
};

inline bool mysort(Edge x, Edge y) {return x.weight < y.weight;}

class SortEdge
{
public:
  SortEdge(AdjacencyMatrix *matrix);
  SortEdge(WeightingAdjacencyList *list);
  int edgeNum();
  std::vector<Edge> edges;
private:
  int countMatrixEdge(AdjacencyMatrix *matrix);
  int countListEdge(WeightingAdjacencyList *list);
  void sort();
  int _edgeNum;
};

class MSTbase
{
public:
  MSTbase(AdjacencyMatrix *matrix);
  MSTbase(WeightingAdjacencyList *list);
  ~MSTbase();
  void printResult(int x);
  virtual void showResult(){};
protected:
  Mode _mode;
  int _nodeNum;
  int *_result;
  bool *arrived;
  WeightingAdjacencyList *_list;
  AdjacencyMatrix *_matrix;
};

class Prim: public MSTbase
{
public:
  Prim(AdjacencyMatrix *matrix);
  Prim(WeightingAdjacencyList *list);
  ~Prim();
  void spanning(int node);
  void showResult();

private:
  void spannedByMatrix(int node);
  void spannedByList(int node);
  int *d;
  Heap<int> *_heap;
  int index;
  static const int MAXWEIGHT = 10000;
};

//class Kruskal: public MSTbase
//{
//public:
//  Kruskal(AdjacencyMatrix *matrix);
//  Kruskal(WeightingAdjacencyList *list);
//  ~Kruskal();
//private:

};

#endif
