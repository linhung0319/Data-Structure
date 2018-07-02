#ifndef HEAP_H
#define HEAP_H

#include <string>
#include <iostream>

enum HeapCategory{MAXHEAP, MINHEAP};

inline bool larger(int a, int b)
{
  if (a > b) return true;
  else return false;
}

inline bool smaller(int a, int b)
{
  if (a < b) return true;
  else return false;
}

template <class T>
struct HeapNode
{
  HeapNode(T d, int p, int o):data(d), pos(p), order(o){};
  HeapNode():order(-1){};
  T data;     //Node所含的資料
  int pos;    //Node的序列，用來快速找到Node在Heap中的位置
  int order;  //Node在Heap中的優先順序
};

template <class T>
class Heap
{
public:
  Heap(HeapCategory hc, int size)
  :_category(hc), MAXSIZE(size + 1)
  {
    _heap = new HeapNode<T>[MAXSIZE];

    //當Heap被初始化，並且還沒被放入任何Node之前，預設Node的序列位置為-1
    _pos = new int[MAXSIZE];
    for (int i = 1 ; i < MAXSIZE ; i++)
    {
      _pos[i] = -1;
    }

    _rear = 1;
    switch (_category)
    {
      case MAXHEAP:
        compare = larger;
        break;
      case MINHEAP:
        compare = smaller;
        break;
    }
  };

  ~Heap()
  {
    delete [] _heap;
  }

  std::string category()
  {
    switch(_category)
    {
      case MAXHEAP:
        return "MAX";
        break;
      case MINHEAP:
        return "MIN";
        break;
    }
  }

  HeapNode<T> *const heap() const
  {
    return _heap;
  }

  int *const pos() const
  {
    return _pos;
  }

  int rear() const
  {
    return _rear;
  }

  int size() const
  {
    return MAXSIZE;
  }

  bool isFull() const
  {
    if (_rear >= MAXSIZE) return true;
    else return false;
  }

  bool isEmpty() const
  {
    if (_rear <= 1) return true;
    else return false;
  }

  void addHN(HeapNode<T> n)
  {
    if ( isFull() )
    {
      std::cout << "Can not add new element to a full heap.\n";
      return;
    }

    int index = _rear;
    if ( isEmpty() )
    {
      _heap[index] = n;
      _pos[n.pos] = index;
    }
    else
    {
      while ( compare(n.order, _heap[index / 2].order) )
      {
        _heap[index] = _heap[index / 2];
        _pos[_heap[index].pos] = index;
        index /= 2;
        if (index == 1) break;
      }
      _heap[index] = n;
      _pos[n.pos] = index;
    }
    _rear++;
  }

  HeapNode<T> deleteHN()
  {
    if ( isEmpty() )
    {
        std::cout << "Can not delete element from an empty heap.\n";
        HeapNode<T> n;
        return n;
    }

    HeapNode<T> frontNode = _heap[1];
    _pos[_heap[1].pos] = -1;
    int index = 1;
    _rear--;

    for (int i = _rear ; i > 1 ; i /= 2)
    {
      if (index * 2 >= _rear) break;    //_rear <= 2*index，底下已經沒有Node，可以結束迴圈
      else if (1 + index * 2 == _rear)  //_rear == 2*index+1，左邊底下有一個Node，需要比較
      {
        if ( compare(_heap[index * 2].order, _heap[_rear].order) )
        {
          _heap[index] = _heap[index * 2];
          _pos[_heap[index].pos] = index;
          index = index * 2;
        }
        else break;
      }
      else //_rear > 2*index+1，左右兩邊底下都有Node，兩個都需要比較
      {
        if ( compare(_heap[index * 2].order, _heap[_rear].order) || \
             compare(_heap[1 + index * 2].order, _heap[_rear].order) )
        {
          if ( compare(_heap[index * 2].order, _heap[1 + index * 2].order) )
          {
            _heap[index] = _heap[index * 2];
            _pos[_heap[index].pos] = index;
            index = index * 2;
          }
          else
          {
            _heap[index] = _heap[1 + index * 2];
            _pos[_heap[index].pos] = index;
            index = 1 + index * 2;
          }
        }
        else break;
      }
    }

    _heap[index] = _heap[_rear];
    _pos[_heap[index].pos] = index;
    return frontNode;
  }

  void modifyOrder(int p, int o)
  {
    if (p >= MAXSIZE || p <= 0)
    {
      std::cout << "Invalid position\n";
      return;
    }
    else if (_pos[p] <= 0)
    {
      std::cout << "The position " << p << " is not in the heap\n";
      return;
    }
    else if ( !compare(o, _heap[_pos[p]].order) )
    {
      //std::cout << "The order can only be decreased or increased in min or max heap respectively\n";
      return;
    }
    else
    {
      _heap[_pos[p]].order = o;
      int index = _pos[p];
      HeapNode<T> tmp;
      while ( compare(_heap[index].order, _heap[index / 2].order) )
      {
        tmp = _heap[index];
        _heap[index] = _heap[index / 2];
        _pos[_heap[index].pos] = index;
        index /= 2;
        _heap[index] = tmp;
        _pos[_heap[index].pos] = index;
        if (index == 1) break;
      }
    }
  }

private:
  const HeapCategory _category;
  const int MAXSIZE;
  HeapNode<T> *_heap;
  int _rear;
  bool (*compare)(int, int);
  int *_pos;
};

#endif
