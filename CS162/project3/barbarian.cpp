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

bool Barbarian::defense(int attackValue)
{
  int roll = this->roll(this->getDefenseDie());
  int armor = this->getArmor();
  int strength = this->getStrengthPoints();
  int damage;

  damage = this->calcDamage(attackValue, roll, armor, strength);
  this->takeDamage(this, damage);


  if (this->getStrengthPoints() <= 0)
    {
      cout << "\nThe barbarian is defeated." << endl;
      return false;
    }
  return true;
}