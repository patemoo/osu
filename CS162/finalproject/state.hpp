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

enum Action{speech = 1, doors, baby};

class State
{
private:
  State *top = nullptr;
  State *left = nullptr;
  State *right = nullptr;
  State *bottom = nullptr;
  string name;
public:
  State(string);
  void setSides(State *, State *, State *, State *);
  void moveOn(Player &);
  virtual int calcVotes(Player &, Action, int &) = 0;
  string getName();
  State * moveMenu(Player &);
};

#endif