/**
 * Author: Patrick Moore
 * Date: November 29, 2017
 * Description: 
 * */

#ifndef BLUESTATE_HPP
#define BLUESTATE_HPP

#include "state.hpp"

class BlueState : public State
{
private:
  
public:
  BlueState(string);
  void moveOn(Player *);
};

#endif