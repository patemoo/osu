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

int SwingState::calcVotes(Player &player, Action action, int &count)
{
  int votes = rand() % 9;
  int actionCount;

  if (player.getName() == "You")
  {
    actionCount = this->p1ActionCount;
  }
  else
  {
    actionCount = this->aiActionCount;
  }
  switch (action)
  {
    case Action::speech:
      votes += 16;
      votes += (actionCount * 2);
      break;
    case Action::doors:
      votes += 8;
      votes += (actionCount * 2);
      break;
    case Action::baby:
      votes += 2;
      votes += (actionCount * 2);
      break;
  }
  if (player.getName() == "You")
  {
    this->p1ActionCount += 1;
  }
  else
  {
    this->aiActionCount += 1;
  }  

  return votes;
}