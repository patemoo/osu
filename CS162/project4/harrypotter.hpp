/**
 * Author: Patrick Moore
 * Date: November 4, 2017
 * Description: 
 * */

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "character.hpp"

class HarryPotter : public Character
{
private:
public:
  HarryPotter();
  int attack();
  bool defense(int);
};

#endif