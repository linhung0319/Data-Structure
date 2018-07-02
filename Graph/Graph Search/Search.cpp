#include <iostream>
#include <algorithm>
#include "Search.h"

GS::GS(AdjacencyMatrix *matrix)
:_mode(AdMatrix), _nodeNum(matrix->nodeNum()), \
_matrix(matrix), _list(NULL)
{
  _result = new int[_nodeNum];
  arrived = new bool[_nodeNum];
}

GS::GS(AdjacencyList *list)
:_mode(AdList), _nodeNum(list->nodeNum()), \
_matrix(NULL), _list(list)
{
  _result = new int[_nodeNum];
  arrived = new bool[_nodeNum];
}

GS::~GS()
{
  delete [] _result;
  delete [] arrived;
}

void GS::printResult(int x)
{
  for (int i = 0 ; i <= x ; i++)
  {
    std::cout << _result[i] << " ";
  }
  std::cout << "\n";
}


void DFS::search(int node)
{
  for (int i = 0 ; i < _nodeNum ; i++)
  {
    (this->arrived)[i] = false;
  }

  switch (_mode)
  {
    case AdMatrix:
    {
      index = 0;
      iterMatrixRow(node);
      break;
    }
    case AdList:
    {
      index = 0;
      iterListRow(node);
      break;
    }
  }
}

void DFS::showResult()
{
  std::cout << "DFS Result: ";
  GS::printResult(index);
}

void DFS::iterMatrixRow(int node)
{
  if (index == 0)
  {
    _result[index] = node;
    arrived[node] = true;
  }

  for (int i = 0 ; i < _nodeNum ; i++)
  {
    if ( (*_matrix)[node][i] == 1 && !arrived[i] )
    {
      index++;
      _result[index] = i;
      arrived[i] = true;
      iterMatrixRow(i);
    }
  }
  return;
}

void DFS::iterListRow(int node)
{
  if (index == 0)
  {
    _result[index] = node;
    arrived[node] = true;
  }

  Element *ptr = (*_list)[node];
  while (ptr != NULL)
  {
    if (!arrived[ptr->v])
    {
      index++;
      _result[index] = ptr->v;
      arrived[ptr->v] = true;
      iterListRow(ptr->v);
    }
    ptr = ptr->next;
  }
  return;
}


void BFS::search(int node)
{
  for (int i = 0 ; i < _nodeNum ; i++)
  {
    (this->arrived)[i] = false;
  }

  switch (_mode)
  {
    case AdMatrix:
    {
      index = 0;
      iterMatrix(node);
      break;
    }
    case AdList:
    {
      index = 0;
      iterList(node);
      break;
    }
  }
}

void BFS::showResult()
{
  std::cout << "BFS Result: ";
  GS::printResult(index);
}

void BFS::iterMatrix(int node)
{
  Queue<int> q;
  q.addQ(node);
  arrived[node] = true;
  _result[index] = node;
  Node<int> *n;
  while( (n = q.deleteQ()) != NULL )
  {
    for (int i = 0 ; i < _nodeNum ; i++)
    {
      if ( (*_matrix)[n->data][i] == 1 && !arrived[i] )
      {
        index++;
        q.addQ(i);
        arrived[i] = true;
        _result[index] = i;
      }
    }
  }
}

void BFS::iterList(int node)
{
  Queue<int> q;
  q.addQ(node);
  arrived[node] = true;
  _result[index] = node;
  Node<int> *n;
  while( (n = q.deleteQ()) != NULL )
  {
    Element *ptr = (*_list)[n->data];
    while (ptr != NULL)
    {
      if ( !arrived[ptr->v] )
      {
        index++;
        q.addQ(ptr->v);
        arrived[ptr->v] = true;
        _result[index] = ptr->v;
      }
      ptr = ptr->next;
    }
  }
}

ArticulationS::ArticulationS(AdjacencyMatrix *matrix)
:GS(matrix)
{
  _visit = new int[_nodeNum];
  _low = new int[_nodeNum];
  _articulationVertex = new bool[_nodeNum];
}

ArticulationS::ArticulationS(AdjacencyList *list)
:GS(list)
{
  _visit = new int[_nodeNum];
  _low = new int[_nodeNum];
  _articulationVertex = new bool[_nodeNum];
}

