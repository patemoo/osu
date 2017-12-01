/**
 * Author: Patrick Moore
 * Date: November 29, 2017
 * Description: 
 * */

#include "swingstate.hpp"

#include <iostream>
using std::cout;
using std::endl;

SwingState::SwingState(string name) : State(name)
{

}

/**
 * 
 * */
void SwingState::moveOn(Player *player)
{
  cout << "\nWhere would you like to campaign next?\n" << endl;

  player->setLocation(State::moveMenu());
}