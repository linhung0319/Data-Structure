#include <iostream>
using namespace std;

struct inner
{
  int a;
};

struct B
{
  int b;
};

struct outer
{
  inner x;
  B y;
};

int main()
{
  int value_x = 5;
  int value_y = 10;
  outer *out1 = (outer*)malloc(sizeof(outer));
  out1->x.a = value_x;
  out1->y.b = value_y;

  cout << " original out1 " << endl;
  cout << out1->x.a << endl;
  cout << out1->y.b << endl << endl;

  cout << " inner *in1 = (inner *)out1 " << endl;
  inner *in1 = (inner *)out1;
  cout << in1->a << endl;
  in1->a = -1;
  cout << out1->x.a << endl << endl;

  cout << " outer *out2 = (outer *)in1 " << endl;
  outer *out2 = (outer *)in1;
  cout << out2->x.a << endl;
  cout << out2->y.b << endl << endl;

  cout << " B *i = (B *)out2 " << endl;
  B *i = (B *)out2;
  cout << i->b << endl;
  B *j = (B *)out1;
  cout << j->b << endl << endl;

  cout << " inner *k = (inner *)out1; " << endl;
  inner *k = (inner *)out1;
  B *l = (B *)out1;
  cout << k << endl;
  cout << l << endl;


}
