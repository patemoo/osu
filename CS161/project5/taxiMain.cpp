// Taxicab Main

#include <iostream>
#include "Taxicab.hpp"

using std::cout;
using std::endl;

int main()
{
  Taxicab cab1;
  Taxicab cab2(5, -8);
  cab1.moveX(3);
  cab1.moveY(-4);
  cab1.moveX(-1);
  cout << cab1.getDistanceTraveled() << std::endl;
  cab2.moveY(7);
  cout << cab2.getYCoord() << std::endl;

  return 0;
}