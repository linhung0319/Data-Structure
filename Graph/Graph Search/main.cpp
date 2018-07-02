#include <iostream>
#include "AdjacencyMatrix.h"
#include "AdjacencyList.h"
#include "search.h"
using namespace std;

void setAdjacency(AdjacencyMatrix &matrix, AdjacencyList &list);

int main()
{
  AdjacencyMatrix matrix(5);
  AdjacencyList list(5);
  setAdjacency(matrix, list);

  DFS dfs1(&matrix);
  dfs1.search(1);
  dfs1.showResult();

  DFS dfs2(&list);
  dfs2.search(1);
  dfs2.showResult();

  BFS bfs1(&matrix);
  bfs1.search(1);
  bfs1.showResult();

  BFS bfs2(&list);
  bfs2.search(1);
  bfs2.showResult();

  ArticulationS as1(&matrix);
  as1.search(1);
  as1.showResult();

  ArticulationS as2(&list);
  as2.search(1);
  as2.showResult();
}

void setAdjacency(AdjacencyMatrix &matrix, AdjacencyList &list)
{
  matrix[0][1] = 1;
  matrix[0][2] = 1;
  matrix[1][0] = 1;
  matrix[1][2] = 1;
  matrix[1][3] = 1;
  matrix[1][4] = 1;
  matrix[2][0] = 1;
  matrix[2][1] = 1;
  matrix[2][4] = 1;
  matrix[3][1] = 1;
  matrix[4][1] = 1;
  matrix[4][2] = 1;

  list.add_edge(0, 2);
  list.add_edge(0, 1);
  list.add_edge(1, 4);
  list.add_edge(1, 3);
  list.add_edge(1, 2);
  list.add_edge(1, 0);
  list.add_edge(2, 4);
  list.add_edge(2, 1);
  list.add_edge(2, 0);
  list.add_edge(3, 1);
  list.add_edge(4, 2);
  list.add_edge(4, 1);
}
