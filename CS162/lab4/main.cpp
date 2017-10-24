/**
 * Author: Patrick Moore
 * Date: October 22, 2017
 * Description: main program file.
 * */

#include "menu.hpp"
#include "university.hpp"

#include <iostream>
using std::cout;
using std::endl;


void personMenu(University &);

int main()
{
  bool active = true;

  University osu;

  Student s("Patrick Moore");
  Instructor i("Shelsea Moore");
  osu.addPerson(&s);
  osu.addPerson(&i);

  Building b1("Adams Hall", 11168, "606 SW 15TH ST \nCORVALLIS, OR 97331");
  Building b2("Austin Hall", 107613, "2751 SW JEFFERSON WAY \nCORVALLIS, OR 97331");
  osu.addBuilding(&b1);
  osu.addBuilding(&b2);

  int systemSelection;
  vector<string> systemOptions{"Print buildings", "Print people", "Have someone do work", "Exit"};
  
  while (active)
  {
    systemSelection = menu(systemOptions);

    switch (systemSelection)
    {
      case 1:
        osu.printBuildings();
      break;
      case 2:
        osu.printPeople();
      break;
      case 3:
      {
        personMenu(osu);
      }
      break;
      case 4:
        active = false;
      break;
    }
  }

  cout << "Exiting program, good bye." << endl;

  return 0;
}

/**
 * Description: create and prompt usrer with a menu of each person at the university.
 * */
void personMenu(University &osu)
{
  int personSelection;
  vector<string> personOptions{};
  
  vector<Person*> people = osu.getPeople();
  int length = people.size();
  for (int i=0; i<length; i++)
  {
    personOptions.push_back(people[i]->getName());
  }

  personSelection = menu(personOptions);

  people[personSelection - 1]->doWork();
}