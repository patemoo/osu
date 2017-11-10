/**
 * Author: Patrick Moore
 * Date: November 4, 2017
 * Description: 
 * */

#include "vampire.hpp"

Vampire::Vampire() : 
Character("Vampire", DieType::_1d12, DieType::_1d6, 1, 18) 
{
}

int Vampire::attack()
{
  return this->roll(this->getAttackDie());
}

void Vampire::defense(int attackValue)
{


}