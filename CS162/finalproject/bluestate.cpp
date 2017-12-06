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

int BlueState::calcVotes(Player &player, Action action, int &count)
{
  int votes = rand() % 9;
  switch (action)
  {
    case Action::speech:
      votes += 16;
      if (count > 0)
      {
        votes /= count;
      }
      count += 1;
      break;
    case Action::doors:
      votes += 8;
      break;
    case Action::baby:
      votes += 2;
      break;
  }
  
  // Campaigning in red states benefits democrats over republicans
  if (player.getParty() == "Democrat")
  {
    votes *= 1.5;
  }
  else
  {
    votes *= .75;
  }

  return votes;
}