/**
 * Author: Patrick Moore
 * Date: November 25, 2017
 * Description: Prompt user with a menu 
 *              to simulate buffer or create palindrome.
 * */

#include "palindrome.hpp"
#include "buffer.hpp"
#include "menu.hpp"
#include "validate.hpp"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;


int main()
{
  srand(time(0));
  bool continueLoop = true;
  vector<string> menuOptions{
    "Simulate buffer", 
    "Create palindrome", 
    "Exit"
  };
  enum Option{simulateBuffer = 1, createPalindrome, exitProgram};

  //buffer vars:
  int rounds;
  int endInChance;
  int frontOutChance;

  //palindrome vars:
  string initString;

  while (continueLoop)
  {
    cout << endl;
    int selection = menu(menuOptions);

    switch (selection)
    {
      case Option::simulateBuffer:
        cout << "\nHow many rounds will be simulated?" << endl;
        cinValidInt(rounds);
        cout << "\nEnter a percentage for the chance to put a randomly generated number at the end of the buffer." << endl;
        cinValidInt(endInChance);
        cout << "\nEnter a percentage for the chance to take out a randomly generated number at the front of the buffer." << endl;
        cinValidInt(frontOutChance);

        bufferSimulation(rounds, endInChance, frontOutChance);
        break;
      case Option::createPalindrome:
        cout << "\nEnter a string to turn into a palindrome:" << endl;
        cin >> initString;
        palindrome(initString);
        break;
      case Option::exitProgram:
        continueLoop = false;
        break;
    }
  }

  cout << "Good bye." << endl;

  return 0;
}

