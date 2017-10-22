/**
 * Author: Patrick Moore
 * Date: October 17, 2016
 * Description: Turtle class implementation
 *              animal params: age, babies, payoff, cost, foodCost
 * */

#include "turtle.hpp"


Turtle::Turtle(Age age)
: Animal(age, 10, 5.00, 100.00)
{
  this->foodCost = 5.00;
}

/**
 * 
 * */
double Turtle::getFoodCost()
{
  return this->foodCost;
}