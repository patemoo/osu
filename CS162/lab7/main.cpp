/**
 * Author: Patrick Moore
 * Date: November 9, 2017
 * Description: main file for a circular linked list
 * */

#include "menu.hpp"
#include "validate.hpp"
#include "queue.hpp"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
  bool done = false;
  vector<string> menuOptions{
    "Add a value to the back of queue", 
    "Display the front value",
    "Remove the front node",
    "Display the queue's content",
    "Exit"
  };

  cout << "\nWelcome to my queue!\n" << endl;

  Queue list;

  while (!done)
  {
    int selection;
    int value;

    selection = menu(menuOptions);

    switch (selection)
    {
      case 1:
      {
        int value;
        cout << "\nPlease enter a positive integer.\n" << endl;
        cinValidInt(value);
        list.addBack(value);
        cout << endl;
      }
      break;
      case 2:
      {
        int frontNode = list.getFront();
        if (frontNode)
        {
          cout << "\nThe first node value is: " << frontNode;
        }
        else
        {
          cout << "\nYour queue is empty";
        }
        cout << "\n" << endl;
      }
      break;
      case 3:
        list.removeFront();
        break;
      case 4:
        list.printQueue();
        break;
      case 5:
        done = true;
        break;
    }
  }
  
  cout << "\nGood bye." << endl;

  return 0;
}