#include <iostream>
#include "AdjacencyMatrix.h"
#include "WeightingAdjacencyList.h"
#include "MST.h"

void setAdjacency(AdjacencyMatrix &matrix, WeightingAdjacencyList &list);

int main()
{
  AdjacencyMatrix matrix(6);
  WeightingAdjacencyList list(6);
  setAdjacency(matrix, list);

  Prim prim1(&matrix);
  prim1.spanning(0);
  prim1.showResult();

  Prim prim2(&list);
  prim2.spanning(0);
  prim2.showResult();

  SortEdge se1(&matrix);
  SortEdge se2(&list);
}

void setAdjacency(AdjacencyMatrix &matrix, WeightingAdjacencyList &list)
{
  matrix[0][1] = 20;
  matrix[0][4] = 12;
  matrix[1][0] = 20;
  matrix[1][2] = 10;
  matrix[2][1] = 10;
  matrix[2][3] = 28;
  matrix[2][5] = 14;
  matrix[3][2] = 28;
  matrix[3][4] = 26;
  matrix[3][5] = 15;
  matrix[4][0] = 12;
  matrix[4][3] = 26;
  matrix[4][5] = 25;
  matrix[5][2] = 14;
  matrix[5][3] = 15;
  matrix[5][4] = 25;

  list.add_edge(0, 4, 12);
  list.add_edge(0, 1, 20);
  list.add_edge(1, 2, 10);
  list.add_edge(1, 0, 20);
  list.add_edge(2, 5, 14);
  list.add_edge(2, 3, 28);
  list.add_edge(2, 1, 10);
  list.add_edge(3, 5, 15);
  list.add_edge(3, 4, 26);
  list.add_edge(3, 2, 28);
  list.add_edge(4, 5, 25);
  list.add_edge(4, 3, 26);
  list.add_edge(4, 0, 12);
  list.add_edge(5, 4, 25);
  list.add_edge(5, 3, 15);
  list.add_edge(5, 2, 14);
}
