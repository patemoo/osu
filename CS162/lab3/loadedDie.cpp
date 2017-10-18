/**
 * Author: Patrick Moore
 * Date: October 15, 2017
 * Description: LoadedDie implementation
 * */

#include "loadedDie.hpp"

#include <cstdlib>
using std::rand;

/**
 * Description: Just passes through the sides param
 * */
LoadedDie::LoadedDie(int sides) : Die(sides)
{
}


/**
 * Description: logic to load the die. 25% you get the highest side.
 * */
int LoadedDie::roll()
{
  int result;

  if (rand() % 4 == 0)
  {
    result = this->getSides();
  }
  else
  {
    result = rand() % this->getSides() + 1;
  }
  return result;
}