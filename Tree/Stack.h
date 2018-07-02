#ifndef STACK_H
#define STACK_H

#include <iostream>

template <class T>
class Stack
{
public:
  Stack(int stackSize)
  {
    _top = -1;
    maxSize = stackSize;
    stack = new T[maxSize];
  }

  ~Stack()
  {
    delete [] stack;
  }

  T &operator[](int i)
  {
    return *(stack + i);
  }

  bool isFull()
  {
    if (_top == maxSize - 1) return true;
    else return false;
  }

  bool isEmpty()
  {
    if (_top < 0) return true;
    else return false;
  }

  void push(T item)
  {
    if (isFull()) std::cout << "The stack is full\n";
    else stack[++_top] = item;
  }

  T pop()
  {
    if (isEmpty()) std::cout << "The stack is empty\n";
    else return stack[_top--];
  }

  const int top()
  {
    return _top;
  }
private:
  T *stack;
  int _top;
  int maxSize;
};

#endif
