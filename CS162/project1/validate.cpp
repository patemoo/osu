/**
 * Author: Patirck Moore
 * Date: October 6, 2017
 * Description: cinValidInt function implementation.
 *              validates integer input. prompts user to retry if int is not entered.
 * */

#include "validate.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void cinValidInt(int &value)
{
  bool valid = false;
  
  while (!valid)
  {
    cin >> value;

    if (cin.fail())
    {
      cin.clear();
      cin.ignore();
      cout << "Please enter an integer." << endl;
    }
    else 
    {
      valid = true;
    }
  }
}