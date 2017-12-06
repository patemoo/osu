/**
 * Author: Patrick Moore
 * Date: November 29, 2017
 * Description: State class implementation 
 * */

#include "state.hpp"
#include "menu.hpp"

#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>
using std::rand;


State::State(string name)
{
  this->name = name;
}

/**
 * Description: takes in State pointers to set as the adjacent campaign destinations.
 * */
void State::setSides(State *top, State *left, State *right, State *bottom)
{
  this->top = top;
  this->left = left;
  this->right = right;
  this->bottom = bottom;
}

/**
 * Description: returns the state's name
 * */
string State::getName()
{
  return this->name;
}


/**
 * Description: creates a menu of adjacent states to move to based on where the player currently is.
 * */
State * State::moveMenu(Player &player)
{
  int index = 0;
  int choice = 0;
  int menuIndex = 0;
  int topNum = 0;
  int leftNum = 0;
  int rightNum = 0;
  int bottomNum = 0;
  vector<string> moveOptions{};

  if (this->top != nullptr)
  {
    menuIndex += 1;
    topNum = menuIndex;
    moveOptions.push_back(this->top->getName());
  }
  if (this->left != nullptr)
  {
    menuIndex += 1;
    leftNum = menuIndex;
    moveOptions.push_back(this->left->getName());
  }
  if (this->right != nullptr)
  {
    menuIndex += 1;
    rightNum = menuIndex;
    moveOptions.push_back(this->right->getName()); 
  }
  if (this->bottom != nullptr)
  {
    menuIndex += 1;
    bottomNum = menuIndex;
    moveOptions.push_back(this->bottom->getName());
  }

  if (player.getName() == "You")
  {
    cout << "\nWhere would you like to campaign next?\n" << endl;
    choice = menu(moveOptions);
  }
  else
  {
    choice = rand() % menuIndex + 1;
  }
  

  if (choice == topNum)
  {
    return this->top;
  }
  if (choice == leftNum)
  {
    return this->left;
  }
  if (choice == rightNum)
  {
    return this->right;
  }
  if (choice == bottomNum)
  {
    return this->bottom;
  }
  return nullptr;
}


/**
 * Description: sets the players location based on the result of the move menu.
 * */
void State::moveOn(Player &player)
{
  player.setLocation(this->moveMenu(player));
}
