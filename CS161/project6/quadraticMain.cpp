// Quadratic main

#include <iostream>
#include "Quadratic.hpp"

using std::cout;
using std::endl;

int main()
{
  Quadratic quad1(1, 0, 1);
  quad1.setC(1.5);
  cout << quad1.getA() << endl;
  cout << quad1.valueFor(7) << endl;
  cout << quad1.numRealRoots() << endl;

  return 0;
}