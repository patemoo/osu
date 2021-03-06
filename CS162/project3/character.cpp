/**
 * Author: Patrick Moore
 * Date: November 4, 2017
 * Description: 
 * */

#include "character.hpp"


Character::Character(string typeName, DieType attackDie, DieType defenseDie, int armor, int strengthPoints)
{
  this->typeName = typeName;
  this->attackDie = attackDie;
  this->defenseDie = defenseDie;
  this->armor = armor;
  this->strengthPoints = strengthPoints;
}

string Character::getTypeName()
{
  return this->typeName;
}

DieType Character::getAttackDie()
{
  return this->attackDie;
}

DieType Character::getDefenseDie()
{
  return this->defenseDie;
}

void Character::setDefenseDie(DieType die)
{
  this->defenseDie = die;
}

int Character::getArmor()
{
  return this->armor;
}

int Character::getStrengthPoints()
{
  return this->strengthPoints;
}

void Character::setStrengthPoints(int points)
{
  this->strengthPoints = points;
}

void Character::decreaseStrengthPoints(int damage)
{
  this->strengthPoints -= damage;
}


int Character::calcDamage(int attack, int defense, int armor, int strength)
{
  int damage;
  if (attack == 60)
  {
    cout << "\nMedusa uses glare!" << endl;
    damage = strength;
  }
  else
  {
    damage = attack - defense - armor;
    cout << "Attack roll: " << attack << endl;
    cout << "Defense roll: " << defense << " + armor: " << armor << endl;
  }

  return damage;
}

void Character::takeDamage(Character *self, int damage)
{
  if (damage > 0)
  {
    cout << "Damage inflicted: " << damage << endl;
    self->decreaseStrengthPoints(damage);
  }
  else
  {
    cout << "Damage inflicted: 0" << endl;
  }
}


/**
 * Description: simulate the respective dice rolls.
 * */
int Character::roll(DieType type)
{
  int roll1 = 0;
  int roll2 = 0;
  int roll3 = 0;

  switch (type)
  {
    case DieType::_1d6:
      roll1 = rand() % 6 + 1;
      break;
    case DieType::_2d6:
      roll1 = rand() % 6 + 1;
      roll2 = rand() % 6 + 1;
      break;
    case DieType::_3d6:
      roll1 = rand() % 6 + 1;
      roll2 = rand() % 6 + 1;
      roll3 = rand() % 6 + 1;
      break;
    case DieType::_2d10:

      roll1 = rand() % 10 + 1;
      roll2 = rand() % 10 + 1;
      break;
    case DieType::_1d12:
      roll1 = rand() % 12 + 1;
      break;
  }

  return (roll1 + roll2 + roll3);
}