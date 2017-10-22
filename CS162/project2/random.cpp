/**
 * Author: Patrick Moore
 * Date: October 17, 2016
 * Description: random event function implementation
 * */

#include "random.hpp"

#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>
using std::rand;


/**
 * Description: Random event logic
 * */
double randomEvent(Zoo &zoo)
{
  srand(time(0));
  int randomInt = rand() % 4;
  double bonus = 0;
  
  enum Event {Sickness, AttendanceBoom, BabyBoom, Nothing};

  switch (randomInt)
  {
    case Event::Sickness:
      sicknessDeath(zoo);
      break;
    case Event::AttendanceBoom:
      bonus = attendanceBoom(zoo.getAnimalCount(TIGER));
      break;
    case Event::BabyBoom:
      babyBoom(zoo);
      break;  
    case Event::Nothing:
      normalDay();
      break;
  }
  return bonus;
}

/**
 * Description: Kill an animal at random
 * */
void sicknessDeath(Zoo &zoo)
{
  switch (zoo.removeRandomAnimal())
  {
    case TIGER:
      cout << "\nA tiger has died due to sickness.\n" << endl;
      break;
    case PENGUIN:
      cout << "\nA penguin has died due to sickness.\n" << endl;
      break;
    case TURTLE:
      cout << "\nA turtle has died due to sickness.\n" << endl;
      break;
  }
}


/**
 * Description: Pay out bonus
 * */
double attendanceBoom(int tigerCount)
{
  srand(time(0));
  int amountPerTiger = rand() % 250 + 250;
  double bonus = static_cast<double>(amountPerTiger * tigerCount);

  cout << "\nToday is National Tiger Day! Tigers generate money today!" << endl;
  cout << "You made: $" << amountPerTiger << " extra dollars for each tiger you own!\n" << endl;
  
  return bonus;
}


/**
 * Description: Animal at random gives birth
 * */
void babyBoom(Zoo &zoo)
{
  srand(time(0));
  int randomAnimal = rand() % 3;
  bool tigersNotChecked = true;
  bool penguinsNotChecked = true;

  switch (randomAnimal)
  {
    case TIGER:
      for (int i=0; i<zoo.getAnimalCount(TIGER); i++)
      {
        if (zoo.getTigers()[i].isAdult())
        {
          int babyNum = zoo.getTigers()[0].getNumberOfBabies();
          zoo.addAnimal(TIGER, babyNum, Age::Baby);
          cout << "\nA tiger had a baby!!\n" << endl;
          return;
        }
      }
      tigersNotChecked = false;
      // if there are no adults move on to next case.
    case PENGUIN:
      for (int i=0; i<zoo.getAnimalCount(PENGUIN); i++)
      {
        if (zoo.getPenguins()[i].isAdult())
        {
          int babyNum = zoo.getPenguins()[0].getNumberOfBabies();
          zoo.addAnimal(PENGUIN, babyNum, Age::Baby);
          cout << "\nA penguin had babies!!\n" << endl;
          return;
        }
      }
      penguinsNotChecked = false;
      // if there are no adults move on to next case.
    case TURTLE:
      for (int i=0; i<zoo.getAnimalCount(TURTLE); i++)
      {
        if (zoo.getTurtles()[i].isAdult())
        {
          int babyNum = zoo.getTurtles()[0].getNumberOfBabies();
          zoo.addAnimal(TURTLE, babyNum, Age::Baby);
          cout << "\nA turtle had babies!!\n" << endl;
          return;
        }
      }
      if (penguinsNotChecked)
      {
        for (int i=0; i<zoo.getAnimalCount(PENGUIN); i++)
        {
          if (zoo.getPenguins()[i].isAdult())
          {
            cout << "\nA penguin had babies!!\n" << endl;
            return;
          }
        }
      }
      if (tigersNotChecked)
      {
        for (int i=0; i<zoo.getAnimalCount(TIGER); i++)
        {
          if (zoo.getTigers()[i].isAdult())
          {
            cout << "\nA tiger had a baby!!\n" << endl;
            return;
          }
        }
      }
      // If there are no adult animals, no births occur, revert to a normal day.
      normalDay();
      break;
  }
}


/**
 * Description:
 * */
void normalDay()
{
  cout << "\nNormal day at the zoo. Not much going on today.\n" << endl;
}