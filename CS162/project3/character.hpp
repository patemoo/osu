/**
 * Author: Patrick Moore
 * Date: November 4, 2017
 * Description: 
 * */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
using std::string;

#include <cstdlib>
using std::rand;

#include <iostream>
using std::cout;
using std::endl;

enum DieType{_1d6, _2d6, _3d6, _2d10, _1d12};

class Character
{
private:
  string typeName = "Char Name";
  DieType attackDie;
  DieType defenseDie;
  int armor;
  int strengthPoints;
public:
  Character(string, DieType, DieType, int, int);
  virtual int attack() = 0;
  virtual bool defense(int) = 0;
  string getTypeName();
  DieType getAttackDie();
  DieType getDefenseDie();
  void setDefenseDie(DieType);
  int getArmor();
  int getStrengthPoints();
  void setStrengthPoints(int);
  void decreaseStrengthPoints(int);
  int calcDamage(int, int, int, int);
  void takeDamage(Character *, int);
  int roll(DieType);
};

#endif