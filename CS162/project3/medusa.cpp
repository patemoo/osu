/**
 * Author: Patrick Moore
 * Date: November 4, 2017
 * Description: 
 * */

#include "medusa.hpp"

Medusa::Medusa() : 
Character("Medusa", DieType::_2d6, DieType::_1d6, 3, 8) 
{
}

int Medusa::attack()
{
  return this->roll(this->getAttackDie());
}

void Medusa::defense(int attackValue)
{
  
}