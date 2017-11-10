/**
 * Author: Patrick Moore
 * Date: November 4, 2017
 * Description: 
 * */

#include "harrypotter.hpp"

HarryPotter::HarryPotter() : 
Character("Harry Potter", DieType::_2d6, DieType::_2d6, 0, 10)
{
}

int HarryPotter::attack()
{
  return this->roll(this->getAttackDie());
}

void HarryPotter::defense(int attackValue)
{
  
}