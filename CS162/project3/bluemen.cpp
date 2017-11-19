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

bool BlueMen::defense(int attackValue)
{
  int strength = this->getStrengthPoints();

  // mob logic
  if (strength > 4 && strength <= 8)
  {
    this->setDefenseDie(DieType::_2d6);
  } 
  else if (strength <= 4)
  {
    this->setDefenseDie(DieType::_1d6);
  }

  int roll = this->roll(this->getDefenseDie());
  int armor = this->getArmor();
  int damage;

  damage = attackValue - roll - armor;
  cout << "Attack roll: " << attackValue << endl;
  cout << "Defense roll: " << roll << " + armor: " << armor << endl;
  this->takeDamage(this, damage);

  if (this->getStrengthPoints() <= 0)
    {
      cout << "\nBlue men are all dead." << endl;
      return false;
    }
  return true;
}