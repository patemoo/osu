/**
 * Author: Patrick Moore
 * Date: Noverber 2, 2017
 * Description: 
 * */


#include "linkedList.hpp"
#include "menu.hpp"
#include "validate.hpp"


#include <iostream>
using std::cout;
using std::endl;


int main()
{
  bool active = true;

  LinkedList list;

  while (active)
  {
    int selected;

    vector<string> menuOptions{
      "Add a new node to the head",
      "Add a new node to the tail",
      "Delete from head",
      "Delete from tail",
      "Traverse the list reversely",
      "Print the value of the head node",
      "Print the value of the tail node",
      "Exit"
    };

    selected = menu(menuOptions);
    cout << endl;

    switch (selected)
    {
      case 1:
      {
        int value;
        cout << "please enter a positive integer." << endl;
        cinValidInt(value);
        list.addNodeAtHead(value);
      }
      break;
      case 2:
      {
        int value;
        cout << "please enter a positive integer." << endl;
        cinValidInt(value);
        list.addNodeAtTail(value);
      }
      break;
      case 3:
        list.deleteFirst();
      break;
      case 4:
        list.deleteLast();
      break;
      case 5:
        list.printInReverse();
      break;
      case 6:
        list.printHead();
      break;
      case 7:
        list.printTail();
      break;
      case 8:
        active = false;
      break;
    }
    
    cout << endl;
    list.printList();
    cout << endl;
  }

  cout << "Goodbye." << endl;

  return 0;
}