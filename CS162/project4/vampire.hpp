/**
 * Author: Patrick Moore
 * Date: November 4, 2017
 * Description: 
 * */

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "character.hpp"

class Vampire : public Character
{
private:
public:
  Vampire();
  int attack();
  bool defense(int);
};

#endif