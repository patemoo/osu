/**
 * Author: Patrick Moore
 * Date: July 29, 2017
 * Description: Person class implementation.
 **/

 #include "Person.hpp"

/**
 * Description: This constructor takes in a string for name and a double for age
 *              and sets the respective member variables.
 **/
Person::Person(string nameValue, double ageValue)
{
  name = nameValue;
  age = ageValue;
}


string Person::getName()
{
  return name;
}


double Person::getAge()
{
  return age;
}