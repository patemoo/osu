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
  
public:
  SwingState(string);
  void moveOn(Player *);
};

#endif