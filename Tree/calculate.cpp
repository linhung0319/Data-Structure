#include <iostream>
#include <string>
#include "BinaryExpressionTree.h"
#include "Heap.h"
using namespace std;

int main()
{

  string s = "(a+b)*c+d";
  BinaryExpressionTree tree(s);
  tree.traverse(tree.root(), DLR);
  string result = tree.traverseResult();
  cout << "Binary Expression Tree Result: " << result << "\n" << endl;


  Heap<char> heap(MINHEAP, 5);
  string c = heap.category();
  HeapNode<char> hn1('p', 1, 2), hn2('p', 2, 3), hn3('e', 3, 5), hn4('a', 4, 1), hn5('l', 5, 4);
  heap.addHN(hn1);
  heap.addHN(hn2);
  heap.addHN(hn3);
  heap.addHN(hn4);
  heap.addHN(hn5);
  cout << "Heap Category: " << c;
  cout << "\nHeap Array Sequence: ";
  for (int i = 1 ; i < heap.rear() ; i++)
  {
    cout << heap.heap()[i].data;
  }

  cout << "\nHeap Position Sequence: ";
  for (int i = 1 ; i < heap.size() ; i++)
  {
    cout << heap.pos()[i];
  }

  cout << "\nHeap Result: ";
  HeapNode<char> hn_result;
  int length = heap.rear();
  for (int i = 1 ; i < length ; i++)
  {
    hn_result = heap.deleteHN();
    cout << hn_result.data;
  }
}
