#include <iostream>
#include <algorithm>
#include "MST.h"

SortEdge::SortEdge(AdjacencyMatrix *matrix)
{
  _edgeNum = countMatrixEdge(matrix);
  sort();
}

SortEdge::SortEdge(WeightingAdjacencyList *list)
{
  _edgeNum = countListEdge(list);
  sort();
}

int SortEdge::countMatrixEdge(AdjacencyMatrix *matrix)
{
  int n = 0;
  for (int i = 0 ; i < matrix->nodeNum() - 1 ; i++)
  {
    for (int j = i + 1 ; j < matrix->nodeNum() ; j++)
    {
      if ( (*matrix)[i][j] > 0 )
      {
        n++;
        Edge e(i, j, (*matrix)[i][j]);
        edges.push_back(e);
      }
    }
  }
  return n;
}

int SortEdge::countListEdge(WeightingAdjacencyList *list)
{
  int n = 0;
  for (int i = 0 ; i < list->nodeNum() - 1 ; i++)
  {
    Element *ptr = (*list)[i];
    while (ptr != NULL)
    {
      if (ptr->v > i)
      {
        n++;
        Edge e(i, ptr->v, ptr->w);
        edges.push_back(e);
      }
      ptr = ptr->next;
    }
  }
  return n;
}

int SortEdge::edgeNum()
{
  return _edgeNum;
}

void SortEdge::sort()
{
  std::sort(edges.begin(), edges.end(), mysort);
}

MSTbase::MSTbase(AdjacencyMatrix *matrix)
:_mode(AdMatrix), _nodeNum(matrix->nodeNum()), \
_matrix(matrix), _list(NULL)
{
  _result = new int[_nodeNum - 1];
  arrived = new bool[_nodeNum];
}

MSTbase::MSTbase(WeightingAdjacencyList *list)
:_mode(AdList), _nodeNum(list->nodeNum()), \
_matrix(NULL), _list(list)
{
  _result = new int[_nodeNum - 1];
  arrived = new bool[_nodeNum];
}

MSTbase::~MSTbase()
{
  delete [] _result;
  delete [] arrived;
}

void MSTbase::printResult(int x)
{
  for (int i = 0 ; i < x ; i++)
  {
    std::cout << _result[i] << " ";
  }
}

Prim::Prim(AdjacencyMatrix *matrix)
:MSTbase(matrix)
{
  d = new int[_nodeNum];
  _heap = NULL;
}

Prim::Prim(WeightingAdjacencyList *list)
:MSTbase(list)
{
  d = NULL;
  _heap = new Heap<int>(MINHEAP, _nodeNum);
}

Prim::~Prim()
{
  if (d != NULL) delete [] d;
  if (_heap != NULL) delete _heap;
}

void Prim::spanning(int node)
{
  switch (_mode)
  {
    case AdMatrix:
    {
      for (int i = 0 ; i < _nodeNum ; i++)
      {
        (this->arrived)[i] = false;
        d[i] = MAXWEIGHT;
      }
      index = 0;
      spannedByMatrix(node);
      break;
    }
    case AdList:
    {
      //除了到root的路徑以外，到其他點的路徑設為MAXWEIGHT
      //heap不加入root，因為沒有任何路徑到此點
      for (int i = 0 ; i < _nodeNum ; i++)
      {
        (this->arrived)[i] = false;
        if (i != node)
        {
          HeapNode<int> hn(i, i, MAXWEIGHT);
          _heap->addHN(hn);
        }
      }

      index = 0;
      spannedByList(node);
      break;
    }
  }
}

void Prim::spannedByMatrix(int node)
{
  arrived[node] = true;
  int min_v = MAXWEIGHT;
  int min_i;
  for (int i = 0 ; i < _nodeNum ; i++)
  {
    if (!arrived[i])
    {
      if ( (*_matrix)[node][i] > 0 ) d[i] = std::min( (*_matrix)[node][i], d[i] );
      if (d[i] < min_v)
      {
        min_v = d[i];
        min_i = i;
      }
    }
  }

  if (min_v == MAXWEIGHT) return;
  else
  {
    _result[index] = min_v;
    index++;
    spannedByMatrix(min_i);
  }
}

void Prim::spannedByList(int node)
{
  arrived[node] = true;

  Element *ptr = (*_list)[node];
  while (ptr != NULL)
  {
    if (!arrived[ptr->v])
    {
      _heap->modifyOrder(ptr->v, ptr->w);
    }

    ptr = ptr->next;
  }

  if (_heap->isEmpty()) return;
  else
  {
    HeapNode<int> hn = _heap->deleteHN();
    _result[index] = hn.order;
    index++;
    spannedByList(hn.data);
  }
}

void Prim::showResult()
{
  std::cout << "Prim\'s Algorithm Result: ";
  MSTbase::printResult(index);
  std::cout << "\n";
}

//Kruskal::Kruskal(AdjacencyMatrix *matrix)
//:MSTbase(matrix)

//Kruskal::Kruskal(WeightingAdjacencyList *list)
//:MSTbase(list)
