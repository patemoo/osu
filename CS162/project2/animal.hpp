/**
 * Author: Patrick Moore
 * Date: October 17, 2016
 * Description: Animal class interface
 * */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

enum Age{Baby, New, Adult = 3};

class Animal
{
  private:
    int age;
    int numberOfBabies;
    double payoff;
    double cost;
    double baseFoodCost = 10.00;
  public:
    Animal(int, int, double, double);
    void increaseAge();
    bool isAdult();
    int getNumberOfBabies();
    double getPayoff();
    double getCost();
    double getBaseFoodCost();
};

#endif