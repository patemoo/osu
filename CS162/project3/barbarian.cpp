/**
 * Author: Patrick Moore
 * Date: November 4, 2017
 * Description: 
 * */

#include "barbarian.hpp"

Barbarian::Barbarian() : 
Character("Barbarian", DieType::_2d6, DieType::_2d6, 0, 12) 
{
}

int Barbarian::attack()
{
  return this->roll(this->getAttackDie());
}

void Barbarian::defense(int attackValue)
{

}