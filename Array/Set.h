#ifndef SET_H
#define SET_H

class Set
{
public:
  Set(int n);
  ~Set();
  int num();
  void unionSet(int x, int y);
  int findSet(int x);
  void showRoute();
private:
  int _num;
  int *route;
};

#endif