ArticulationS::~ArticulationS()
{
  delete [] _visit;
  delete [] _low;
  delete [] _articulationVertex;
}

void ArticulationS::search(int node)
{
  for (int i = 0 ; i < _nodeNum ; i++)
  {
    (this->arrived)[i] = false;
    _visit[i] = 0;
    _articulationVertex[i] = false;
  }

  switch (_mode)
  {
    case AdMatrix:
    {
      index = 0;
      dfsMatrix(node, node);
      break;
    }
    case AdList:
    {
      index = 0;
      dfsList(node, node);
      break;
    }
  }
}

void ArticulationS::dfsMatrix(int child, int parent)
{
  if (index == 0)
  {
    _result[index] = child;
    arrived[child] = true;
    _visit[child] = _low[child] = index + 1;
  }

  bool ap = false;
  int children = 0;

  for (int i = 0 ; i < _nodeNum ; i++)
  {
    if (parent != i)
    {
      if ( (*_matrix)[child][i] == 1 && !arrived[i] )
      {
        //children用來判斷此點有幾個children，用來確認root是否為關節點
        children++;
        index++;
        _result[index] = i;
        arrived[i] = true;
        //若點i還未走過，則此點被拜訪(visit)的順序和
        //其最低(low)的順序是一樣的
        _visit[i] = _low[i] = index + 1;
        dfsMatrix(i, child);
        //以順序來看此點的low要小於下一點
        //若下一點之後有back trace，此點也可以走back trace，low相等
        //因此目前的點的low絕對小於等於下一個點的low
        _low[child] = std::min(_low[child], _low[i]);
        //假如下一點的low比此點的拜訪(visit)順序小，
        //表示下一點後有通往此點之前的back trace
        //此點不是關節點
        if (_low[i] >= _visit[child]) ap = true;
      }
      else if ( (*_matrix)[child][i] == 1 && arrived[i] )
      {
        //若遇到已經到達過的點，表示遇到back trace，
        //則low值更新為back trace的點的拜訪(visit)順序
        _low[child] = std::min(_low[child], _visit[i]);
      }
    }
  }

  if ( (parent == child && children > 1) || (parent != child && ap) )
  {
    _articulationVertex[child] = true;
  }
  return;
}

void ArticulationS::dfsList(int child, int parent)
{
  if (index == 0)
  {
    _result[index] = child;
    arrived[child] = true;
    _visit[child] = _low[child] = index + 1;
  }

  bool ap = false;
  int children = 0;

  Element *ptr = (*_list)[child];
  while (ptr != NULL)
  {
    if (parent != ptr->v)
    {
      if ( !arrived[ptr->v] )
      {
        //children用來判斷此點有幾個children，用來確認root是否為關節點
        children++;
        index++;
        _result[index] = ptr->v;
        arrived[ptr->v] = true;
        //若點i還未走過，則此點被拜訪(visit)的順序和
        //其最低(low)的順序是一樣的
        _visit[ptr->v] = _low[ptr->v] = index + 1;
        dfsList(ptr->v, child);
        //以順序來看此點的low要小於下一點
        //若下一點之後有back trace，此點也可以走back trace，low相等
        //因此目前的點的low絕對小於等於下一個點的low
        _low[child] = std::min(_low[child], _low[ptr->v]);
        //假如下一點的low比此點的拜訪(visit)順序小，
        //表示下一點後有通往此點之前的back trace
        //此點不是關節點
        if (_low[ptr->v] >= _visit[child]) ap = true;
      }
      else if ( arrived[ptr->v] )
      {
        //若遇到已經到達過的點，表示遇到back trace，
        //則low值更新為back trace的點的拜訪(visit)順序
        _low[child] = std::min(_low[child], _visit[ptr->v]);
      }
    }
    ptr = ptr->next;
  }

  if ( (parent == child && children > 1) || (parent != child && ap) )
  {
    _articulationVertex[child] = true;
  }
  return;
}

void ArticulationS::showResult()
{
  std::cout << "Articulation Vertex Result: ";
  for (int i = 0 ; i < _nodeNum ; i++)
  {
    if (_articulationVertex[i]) std::cout << i << " ";
  }
  std::cout << "\n";
}
