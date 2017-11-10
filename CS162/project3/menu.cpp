/**
 * Author: Patirck Moore
 * Date: October 6, 2017
 * Description: menu function implementation.
 * */

#include "menu.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int menu(vector <string> options)
{
  int selection;
  int optionNum = 1;
  bool valid = false;

  cout << "Please select from the following options:" << endl;

  // output menu options
  for (string option : options)
  {
    cout << optionNum << ". " << option << endl;
    optionNum += 1;
  } 

  // read in and validate selection input
  while (!valid)
  {
    cin >> selection;

    if (cin.fail())
    {
      cin.clear();
      cin.ignore();
      cout << "Please enter an integer." << endl;
    }
    else if (selection <= 0 || selection > options.size())
    {
      cout << "Please enter the number preceding one of the above options." << endl;
    }
    else 
    {
      valid = true;
    }
  }

  return selection;
}