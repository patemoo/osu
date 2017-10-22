/**
 * Author: Patrick Moore
 * Date: October 17, 2016
 * Description: Zoo class implementation
 * */

#include "zoo.hpp"

#include <cstdlib>
using std::rand;


/**
 * Description:
 * */
Zoo::Zoo()
{

}


/**
 * Description:
 * */
void Zoo::addAnimal(AnimalName name, int qty, Age age)
{
  for (int i=0; i<qty; i++)
  {
    switch (name)
    {
      case TIGER:
      {
        Tiger tiger(age);
        this->tigers.push_back(tiger);
      }
      break;
      case PENGUIN:
      {
        Penguin penguin(age);
        this->penguins.push_back(penguin);
      }
      break;
      case TURTLE:
      {
        Turtle turtle(age);
        this->turtles.push_back(turtle);
      }
      break;
    }
  }
}


/**
 * Description:
 * */
int Zoo::removeRandomAnimal()
{
  int randomAnimal = rand() % 3;

  switch (randomAnimal)
  {
    case TIGER:
    {
      int tigerCount = this->getAnimalCount(TIGER);
      int tigerIndex = rand() % tigerCount;
      this->tigers.erase(this->tigers.begin() + tigerIndex);
    }
    break;
    case PENGUIN:
    {
      int penguinCount = this->getAnimalCount(PENGUIN);
      int penguinIndex = rand() % penguinCount;
      this->penguins.erase(this->penguins.begin() + penguinIndex);
    }  
    break;
    case TURTLE:
    {
      int turtleCount = this->getAnimalCount(TURTLE);
      int turtleIndex = rand() % turtleCount;
      this->turtles.erase(this->turtles.begin() + turtleIndex);
    }
    break;
  }
  return randomAnimal;
}


/**
 * Description:
 * */
void Zoo::increaseAgeOnAll()
{
  // loop through and increase the age of each tiger in the zoo
  for (Tiger &animal : this->tigers)
  {
    animal.increaseAge();
  }
  // loop through and increase the age of each penguin in the zoo
  for (Penguin &animal : this->penguins)
  {
    animal.increaseAge();
  }
  // loop through and increase the age of each turtle in the zoo
  for (Turtle &animal : this->turtles)
  {
    animal.increaseAge();
  }
}


/**
 * Description: return the size of the vector corresponding to the animal name enum passed in.
 * */
int Zoo::getAnimalCount(AnimalName name)
{
  switch (name)
  {
    case TIGER:
      return this->tigers.size();
      break;
    case PENGUIN:
      return this->penguins.size();
      break;
    case TURTLE:
      return this->turtles.size();
      break;
  }
}

vector<Tiger> Zoo::getTigers()
{
  return this->tigers;
}

vector<Penguin> Zoo::getPenguins()
{
  return this->penguins;
}

vector<Turtle> Zoo::getTurtles()
{
  return this->turtles;
}