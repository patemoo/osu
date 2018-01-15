/*****************************************************************
 * Program Filename: Area function
 * Author: Patrick Moore
 * Date: January 11, 2018
 * Description:
 * Input: 
 * Output: 
 *****************************************************************/

#include <stdio.h>
#include <math.h>

double getArea(double a, double b, double c);

int main() 
{

  printf("%f", getArea(6,5,10));

  return 0;
}

double getArea(double a, double b, double c)
{
  double p; // half the perimeter of the triangle.
  double A; // area of the triangle.

  p = (a + b + c) / 2;

  A = sqrt(p * (p-a) * (p-b) * (p-c));

  return A;
}