#ifndef ARRAY2D_H
#define ARRAY2D_H

class Array2D
{
public:
  Array2D(int width, int height, int size);
  ~Array2D();
  void **array();
protected:
  void malloc2d();
private:
  int w;
  int h;
  int s;
  void **_array;
};

#endif
