/**
 * Author: Patrick Moore
 * Date: November 4, 2017
 * Description: 
 * */

#include "bluemen.hpp"

BlueMen::BlueMen() : 
Character("Blue Men", DieType::_2d10, DieType::_3d6, 3, 12)
{
}

int BlueMen::attack()
{
  return this->roll(this->getAttackDie());
}

void BlueMen::defense(int attackValue)
{
  
}