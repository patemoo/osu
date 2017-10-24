/**
 * Author: Patrick Moore
 * Date: October 22, 2017
 * Description: University class implementation.
 * */

#include "university.hpp"

#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setprecision;

/**
 * Description: University class constructor.
 * */ 
University::University()
{
}

/**
 * Description: adds a building to the buildings vector.
 * */
void University::addBuilding(Building* building)
{
  this->buildings.push_back(building);
}

/**
 * Description: prints the info for each building in the system.
 * */
void University::printBuildings()
{
  int length = this->buildings.size();
  for (int i=0; i<length; i++)
  {
    cout << "Name: " << this->buildings[i]->getName() << endl;
    cout << "Size: " << this->buildings[i]->getSize() << "sqft" << endl;
    cout << "Address: " << this->buildings[i]->getAddress() << endl;
    cout << endl;
  }
}

/**
 * Description: adds a person to the people vector.
 * */
void University::addPerson(Person* person)
{
  this->people.push_back(person);
}

/**
 * Description: prints all people in the system.
 * */
void University::printPeople()
{
  
  int length = this->people.size();
  for (int i=0; i<length; i++)
  {
    cout << "Name: " << this->people[i]->getName() << endl;
    cout << "Age: " << this->people[i]->getAge() << endl;
    if (this->people[i]->isStudent())
    {
      cout << "GPA: ";
    }
    else 
    {
      cout << "Rating: ";
    }
    cout << setprecision(2) << this->people[i]->getScore() << endl;
    cout << endl;
  }
}

/**
 * Description: return the university's name.
 * */
string University::getName()
{
  return this->name;
}

/**
 * Description: return people vector.
 * */
vector<Person*> University::getPeople()
{
  return this->people;
}