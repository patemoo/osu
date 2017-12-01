/**
 * Author: Patrick Moore
 * Date: November 29, 2017
 * Description: 
 * */

#include "redstate.hpp"

#include <iostream>
using std::cout;
using std::endl;

RedState::RedState(string name) : State(name)
{

}

/**
 * 
 * */
void RedState::moveOn(Player *player)
{
  cout << "\nWhere would you like to campaign next?\n" << endl;

  player->setLocation(State::moveMenu());
}