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


Player::Player(Party party, string name)
{
  this->party = party;
  this->name = name;
}


/**
 * Description: returns a text string of the players chosen political party.
 * */
string Player::getParty()
{
  string partyString;
  switch (this->party)
  {
    case 1:
      partyString = "Democrat";
    break;
    case 2:
      partyString = "Republican";
    break;
  }
  return partyString;
}

// returns the players identifier string.
string Player::getName()
{
  return this->name;
}

int Player::getVotes()
{
  return this->votes;
}

bool Player::addVotes(int votes)
{
  if (this->votes + votes > 270)
  {
    this->votes = 270;
    return true;
  }
  else 
  {
    this->votes += votes;
    return false;
  }
}

/**
 * 
 * */
void Player::removeVotes(int votes)
{
  this->votes -= votes;
}

/**
 * 
 * */
void Player::setLocation(State *location)
{
  cout << "\n" << this->name << " arrived in " << location->getName() << endl;

  this->currentLocation = location;
}

State * Player::getLocation()
{
  return this->currentLocation;
}