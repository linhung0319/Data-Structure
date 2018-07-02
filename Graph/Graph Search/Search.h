#ifndef SEARCH_H
#define SEARCH_H

#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
#include "Queue.h"

enum Mode{AdMatrix, AdList};

class GS
{
public:
  explicit GS(AdjacencyMatrix *matrix);
  explicit GS(AdjacencyList *list);
  ~GS();
  virtual void search(int node){};
  virtual void showResult(){};
  void printResult(int x);
protected:
  Mode _mode;
  int _nodeNum;
  int *_result;
  bool *arrived;
  AdjacencyList *_list;
  AdjacencyMatrix *_matrix;
};

class DFS : public GS
{
public:
  explicit DFS(AdjacencyMatrix *matrix):GS(matrix){};
  explicit DFS(AdjacencyList *list):GS(list){};
  virtual void search(int node);
  virtual void showResult();
private:
  void iterMatrixRow(int node);
  void iterListRow(int node);
  int index;
};

class BFS : public GS
{
public:
  explicit BFS(AdjacencyMatrix *matrix):GS(matrix){};
  explicit BFS(AdjacencyList *list):GS(list){};
  virtual void search(int node);
  virtual void showResult();
private:
  void iterMatrix(int node);
  void iterList(int node);
  int index;
};

class ArticulationS : public GS
{
public:
  explicit ArticulationS(AdjacencyMatrix *matrix);
  explicit ArticulationS(AdjacencyList *list);
  ~ArticulationS();
  virtual void search(int node);
  virtual void showResult();
private:
  void dfsMatrix(int child, int parent);
  void dfsList(int child, int parent);
  int index;
  int *_visit;
  int *_low;
  bool *_articulationVertex;
};

#endif
