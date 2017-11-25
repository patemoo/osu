/**
 * Author: Patrick Moore
 * Date: November 19, 2017
 * Description: 
 * */

#ifndef LINEUP_HPP
#define LINEUP_HPP

#include "lineupnode.hpp"

class Lineup
{
private:
  LineupNode *head = nullptr;
public:
  Lineup();
  ~Lineup();
  bool isEmpty();
  void addBack(Character *, string);
  Character * getFighterType();
  string getFighterName();
  void moveToBack();
  void removeDefeated(vector<string> *);
};

#endif