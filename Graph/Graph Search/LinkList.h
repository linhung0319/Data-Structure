#ifndef LINKLIST_H
#define LINKLIST_H

#include <cstddef>

template <class T>
struct Node
{
public:
  Node(T d):data(d), lPtr(NULL), rPtr(NULL){};
  Node():lPtr(NULL), rPtr(NULL){};

  T data;
  struct Node *lPtr;
  struct Node *rPtr;
};

template <class T>
class LinkList
{
public:
  LinkList(int num)
  {
    _first = new Node<T>;
    _first->lPtr = NULL;
    _first->rPtr = NULL;

    _avail = new Node<T>;
    Node<T> *tmp;
    for (std::size_t i = 1 ; i < num ; i++)
    {
      tmp = new Node<T>;
      _avail->lPtr = tmp;
      tmp->rPtr = _avail;
      _avail = tmp;
    }
  }

  ~LinkList()
  {
    deleteAll();
    delete _first;
  }

  void push_back(T element)
  {
    Node<T> *n = newNode(element);

    n->rPtr = _first;
    if (_first->lPtr == NULL)
    {
      n->lPtr = _first;
      _first->lPtr = n;
      _first->rPtr = n;
    }
    else
    {
      n->lPtr = _first->lPtr;
      _first->lPtr->rPtr = n;
      _first->lPtr = n;
    }
  }

  bool deleteNode(Node<T> *n)
  {
    if (n != _first)
    {
      n->lPtr->rPtr = n->rPtr;
      n->rPtr->lPtr = n->lPtr;
      if (_avail == NULL)
      {
        _avail = n;
        _avail->lPtr = NULL;
        _avail->rPtr = NULL;
      }
      else
      {
        _avail->lPtr = n;
        n->lPtr = NULL;
        n->rPtr = _avail;
        _avail = n;
      }
      return true;
    }
    else return false;
  }

  void insertAfter(Node<T> *n, T element)
  {
    Node<T> *after_n = newNode(element);
    n->rPtr->lPtr = after_n;
    after_n->rPtr = n->rPtr;
    after_n->lPtr = n;
    n->rPtr = after_n;
  }

  Node<T> *first()
  {
    return _first;
  }

  Node<T> *rear()
  {
    return _first->lPtr;
  }

  Node<T> *next(Node<T> * n)
  {
    return n->rPtr;
  }

  Node<T> *previous(Node<T> * n)
  {
    return n->lPtr;
  }

  void deleteAll()
  {
    if (_first->lPtr != NULL)
    {
      _first->lPtr->rPtr = _avail;
      if (_avail != NULL) _avail->lPtr = _first->lPtr;

      _avail = _first->rPtr;
      _avail->lPtr = NULL;
      _first->lPtr = NULL;
      _first->rPtr = NULL;
    }

    while(_avail != NULL)
    {
      Node<T> *tmp = _avail;
      _avail = _avail->rPtr;
      delete tmp;
    }
  }

private:
  Node<T> *newNode(T element)
  {
    Node<T> *n;
    if (_avail == NULL) n = new Node<T>(element);
    else
    {
      n = _avail;
      _avail = _avail->rPtr;
      n->data = element;
    }

    return n;
  }

  Node<T> *_first;
  Node<T> *_avail;
};

#endif
