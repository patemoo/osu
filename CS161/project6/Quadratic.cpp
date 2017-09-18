/*******
 * Author: Patrick Moore
 * Date: July 23, 2017
 * Description: Quadratic class implementation.
 *******************************/

#include "Quadratic.hpp"
#include <cmath>

using std::pow;

/****
 *
 * Description: This default constructor initializes 
 *              all coefficient values to 1.0
 *
 *****/
Quadratic::Quadratic()
{
  setA(1.0);
  setB(1.0);
  setC(1.0);
}


/****
 *
 * Description: Constructor that sets the value of each coefficient.
 *
 *****/
Quadratic::Quadratic(double aValue, double bValue, double cValue)
{
  setA(aValue);
  setB(bValue);
  setC(cValue);
}


/****
 *
 * Description: Returns the current value of a
 *
 *****/
double Quadratic::getA()
{
  return a;
}


/****
 *
 * Description: Returns the current value of b
 *
 *****/
double Quadratic::getB()
{
  return b;
}


/****
 *
 * Description: Returns the current value of c
 *
 *****/
double Quadratic::getC()
{
  return c;
}


/****
 *
 * Description: The value sumbitted is set to a
 *
 *****/
void Quadratic::setA(double value)
{
  a = value;
}


/****
 *
 * Description: The value sumbitted is set to b
 *
 *****/
void Quadratic::setB(double value)
{
  b = value;
}

/****
 *
 * Description: The value sumbitted is set to c
 *
 *****/
void Quadratic::setC(double value)
{
  c = value;
}

/*****************
 *
 * Description: Method that returns a result based on a given x value.
 *
 ****************/
double Quadratic::valueFor(double x)
{
  double y;
  y = a * pow(x, 2) + b * x + c;
  return y;
}

/****
 *
 * Description: Method that returns the number of real roots.
 *
 *****/
int Quadratic::numRealRoots()
{
  double disc;
  disc = pow(b, 2) - 4 * a * c;
  if (disc < -0.00001)
  {
    return 0;
  } else if (disc > 0.00001)
  {
    return 2;
  } else 
  {
    return 1;
  } 
}