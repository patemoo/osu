/**
 * Author: Patrick Moore
 * Date: November 29, 2017
 * Description: 
 * */

#ifndef REDSTATE_HPP
#define REDSTATE_HPP

#include "state.hpp"

class RedState : public State
{
private:
  
public:
  RedState(string);
  int calcVotes(Player &, Action, int &);
};

#endif