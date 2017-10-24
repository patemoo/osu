/**
 * Author: Patrick Moore
 * Date: October 17, 2016
 * Description: main program implementation
 * */

#include "player.hpp"
#include "menu.hpp"
#include "validate.hpp"
#include "tiger.hpp"
#include "zoo.hpp"
#include "random.hpp"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <cstdlib>
using std::rand;


void calcAndWithdrawFoodCost(Player &, Zoo &);
void calcAndDepositProfit(Player &, Zoo &, int);


int main()
{
  bool playing = true;
  bool haveMoney = true;
  int dayCount = 1;
  Player tycoon;
  int initialCount = 0;

  cout << "Welcome to Zoo Tycoon!" << endl;
  cout << "You have just become the proud owner of a brand new zoo." << endl;
  cout << "You currently have $" << tycoon.getBankRoll() << " in the bank." << endl;

  // Create zoo instance.
  Zoo zoo;

  // prompt user to pick quantity of initial animals.
  cout << "You need to purchase a few animals to get things going." << endl;
  cout << "Would you like to start with 1 or 2 tigers? ($10,000.00)" << endl;
  cinValidInt(initialCount, 1, 2);
  zoo.addAnimal(TIGER, initialCount, Age::New);
  double tigerCost = zoo.getTigers()[0].getCost();

  cout << "Would you like to start with 1 or 2 penguins? ($1,000.00)" << endl;
  cinValidInt(initialCount, 1, 2);
  zoo.addAnimal(PENGUIN, initialCount, Age::New);
  double penguinCost = zoo.getPenguins()[0].getCost();

  cout << "Would you like to start with 1 or 2 turtles? ($100.00)" << endl; 
  cinValidInt(initialCount, 1, 2);
  zoo.addAnimal(TURTLE, initialCount, Age::New);
  double turtleCost = zoo.getTurtles()[0].getCost();

  // subtract these initial purchases from the bankRoll.
  tycoon.withdraw(static_cast<double>(zoo.getAnimalCount(TIGER)) * tigerCost);
  tycoon.withdraw(static_cast<double>(zoo.getAnimalCount(PENGUIN)) * penguinCost);
  tycoon.withdraw(static_cast<double>(zoo.getAnimalCount(TURTLE)) * turtleCost);

  cout << "Your animals have been purchased." << endl;
  cout << "Your remaining bank balance is $" << tycoon.getBankRoll() << endl;



  // Day loop
  while (playing)
  {
    cout << "\nDay: " << dayCount << endl;

    double bonus = 0;

    // increase all animals age
    zoo.increaseAgeOnAll();

    // Pay for feed.
    calcAndWithdrawFoodCost(tycoon, zoo);
    cout << "After feeding all animals, your bank blance is $" << tycoon.getBankRoll() << endl;

    // random event
    bonus = randomEvent(zoo);

    // calc profit
    calcAndDepositProfit(tycoon, zoo, bonus);
    cout << "After depositing profit, your bank blance is $" << tycoon.getBankRoll() << endl;

    cout << endl;

    // prompt user to by adult animal
    cout << "Would you like to buy an adult animal?" << endl;
    vector<string> newAdultOptoins{"Tiger ($10,000.00)", "Penguin ($1,000.00)", "Turtle ($100.00)", "No Thanks."};
    string newAnimal;
    int newAdultSelection = menu(newAdultOptoins);
    switch (newAdultSelection)
    {
      case 1:
        zoo.addAnimal(TIGER, 1, Age::Adult);
        haveMoney = tycoon.withdraw(zoo.getTigers()[0].getCost());
        newAnimal = "tiger";
        break;
      case 2:
        zoo.addAnimal(PENGUIN, 1, Age::Adult);
        haveMoney = tycoon.withdraw(zoo.getPenguins()[0].getCost());
        newAnimal = "penguin";
        break;
      case 3:
        zoo.addAnimal(TURTLE, 1, Age::Adult);
        haveMoney = tycoon.withdraw(zoo.getTurtles()[0].getCost());
        newAnimal = "turtle";
        break;
    }
    if (newAdultSelection != 4 && haveMoney)
    {
      cout << "\nAn adult " << newAnimal << " has been added to your zoo." << endl;
      cout << "Your remaining bank balance is $" << tycoon.getBankRoll() << endl;
    } 

    cout << endl;

    cout << "Animal count: " << endl;
    cout << "Tigers: " << zoo.getAnimalCount(TIGER) << endl;
    cout << "Penguins: " << zoo.getAnimalCount(PENGUIN) << endl;
    cout << "Turtles: " << zoo.getAnimalCount(TURTLE) << endl;

    cout << endl;

    // if you run out of money.
    if (!haveMoney)
    {
      cout << "You ran out of money!" << endl;
      playing = haveMoney;
    }
    else {
      // prompt user to continue or end the game
      vector<string> continueOptions{"Keep playing", "End game"};
      if (menu(continueOptions) == 2)
      {
        playing = false;
      }
    }

    

    dayCount += 1;
  }

  cout << "Game over." << endl;
  cout << "Goodbye." << endl;

  return 0;
}


/**
 * Description: 
 * */
void calcAndWithdrawFoodCost(Player &tycoon, Zoo &zoo)
{
  double totalFoodCost = 0;
  // add cost of food for all tigers
  totalFoodCost += 
  static_cast<double>(zoo.getAnimalCount(TIGER))
  * zoo.getTigers()[0].getFoodCost();
  // add cost of food for all penguins
  totalFoodCost += 
  static_cast<double>(zoo.getAnimalCount(PENGUIN))
  * zoo.getPenguins()[0].getFoodCost();
  // add cost of food for all turtles
  totalFoodCost += 
  static_cast<double>(zoo.getAnimalCount(TURTLE))
  * zoo.getTurtles()[0].getFoodCost();

  tycoon.withdraw(totalFoodCost);
}


/**
 * Description:
 * */
void calcAndDepositProfit(Player &tycoon, Zoo &zoo, int bonus)
{
  double totalProfit = 0;

  // add profit from all tigers
  totalProfit += 
  static_cast<double>(zoo.getAnimalCount(TIGER))
  * zoo.getTigers()[0].getPayoff();
  // add profit from all penguins
  totalProfit += 
  static_cast<double>(zoo.getAnimalCount(PENGUIN))
  * zoo.getPenguins()[0].getPayoff();
  // add profit from all turtles
  totalProfit += 
  static_cast<double>(zoo.getAnimalCount(TURTLE))
  * zoo.getTurtles()[0].getPayoff();

  totalProfit += bonus;

  cout << "Your profit for the day, including bonus, is $" << totalProfit << endl;
  tycoon.deposit(totalProfit);
}


