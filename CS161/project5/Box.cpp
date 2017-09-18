/*******************************************
 * Author: Patrick Moore
 * Date: July 19, 2017
 * Description: Box class implementation.
 * ****************************************/

#include "Box.hpp"

Box::Box()
{
  height = 1;
  width = 1;
  length = 1;
}

Box::Box(double h, double w, double l)
{
  height = h;
  width = w;
  length = l;
}

bool Box::setHeight(double h)
{
  bool valid = true;
  
  if (h >= 0)
    height = h;
  else 
    valid = false;

  return valid; 
}

bool Box::setWidth(double w)
{
  bool valid = true;

  if (w >= 0)
    width = w;
  else
    valid = false;

  return valid;
}

bool Box::setLength(double l)
{
  bool valid = true;

  if (l >= 0)
    length = l;
  else
    valid = false;

  return valid;
} 

double Box::calcVolume()
{
  return height * width * length;
}

double Box::calcSurfaceArea()
{
  double surfaceArea;
  surfaceArea = height * width * 2;
  surfaceArea += width * length * 2;
  surfaceArea += length * height * 2; 

  return surfaceArea; 
}