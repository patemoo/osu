/**
 * Author: Patrick Moore
 * Date: November 4, 2017
 * Description: 
 * */

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "character.hpp"

class Medusa : public Character
{
private:
public:
  Medusa();
  int attack();
  bool defense(int);
};

#endif