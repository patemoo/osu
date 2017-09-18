/**********************************************************************
 * Author: Patrick Moore
 * Date: July 14, 2017
 * Description: This program calculates the distance an object falls
 *              due to gravity in a specific time period.
 * ********************************************************************/

#include <cmath>

double fallDistance(double time) 
{
  const double gravity = 9.8;
  double distance;

  distance = 0.5 * gravity * pow(time, 2);

  return distance; 
}

