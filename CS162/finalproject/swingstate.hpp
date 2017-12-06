/**
 * Author: Patrick Moore
 * Date: November 29, 2017
 * Description: 
 * */

#ifndef SWINGSTATE_HPP
#define SWINGSTATE_HPP

#include "state.hpp"

class SwingState : public State
{
private:
  int p1ActionCount = 0;
  int aiActionCount = 0;
public:
  SwingState(string);
  int calcVotes(Player &, Action, int &);
};

#endif