/**
 * Author: Patrick Moore
 * Date: November 29, 2017
 * Description: State class implementation 
 * */

#include "state.hpp"
#include "menu.hpp"


State::State(string name)
{
  this->name = name;
}

/**
 * 
 * */
void State::setSides(State *top, State *left, State *right, State *bottom)
{
  this->top = top;
  this->left = left;
  this->right = right;
  this->bottom = bottom;
}

/**
 * 
 * */
string State::getName()
{
  return this->name;
}

/**
 * 
 * */
int State::getVisitVotes()
{
  return this->visitVotes;
}


/**
 * 
 * */
void State::addVisitVotes(int votes)
{
  this->visitVotes += votes;
}

/**
 * 
 * */
void State::removeVisitVotes(int votes)
{
  this->visitVotes -= votes;
}


/**
 * 
 * */
State * State::moveMenu()
{
  int index = 0;
  int choice = 0;
  int menuIndex = 1;
  int topNum = 0;
  int leftNum = 0;
  int rightNum = 0;
  int bottomNum = 0;
  vector<string> moveOptions{};

  if (this->top != nullptr)
  {
    topNum = menuIndex;
    moveOptions.push_back(this->top->getName());
    menuIndex += 1;
  }
  if (this->left != nullptr)
  {
    leftNum = menuIndex;
    moveOptions.push_back(this->left->getName());
    menuIndex += 1;
  }
  if (this->right != nullptr)
  {
    rightNum = menuIndex;
    moveOptions.push_back(this->right->getName());
    menuIndex += 1;
  }
  if (this->bottom != nullptr)
  {
    bottomNum = menuIndex;
    moveOptions.push_back(this->bottom->getName());
  }

  choice = menu(moveOptions);

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
