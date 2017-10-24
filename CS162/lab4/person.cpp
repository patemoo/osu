/**
 * Author: Patrick Moore
 * Date: October 22, 2017
 * Description: Person class implementation.
 * */

#include "person.hpp"

/**
 * Description: Person constructor. takes a name param.
 * */
Person::Person(string name)
{
  this->name = name;
}

string Person::getName()
{
  return this->name;
}

int Person::getAge()
{
  return this->age;
}

void Person::setAge(int age)
{
  this->age = age;
}