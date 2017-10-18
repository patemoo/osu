/**
 * Author: Patrick Moore
 * Date: October 17, 2016
 * Description: Animal class interface
 * */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
  private:
    int age = 1;
    int const babyQty;
    int const payoff;
    double const cost;
    double const foodCost;
  public:
    Animal();
};

#endif