#ifndef ARRAY2D_H
#define ARRAY2D_H

class Array2D
{
public:
  Array2D(int width, int height, int size)
  {
    w = width;
    h = height;
    s = size;
    malloc2d();
  }

  ~Array2D()
  {
    delete [] _array;
  }

  void **array()
  {
    return _array;
  }
private:
  void malloc2d()
  {
    _array = (void**) new char[h * sizeof(void*) + h * w * s];
    for (int i = 0 ; i < h ; i++)
    {
      _array[i] = ( (char*)(_array + h) ) + i * w * h;
    }
  }

  int w;
  int h;
  int s;
  void **_array;
};

#endif
