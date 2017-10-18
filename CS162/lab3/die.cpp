/**
 * Author: Patrick Moore
 * Date: October 15, 2017
 * Description: Die class implementation 
 * */

#include "die.hpp"

#include <cstdlib>
using std::rand;

/**
 * Description: Constructor, sets side member var.
 * */
Die::Die(int sides)
{
  this->sides = sides;
}

/**
 * Description: returns a random number between 1 and the number of sides.
 * */
int Die::roll()
{
  return rand() % sides + 1;
}


/**
 * Description: returns the number of sides
 * */
int Die::getSides()
{
  return sides;
}

