#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

#include "Array2D.h"

class AdjacencyMatrix
{
public:
  AdjacencyMatrix(int n);
  int *operator[](int i);
  int nodeNum();
private:
  int _nodeNum;
  Array2D _array;
};

#endif
