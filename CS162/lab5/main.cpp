/**
 * Author: Patrick Moore
 * Date: October 28, 2017
 * Description: This file runs the menu for a user to interact
 *              with the recursive functions.
 * */

#include "recursive.hpp"
#include "menu.hpp"
#include "validate.hpp"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;


int main()
{
  bool stay = true;

  while (stay)
  {
    int selection;

    // prompt user for which function they would like to run.
    vector<string> functionOptions{"Function One", "Function Two", "Function Three", "Exit"};
    selection = menu(functionOptions);

    switch (selection)
    {
      case 1:
      {
        const int SIZE = 51;
        char textString[SIZE];

        cout << "Please enter a text string less than " << (SIZE - 1) << " characters." << endl;
        cin.ignore();
        cin.getline(textString, SIZE);

        cout << endl;
        functionOne(textString);
        cout << endl;
      }
      break;
      case 2:
      {
        int sum;
        int arraySize;
        cout << "What is the size of your integer array?" << endl;
        cinValidInt(arraySize);

        int array[arraySize];
        for (int i=0; i<arraySize; i++)
        {
          cout << "Enter an integer:" << endl;
          cinValidInt(array[i]);
        }

        cout << endl;
        sum = functionTwo(array, arraySize);
        cout << "sum: " << sum << endl;
      }
      break;
      case 3:
        {
          int userInt;
          bool negative = true;

          while(negative)
          {
            cout << "Please enter a non-negative integer." << endl;
            cinValidInt(userInt);
            if (userInt >= 0)
            {
              negative = false;
            }
          }

          cout << endl;
          cout << functionThree(userInt);
          cout << endl;
        }
        break;
      case 4:
      {
        stay = false;
      }
      break;
    }
    cout << endl;
  }

  cout << "\nGoodbye." << endl;
  return 0;
}