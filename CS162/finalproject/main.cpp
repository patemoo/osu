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

#include <cstdlib>
using std::rand;

int selectStartState();

bool takeAction(Player &, int &);

int main()
{
  srand(time(0));
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

  cout << "\nCampaign Trail pits you against a computer opponent \nas you travel from state to state collecting votes." << endl; 
  cout << "In each state you will earn votes for each action you take." << endl;
  cout << "But be warned, some states lean more to one political party\nthan the other.";
  cout << " The campaign will last for 30 days." << endl;
  cout << "The winner will be the fist candidate to reach 270 votes \nor whoever has the most votes on election day. Have fun!\n" << endl;

  //game loop
  while(inGame)
  {
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
    vector<string> partyOptions{"Democrat", "Republican"};
    cout << "\nTo begin your campaign you must select a political party?\n" << endl;
    int partySelection = menu(partyOptions);

    // create player
    Player p1(static_cast<Party>(partySelection), "You");
    cout << "\nYou have chosen to run as a " << p1.getParty() << "." << endl;

    // randomly select a party for AI opponent
    // create AI opponent
    Player ai(static_cast<Party>(rand() % 2 + 1), "Your opponent");
    cout << "\nYour opponent has chosen to run as a " << ai.getParty() << endl;

    // choose a state to start in
    p1.setLocation(states[selectStartState()]);

    // randomly select a state for the AI opponent to start in.
    ai.setLocation(states[(rand() % 9)]);

    int dayCount = 30;
    int p1SpeechCount = 1;
    int aiSpeechCount = 1;
    bool p1VoteLimit = false;
    bool aiVoteLimit = false;

    // action loop
    while (dayCount > 0)
    {
      p1VoteLimit = takeAction(p1, p1SpeechCount);
      aiVoteLimit = takeAction(ai, aiSpeechCount);
      dayCount -= 1;

      if (p1VoteLimit || aiVoteLimit)
      {
        dayCount = 0;
      }
      else
      {
        cout << "\nElection Day is " << dayCount << " days away." << endl;
        cout << "You have " << p1.getVotes() << " votes." << endl;
        cout << "Your opponent has " << ai.getVotes() << " votes." << endl;
      }
    }
    cout << p1VoteLimit << endl;
    if (p1VoteLimit || aiVoteLimit)
    {
      if (p1VoteLimit)
      {
        cout << "\nYou have reached the 270 vote limit." << endl;
      }
      if (aiVoteLimit)
      {
        cout << "\nYour opponent has reached the 270 vote limit." << endl;
      }
    }
    else
    {
      cout << "\nElection Day has arrived!!" << endl;
      cout << "\nTime to tally the votes...\n" << endl;
    }
    

    if (p1.getVotes() > ai.getVotes())
    {
      cout << "\n==================\n";
      cout << "=**= You Won! =**=\n";
      cout << "==================\n\n" << endl;
    }
    else if (p1.getVotes() < ai.getVotes())
    {
      cout << "\n===================\n";
      cout << "=**= You Lost! =**=\n";
      cout << "===================\n\n" << endl;
    }
    else
    {
      cout << "\nThe votes are tied" << endl;
    }

    // prompt user to play again or exit game
    vector<string> againOptions{"Play again", "No thanks"};
    int againSelection = menu(againOptions);

    if (againSelection == 2)
    {
      inGame = false;
    }
    else
    {
      p1.removeVotes(p1.getVotes());
      ai.removeVotes(ai.getVotes());
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


/**
 * 
 * */
bool takeAction(Player &player, int &speechCount)
{
  vector<string> actionOptions{
    "Give a speech", 
    "Knock on doors", 
    "Kiss a baby", 
    "Leave state"
  };

  int actionSelection;
  if (player.getName() == "You")
  {
    cout << "\nWhat would you like to do?\n" << endl;
    actionSelection = menu(actionOptions);
  }
  else
  {
    actionSelection = rand() % 4 + 1;
  }
  
  int actionVotes = 0;
  bool voteLimit = false;
  switch (actionSelection)
  {
    case 1: // give speech
      actionVotes = player.getLocation()->calcVotes(player, Action::speech, speechCount);
      cout << "\nWhile in " << player.getLocation()->getName() << ", " << player.getName() << " gave a speech." << endl;
      cout << player.getName() << " earned " << actionVotes << " votes." << endl;
      voteLimit = player.addVotes(actionVotes);
      break;

    case 2: // knock on doors
      actionVotes = player.getLocation()->calcVotes(player, Action::doors, speechCount);
      cout << "\nWhile in " << player.getLocation()->getName() << ", " << player.getName() << " went door to door meeting potential voters." << endl;
      cout << player.getName() << " earned " << actionVotes << " votes." << endl;
      voteLimit = player.addVotes(actionVotes);
      break;

    case 3: // kiss baby
      actionVotes = player.getLocation()->calcVotes(player, Action::baby, speechCount);
      cout << "\nWhile in " << player.getLocation()->getName() << ", " << player.getName() << " kissed a baby while at a local event." << endl;
      cout << player.getName() << " earned " << actionVotes << " votes." << endl;
      voteLimit = player.addVotes(actionVotes);
      break;

    case 4:
      player.getLocation()->moveOn(player);
      speechCount = 1;
      break;
  }
  return voteLimit;  
}

