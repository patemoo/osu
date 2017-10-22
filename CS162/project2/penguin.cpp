/**
 * Author: Patrick Moore
 * Date: October 17, 2016
 * Description: Penguin class implementation
 *              animal params: age, babies, payoff, cost, foodCost
 * */

#include "penguin.hpp"

Penguin::Penguin(Age age) 
: Animal(age, 5, 100.00, 1000.00)
{
  this->foodCost = 10.00;
}

/**
 * 
 * */
double Penguin::getFoodCost()
{
  return this->foodCost;
}