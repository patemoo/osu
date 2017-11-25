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

bool Vampire::defense(int attackValue)
{
  int charm = rand() % 2;
  int roll = this->roll(this->getDefenseDie());
  int armor = this->getArmor();
  int strength = this->getStrengthPoints();
  int damage;

  // charm logic
  if (charm == 1)
  {
    // cout << "The vampire uses charm, opponent does not attack." << endl;
  }
  else
  {
    damage = this->calcDamage(attackValue, roll, armor, strength);
    this->takeDamage(this, damage);
  }

  if (strength <= 0)
    {
      // cout << "\nThe vampire is defeated." << endl;
      return false;
    }
  return true;
}