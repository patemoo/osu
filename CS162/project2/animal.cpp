/**
 * Author: Patrick Moore
 * Date: October 17, 2016
 * Description: Animal class implementation
 * */

#include "animal.hpp"


Animal::Animal(int age, int babies, double payoff, double cost)
{
  this->age = age;
  this->numberOfBabies = babies;
  this->payoff = payoff;
  this->cost = cost;
}


/**
 * Description: increase the animals age by 1.
 * */
void Animal::increaseAge()
{
  this->age += 1;
}

/**
 * Description: returns a bool value dependent on the age of the animal
 * */
bool Animal::isAdult()
{
  if (this->age < 3)
  {
    return false;
  }
  else
  {
    return true;
  }
}


/**
 * Description: 
 * */
int Animal::getNumberOfBabies()
{
  return this->numberOfBabies;
}

/**
 * Description: 
 * */
double Animal::getPayoff()
{
  return this->payoff;
}

/**
 * Description: 
 * */
double Animal::getCost()
{
  return this->cost;
}

/**
 * Description: 
 * */
double Animal::getBaseFoodCost()
{
  return this->baseFoodCost;
}