/**********************************************
 * Author: Patrick Moore
 * Date: July 19, 2017
 * Description: Taxicab class implementation.
 * ********************************************/

#include <cmath>
#include "Taxicab.hpp"
using std::abs;

// default constructor:
Taxicab::Taxicab()
{
  x   = 0;
  y   = 0;
  odo = 0;
}

Taxicab::Taxicab(int xCoord, int yCoord)
{
  x   = xCoord;
  y   = yCoord;
  odo = 0;
}

int Taxicab::getXCoord()
{
  return x;
}

int Taxicab::getYCoord()
{
  return y;
}

int Taxicab::getDistanceTraveled()
{
  return odo;
}

void Taxicab::moveX(int units)
{
  x += units;
  odo += abs(units);
}

void Taxicab::moveY(int units)
{
  y += units;
  odo += abs(units);
}
