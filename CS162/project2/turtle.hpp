/**
 * Author: Patrick Moore
 * Date: October 17, 2016
 * Description: Turtle class interface
 * */

#include "animal.hpp"

#ifndef TURTLE_HPP
#define TURTLE_HPP

class Turtle : public Animal
{
  private:
   double foodCost;
  public:
    Turtle(Age);
    double getFoodCost();
};

#endif