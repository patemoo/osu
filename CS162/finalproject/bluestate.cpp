/**
 * Author: Patrick Moore
 * Date: November 29, 2017
 * Description: 
 * */

#include "bluestate.hpp"

#include <iostream>
using std::cout;
using std::endl;

BlueState::BlueState(string name) : State(name)
{

}

/**
 * 
 * */
void BlueState::moveOn(Player *player)
{
  cout << "\nWhere would you like to campaign next?\n" << endl;

  player->setLocation(State::moveMenu());
}