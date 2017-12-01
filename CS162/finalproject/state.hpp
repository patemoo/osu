/**
 * Author: Patrick Moore
 * Date: November 29, 2017
 * Description: State class interface
 * */

#ifndef STATE_HPP
#define STATE_HPP

#include "player.hpp"

#include <string>
using std::string;

class State
{
private:
  State *top = nullptr;
  State *left = nullptr;
  State *right = nullptr;
  State *bottom = nullptr;
  string name;
  int visitVotes = 0;

public:
  State(string);
  void setSides(State *, State *, State *, State *);
  virtual void moveOn(Player *) = 0;
  string getName();
  int getVisitVotes();
  void addVisitVotes(int);
  void removeVisitVotes(int);
  State * moveMenu();
};

#endif