#include "Array2D.h"

Array2D::Array2D(int width, int height, int size)
{
  w = width;
  h = height;
  s = size;
  malloc2d();
}

Array2D::~Array2D()
{
  delete [] _array;
}

void **Array2D::array()
{
  return _array;
}

void Array2D::malloc2d()
{
  _array = (void**) new char[h * sizeof(void*) + h * w * s];
  for (int i = 0 ; i < h ; i++)
  {
    _array[i] = ( (char*)(_array + h) ) + i * w * s;
  }
}
