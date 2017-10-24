/**
 * Author: Patrick Moore
 * Date: October 22, 2017
 * Description: Building class implementation.
 * */

#include "building.hpp"

Building::Building(string name, int size, string address)
{
  this->name = name;
  this->size = size;
  this->address = address;
}

string Building::getName()
{
  return this->name;
}

int Building::getSize()
{
  return this->size;
}

string Building::getAddress()
{
  return this->address;
}