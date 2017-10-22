/**
 * Author: Patrick Moore
 * Date: October 17, 2016
 * Description: Tiger class implementation
 *              animal params: age, babies, payoff, cost, foodCost
 * */

#include "tiger.hpp"

// Tiger::Tiger() 
// : Animal(1, 1, 2000.00, 10000.00)
// {
//   this->foodCost = 50.00;
// }

Tiger::Tiger(Age age) 
: Animal(age, 1, 2000.00, 10000.00)
{
  this->foodCost = 50.00;
}

/**
 * 
 * */
double Tiger::getFoodCost()
{
  return this->foodCost;
}