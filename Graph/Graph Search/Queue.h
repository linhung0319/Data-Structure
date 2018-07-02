#ifndef QUEUE_H
#define QUEUE_H

#include "LinkList.h"

template <class T>
class Queue
{
public:
  Queue():list(10), outNode(NULL){};
  ~Queue()
  {
    delete outNode;
  }
  void addQ(T data)
  {
    list.push_back(data);
  }
  Node<T> *deleteQ()
  {
    Node<T> *qFirst = list.next(list.first());
    if (list.deleteNode(qFirst))
    {
      //LinkList的deleteNode()會將Node暫時放到儲存區，
      //下一次addNode()可能會將此Node直接拿出來用，
      //因此若Queue直接以pointer接收被delete的Node，
      //可能會因為LinkList內部的動作導致Queue的output值被改變
      //這邊必須另外new一個新的Node，以確保Queue的output值只在Queue中被決定
      if(outNode == NULL) outNode = new Node<T>(qFirst->data);
      else outNode->data = qFirst->data;

      return outNode;
    }
    else return NULL;
  }
private:
  LinkList<T> list;
  Node<T> *outNode;
};

#endif
