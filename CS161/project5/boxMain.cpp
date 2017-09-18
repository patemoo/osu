// Box main

#include <iostream>
#include "Box.hpp"

using namespace std;

int main () 
{
  Box box1(2.4, 7.1, 5.0);
  Box box2;
  double volume1 = box1.calcVolume();
  double surfaceArea1 = box1.calcSurfaceArea();
  double volume2 = box2.calcVolume();
  double surfaceArea2 = box2.calcSurfaceArea();

  cout << volume1 << endl << surfaceArea1 << endl << volume2 << endl << surfaceArea2 << endl;

  return 0;
}


