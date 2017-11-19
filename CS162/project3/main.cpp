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

void printAttackStats(Character *, Character *);
Character * getCharacter(int);

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
    playerOne = getCharacter(p1Choice);
    
    // prompt user and create player two's character.
    cout << "\nChoose a character for Player Two." << endl;
    int p2Choice = menu(characterOptions);
    playerTwo = getCharacter(p2Choice);
 

    bool inCombat = true;
    // Randomize who attacks first.
    srand(time(0));
    int combatToggle = rand() % 2;
    
    // remove this code
    // int count = 0;

    // combat loop
    while (inCombat)
    {
      if (combatToggle)
      {
        printAttackStats(playerOne, playerTwo);
        inCombat = playerTwo->defense(playerOne->attack());
        if (inCombat)
        {
          printAttackStats(playerTwo, playerOne);
          inCombat = playerOne->defense(playerTwo->attack());
        }
      }
      else
      {
        printAttackStats(playerTwo, playerOne);
        inCombat = playerOne->defense(playerTwo->attack());
        if (inCombat)
        {
          printAttackStats(playerOne, playerTwo);
          inCombat = playerTwo->defense(playerOne->attack());
        }
      }
      
      combatToggle = !combatToggle;
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
 * Description: return a new character based on the user's choice.
 * */
Character * getCharacter(int choice)
{
  enum CharType{vampire = 1, barbarian, bluemen, medusa, harrypotter};
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