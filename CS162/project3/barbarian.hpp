/**
 * Author: Patrick Moore
 * Date: November 4, 2017
 * Description: 
 * */

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "character.hpp"

class Barbarian : public Character
{
private:
public:
  Barbarian();
  int attack();
  bool defense(int);
};

#endif