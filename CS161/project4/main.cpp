/**********
 * main.cpp
 * ************/

#include <iostream>
using std::cout;
using std::endl;

double fallDistance(double time);
void smallSort(int &a, int &b, int &c);
int hailstone(int value);

int main()
{
//  cout << fallDistance(3.0) << endl;
/*
  int a = 14;
  int b = -90;
  int c = 2;
  smallSort(a, b, c);
  cout << a << ", " << b << ", " << c << endl;
*/

  cout << hailstone(3) << endl;

  return 0;
}
