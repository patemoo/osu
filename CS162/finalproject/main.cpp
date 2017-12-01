/**
 * Author: Patrick Moore
 * Date: November 29, 2017
 * Description: Campaign Trail Game
 * */

#include "bluestate.hpp"
#include "redstate.hpp"
#include "swingstate.hpp"
#include "player.hpp"
#include "menu.hpp"

#include <iostream>
using std::cout;
using std::endl;

int selectStartState();

int main()
{
  bool inGame = true;
  vector<string> mainOptions{"Play", "Exit"};

  cout << "\nWelcome to:\n\n";
  cout << "========================\n";
  cout << "=**= Campaign Trail =**=\n";
  cout << "========================\n" << endl;
  
  int mainSelection = menu(mainOptions);
  if (mainSelection == 2)
  {
    inGame = false;
  }

  //game loop
  while(inGame)
  {
    cout << "\nGame description...\n" << endl;

    // create states:
    BlueState wa("Washington");
    BlueState ca("California");
    BlueState ny("New York");
    RedState tx("Texas");
    RedState ky("Kentucky");
    RedState id("Idaho");
    SwingState co("Colorado");
    SwingState oh("Ohio");
    SwingState fl("Florida");

    // connect states:
    wa.setSides(nullptr, nullptr, &id, &ca);
    ca.setSides(&wa, nullptr, &co, &tx);
    ny.setSides(nullptr, &oh, nullptr, &fl);
    tx.setSides(&co, &ca, &fl, nullptr);
    ky.setSides(&oh, &tx, &ny, &fl);
    id.setSides(nullptr, &wa, &oh, &co);
    co.setSides(&id, &ca, &ky, &tx);
    oh.setSides(nullptr, &id, &ny, &ky);
    fl.setSides(&ky, &tx, &ny, nullptr);

    // create a vector of state pointers
    vector<State *> states{&wa, &id, &co, &ca, &tx, &oh, &ny, &ky, &fl};

    // choose a party
    vector<string> partyOptions{"Democrate", "Republican", "Independent"};
    cout << "\nTo begin your campain you must select a political party?\n" << endl;
    int partySelection = menu(partyOptions);

    // create player one
    Player p1(static_cast<Party>(partySelection));

    // randomly select a party for AI opponent
    // create AI opponent

    // choose a state to start in
    p1.setLocation(states[selectStartState()]);

    int dayCount = 20;
    // campaign loop
    while (dayCount > 0)
    {
      vector<string> activityOptions{"Give a speech", "Knock on doors", "Kiss a baby", "Leave state"};
      cout << "\nWhat would you like to do?\n" << endl;
      int activitySelection = menu(activityOptions);
      switch (activitySelection)
      {
        case 1:

          break;
        case 2:

          break;
        case 3:
        
          break;
        case 4:

          p1.getLocation()->moveOn(&p1);
          dayCount -= 3;
          break;
      }


    }

    cout << "\nThe campaign trail has come to end. It is now Election Day!" << endl;
    cout << "\nTime to tally the votes...\n" << endl;



    // prompt user to play again or exit game
    vector<string> againOptions{"Play again", "No thanks"};
    int againSelection = menu(againOptions);

    if (againSelection == 2)
    {
      inGame = false;
    }
  }

  cout << "\nGoodbye.\n" << endl;

  return 0;
}



/**
 * 
 * */
int selectStartState()
{
  vector<string> stateOptions{
      "Washington",
      "Idaho",
      "Colorado",
      "California",
      "Texas",
      "Ohio",
      "New York",
      "Kentucky",
      "Florida"
    };
    cout << "\nIn which state would you like to start your campaign?\n" << endl;
    int stateSelection = menu(stateOptions);
    return stateSelection - 1;
}
