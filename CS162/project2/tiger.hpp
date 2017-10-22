/**
 * Author: Patrick Moore
 * Date: October 17, 2016
 * Description: Tiger class interface
 * */

#include "animal.hpp"

#ifndef TIGER_HPP
#define TIGER_HPP

class Tiger : public Animal
{
  private:
    double foodCost;
  public: 
    Tiger(Age);
    double getFoodCost();
};

#endif