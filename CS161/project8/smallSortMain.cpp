// small sort main

#include <iostream>
#include "smallSort2.cpp"

using std::cout;
using std::endl;

int main()
{

  int a = 14;
  int b = -90;
  int c = 2;

  smallSort2(&a, &b, &c);
  cout << a << ", " << b << ", " << c << endl;

  return 0;
}