/**
 * Author: Patrick Moore
 * Date: October 17, 2016
 * Description: main program implementation
 * */

#include "player.hpp"
#include "menu.hpp"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <cstdlib>
using std::rand;


void randomEvent(int, int, int);
void sicknessDeath();
void attendanceBoom();
void babyBoom();

int main()
{
  bool playing = true;
  Player tycoon;
  int tigerCount = 0;
  int penguinCount = 0;
  int turtleCount = 0;

  cout << "Welcome to Zoo Tycoon!" << endl;
  cout << "You have just become the own of your very own zoo." << endl;
  cout << "You currently have $" << tycoon.getBankRoll() << endl;

  cout << "You need to purchase a vew animals to put on display." << endl;
  cout << "" << endl; 

  

  // Day loop
  while (playing)
  {


    randomEvent(tigerCount, penguinCount, turtleCount);



    // prompt user to continue or end the game
    vector<string> continueOptions{"Keep playing", "End game"};
    if (menu(continueOptions) == 2)
    {
      playing = false;
    }

  }

  cout << "Game over." << endl;
  cout << "Goodbye." << endl;

  return 0;
}


/**
 * Description: Random event logic
 * */
void randomEvent(int tiCount, int pCount, int tuCount)
{
  int randomInt = random() % 4;
  
  enum Event {Sickness, AttendanceBoom, BabyBoom, Nothing};

  switch (randomInt)
  {
    case Event::Sickness:
      sicknessDeath();
      break;
    case Event::AttendanceBoom:
      attendanceBoom();
      break;
    case Event::BabyBoom:
      babyBoom();
      break;  
    case Event::Nothing:
      cout << "nothing" << endl;
      break;
  }
}


/**
 * Description: Kill an animal at random
 * */
void sicknessDeath()
{
  cout << "sickness" << endl;
}


/**
 * Description: Pay out bonus
 * */
void attendanceBoom()
{
  cout << "attendance" << endl;
}


/**
 * Description: Animal at random gives birth
 * */
void babyBoom()
{
  cout << "baby" << endl;
}