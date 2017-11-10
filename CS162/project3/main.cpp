/**
 * Author: Patrick Moore
 * Date: November 4, 2017
 * Description: 
 * */

#include "menu.hpp"
#include "character.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"

#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>
using std::rand;

void printRoundStats(Character *, Character *);

int main()
{
  srand(time(0));
  bool inGame = true;
  enum CharType{vampire = 1, barbarian, bluemen, medusa, harrypotter};
  Character *playerOne;
  Character *playerTwo; 

  cout << "\nWelcome to Fantasy Combat game.\n" << endl;
  vector<string> characterOptions{"Vampire", "Barbarian", "Blue Men", "Medusa", "Harry Potter"};
  vector<string> gameOptions{"Play again", "Exit game"};

  // game loop
  while (inGame)
  {
    // prompt user and create player one's character.
    cout << "\nChoose a character for Player One." << endl;
    int p1Choice = menu(characterOptions);
    switch (p1Choice)
    {
      case CharType::vampire:
      {
        Vampire vamp;
        playerOne = &vamp;
      }
      break;
      case CharType::barbarian:
      {
        Barbarian barb;
        playerOne = &barb;
      }
      break;
      case CharType::bluemen:
      {
        BlueMen blue;
        playerOne = &blue;
      }
      break;
      case CharType::medusa:
      {
        Medusa med;
        playerOne = &med;
      }
      break;
      case CharType::harrypotter:
      {
        HarryPotter potter;
        playerOne = &potter;
      }
      break;
    }
    
    // prompt user and create player two's character.
    cout << "\nChoose a character for Player Two." << endl;
    int p2Choice = menu(characterOptions);
    switch (p2Choice)
    {
      case CharType::vampire:
      {
        Vampire vamp;
        playerTwo = &vamp;
      }
      break;
      case CharType::barbarian:
      {
        Barbarian barb;
        playerTwo = &barb;
      }
      break;
      case CharType::bluemen:
      {
        BlueMen blue;
        playerTwo = &blue;
      }
      break;
      case CharType::medusa:
      {
        Medusa med;
        playerTwo = &med;
      }
      break;
      case CharType::harrypotter:
      {
        HarryPotter potter;
        playerTwo = &potter;
      }
      break;
    }

    // I would have liked to combine the logic from the two above switch statements 
    // and abstract it out to a helper function but was running into some memory allocation issues.
    
    bool inCombat = true;
    // Randomize who attacks first.
    srand(time(0));
    int combatToggle = rand() % 2;
    
    // remove this code
    int count = 0;

    // combat loop
    while (inCombat)
    {
      if (combatToggle)
      {
        printRoundStats(playerOne, playerTwo);
        // playerTwo->defense(playerOne->attack());
        // playerOne->defense(playerTwo->attack());
      }
      else
      {
        printRoundStats(playerTwo, playerOne);
        // playerOne->defense(playerTwo->attack());
        // playerTwo->defense(playerOne->attack());
      }

      combatToggle = !combatToggle;
      if (count == 1)
      {
        inCombat = false;
      }
      count += 1;
    }

    // prompt user to play again or exit the game.
    int keepPlaying;
    cout << endl;
    keepPlaying = menu(gameOptions);
    if (keepPlaying == 2)
    {
      inGame = false;
    }

  }

  cout << "Game over." << endl;

  return 0;
}


/**
 * Description:
 * */
void printRoundStats(Character *attacker, Character *defender)
{
  cout << "\nAttacker type: " << attacker->getTypeName() << endl;
  cout << "\nDefender type: " << defender->getTypeName() << endl;
  cout << "Defender armor: " << defender->getArmor() << endl;
  cout << "Defender strength: " << defender->getStrengthPoints() << endl;
  cout << endl;
}