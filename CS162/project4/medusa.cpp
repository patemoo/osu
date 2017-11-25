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
  int roll = this->roll(this->getAttackDie());
  if (roll == 12)
  {
    return 60;
  }
  else
  {
    return roll;
  }
}

bool Medusa::defense(int attackValue)
{
  int roll = this->roll(this->getDefenseDie());
  int armor = this->getArmor();
  int strength = this->getStrengthPoints();
  int damage;

  damage = this->calcDamage(attackValue, roll, armor, strength);
  this->takeDamage(this, damage);

  if (this->getStrengthPoints() <= 0)
    {
      // cout << "\nMedusa has been defeated." << endl;
      return false;
    }
  return true;
}