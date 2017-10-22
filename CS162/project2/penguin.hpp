/**
 * Author: Patrick Moore
 * Date: October 17, 2016
 * Description: Penguin class interface
 * */

#include "animal.hpp"

#ifndef PENGUIN_HPP
#define PENGUIN_HPP

class Penguin : public Animal
{
  private:
   double foodCost;
  public: 
    Penguin(Age);
    double getFoodCost();
};

#endif