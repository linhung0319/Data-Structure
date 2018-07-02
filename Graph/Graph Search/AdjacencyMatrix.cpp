#include <algorithm>
#include "AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix(int n)
:_nodeNum(n), _array(n, n, sizeof(int))
{
  std::fill( (*this)[0], (*this)[0] + n * n, 0 );
}

int *AdjacencyMatrix::operator[](int i)
{
  return ( (int**)_array.array() )[i];
}

int AdjacencyMatrix::nodeNum()
{
  return _nodeNum;
}
