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

bool HarryPotter::defense(int attackValue)
{
  bool usedHogwarts = false; 
  int roll = this->roll(this->getDefenseDie());
  int armor = this->getArmor();
  int strength = this->getStrengthPoints();
  int damage;
  
  damage = this->calcDamage(attackValue, roll, armor, strength);
  this->takeDamage(this, damage);

  if (this->getStrengthPoints() <= 0)
    {
      if (!usedHogwarts)
      {
        // cout << "\nHarry dies and comes back stronger!" << endl;
        this->setStrengthPoints(20);
        usedHogwarts = true;
      }
      else
      {
        // cout << "\nHarry Potter is dead." << endl;
        return false;
      }
      
    }
  return true;
}