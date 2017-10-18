/**
 * Author: Patrick Moore
 * Date: October 15, 2017
 * Description: game class implementation
 * */

#include "game.hpp"
#include "die.hpp"
#include "loadedDie.hpp"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

/**
 * Description: Game constructor
 * */
Game::Game(int rounds, int p1Type, int p1Sides, int p2Type, int p2Sides)
{
  this->rounds = rounds;
  this->p1DieType = p1Type;
  this->p1DieSides = p1Sides;
  this->p2DieType = p2Type;
  this->p2DieSides = p2Sides;
}


/**
 * Description: Handles the game play loop. 
 * */
void Game::play()
{

  // loop through each round of the game.
  for (int i=0; i<rounds; i++)
  {
    cout << "Round " << i+1 << endl;

    int p1Roll = this->getRoll(p1DieType, p1DieSides);
    int p2Roll = this->getRoll(p2DieType, p2DieSides);

    cout << "Player One, using a " << this->getType(p1DieType) 
    << " " << p1DieSides << " sided die, " 
    << "rolls a " << p1Roll << endl;

    cout << "Player Two, using a " << this->getType(p2DieType) 
    << " " << p2DieSides << " sided die, " 
    << "rolls a " << p2Roll << endl;

    if (p1Roll > p2Roll)
    {
      cout << "Player One gets a point." << endl;
      this->p1Score += 1;
    }
    else if (p2Roll > p1Roll)
    {
      cout << "Player Two gets a point." << endl;
      this->p2Score += 1;
    }
    else 
    {
      cout << "No points awarded." << endl;
    }

    cout << "Score: Player One: " << this->p1Score << " Player Two: " << this->p2Score << endl;
    cout << endl;
    cout << endl;
  }

  // check final score:
  if (p1Score > p2Score)
    {
      cout << "Player One wins the game!" << endl;
    }
    else if (p2Score > p1Score)
    {
      cout << "Player Two wins the game!" << endl;
    }
    else 
    {
      cout << "Draw! no winner" << endl;
    }
    cout << "Final score: Player One: " << this->p1Score << " Player Two: " << this->p2Score << endl;
    cout << endl;
}


/**
 * Description: Creates and rolls the correct die then returns the reslut
 * */
int Game::getRoll(int type, int sides)
{
  int result;
  if (type == 1)
  {
    Die rDie(sides);
    result = rDie.roll();
  }
  else
  {
    LoadedDie lDie(sides);
    result = lDie.roll();
  }

  return result;
}


/**
 * Description: returns a string for the die type.
 * */
string Game::getType(int type)
{
  if (type == 1)
  {
    return "regular";
  }
  else 
  {
    return "loaded";
  }
}



