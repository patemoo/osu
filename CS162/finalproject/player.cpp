/**
 * Author: Patrick Moore
 * Date: November 29, 2017
 * Description: Player class implementation
 * */

#include "player.hpp"
#include "state.hpp"

#include <iostream>
using std::cout;
using std::endl;

Player::Player(Party party)
{
  this->party = party;
}


/**
 * 
 * */
Party Player::getParty()
{
  return this->party;
}

/**
 * 
 * */
void Player::setLocation(State *location)
{
  cout << "\nYou have arrived in " << location->getName() << "\n" << endl;

  this->currentLocation = location;
}

State * Player::getLocation()
{
  return this->currentLocation;
}