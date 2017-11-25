/**
 * Author: Patrick Moore
 * Date: November 19, 2017
 * Description: 
 * */

#include "menu.hpp"
#include "validate.hpp"
#include "character.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"

#include "lineup.hpp"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;


#include <cstdlib>
using std::rand;

void printAttackStats(Character *, Character *);
Character * getCharacter(int);

void fillLineup(Lineup *, int);

void runCombat(Lineup *, Lineup *, vector<string> *);

int main()
{
  srand(time(0));
  bool inGame = true;
  bool inTourny = true;
  enum CharType{vampire = 1, barbarian, bluemen, medusa, harrypotter};
  vector<string> playOptions{"Play", "Exit"};
  vector<string> playAgainOptions{"Play again", "Exit"};

  cout << "\nWelcome to Fantasy Combat tournament.\n" << endl;

  // prompt user to play the tournament.
  int play = menu(playOptions);
  if (play == 2)
  {
    inTourny = false;
  }

  // tournament loop
  while (inTourny)
  {
    int teamSize;
    cout << "\nHow many fighters would you like on both teams?" << endl;
    cinValidInt(teamSize, 1, 10);

    cout << "\nAdd fighters to the red team.\n" << endl;
    Lineup redTeam;
    fillLineup(&redTeam, teamSize);

    cout << "\nAdd fighters to the blue team.\n" << endl;
    Lineup blueTeam;
    fillLineup(&blueTeam, teamSize);

    vector<string> defeatedList{};
    runCombat(&redTeam, &blueTeam, &defeatedList);


    
    //prompt user to play or exit the game.
    cout << endl;
    int playAgain;
    playAgain = menu(playAgainOptions);
    if (playAgain == 2)
    {
      inTourny = false;
    }
  }

  cout << "Game over." << endl;

  return 0;
}


/**
 * Description: return a new character based on the user's choice.
 * */
Character * getCharacter(int choice)
{
  
  Character *player;
  switch (choice)
  {
    case CharType::vampire:
    {
      player = new Vampire;
    }
    break;
    case CharType::barbarian:
    {
      player = new Barbarian;
    }
    break;
    case CharType::bluemen:
    {
      player = new BlueMen;
    }
    break;
    case CharType::medusa:
    {
      player = new Medusa;
    }
    break;
    case CharType::harrypotter:
    {
      player = new HarryPotter;
    }
    break;
  }
  return player;
}


/**
 * Description: Print stats.
 * */
void printAttackStats(Character *attacker, Character *defender)
{
  cout << "\nAttacker: " << attacker->getTypeName();
  cout << "\nDefender: " << defender->getTypeName() << " ";
  cout << "armor: " << defender->getArmor() << " ";
  cout << "strength: " << defender->getStrengthPoints() << endl;
  cout << endl;
}


/**
 * Description: create team. prompt user for line up selection.
 * */
void fillLineup(Lineup *team, int size)
{
  vector<string> characterOptions{"Vampire", "Barbarian", "Blue Men", "Medusa", "Harry Potter"};

  for (int i=0; i<size; i++)
  {
    int type;
    string name;

    cout << "Choose player type:" << endl;
    type = menu(characterOptions);

    cout << "Enter player name:" << endl;
    cin >> name;

    team->addBack(getCharacter(type), name);
  }
}


/**
 * Description: 
 * */
void runCombat(Lineup *redTeam, Lineup *blueTeam, vector<string> *defeatedList)
{
  int redPoints = 0;
  int bluePoints = 0;
  int roundCount = 1;

  // round loop
  while (!redTeam->isEmpty() && !blueTeam->isEmpty())
  {
    bool inCombat = true;
    bool redDefeated = false;
    bool blueDefeated = false;
    
    // Randomize who attacks first.
    srand(time(0));
    int combatToggle = rand() % 2;

    // combat loop
    while (inCombat)
    {

      Character *playerRed = redTeam->getFighterType();
      Character *playerBlue = blueTeam->getFighterType();

      if (combatToggle)
      {
        // printAttackStats(playerRed, playerBlue);
        inCombat = playerBlue->defense(playerRed->attack());
        blueDefeated = !inCombat;
        if (inCombat)
        {
          // printAttackStats(playerBlue, playerRed);
          inCombat = playerRed->defense(playerBlue->attack());
          redDefeated = !inCombat;
        }
      }
      else
      {
        // printAttackStats(playerBlue, playerRed);
        inCombat = playerRed->defense(playerBlue->attack());
        redDefeated = !inCombat;
        if (inCombat)
        {
          // printAttackStats(playerRed, playerBlue);
          inCombat = playerBlue->defense(playerRed->attack());
          blueDefeated = !inCombat;
        }
      }
      
      combatToggle = !combatToggle;
    }

    cout << endl;
    cout << "round " << roundCount << ":" << endl;
    cout << " RedTeam: " << redTeam->getFighterName() << " vs. ";
    cout << " BlueTeam: " << blueTeam->getFighterName() << endl;

    if (redDefeated)
    {
      cout << blueTeam->getFighterName() << " won!" << endl;
      redTeam->removeDefeated(defeatedList);
      blueTeam->moveToBack();
      bluePoints += 1;
    }

    if (blueDefeated)
    {
      cout << redTeam->getFighterName() << " won!" << endl;
      blueTeam->removeDefeated(defeatedList);
      redTeam->moveToBack();
      redPoints += 1;
    }

    roundCount += 1;
  }

  cout << endl;
  cout << "Red points: " << redPoints << endl;
  cout << "Blue points: " << bluePoints << endl;
  cout << endl;
  
  if (redPoints > bluePoints)
  {
    cout << "Red Team Wins!" << endl;
  }
  else if (bluePoints > redPoints)
  {
    cout << "Blue Team Wins!" << endl;
  }

  vector<string> printOptions{"print loosers", "don't print"};
  int printChoice = menu(printOptions);
  if (printChoice == 1)
  {

    for (string item : *defeatedList)
    {
      cout << item << " ";
    }
    cout << endl;
  }
}
