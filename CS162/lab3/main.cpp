/**
 * Author: Patrick Moore
 * Date: October 15, 2017
 * Description: main file for war game
 * */

#include "game.hpp"
#include "menu.hpp"
#include "validate.hpp"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

void playGame();

int main()
{
  int selection;

  // Prompt the user to play war or quit.
  // create vecotr of menu options
  vector<string> options{"Play War", "Exit game"};

  // Run menu and store selection.
  selection = menu(options);

  if (selection == 1)
  {
    playGame();
  }

  cout << "Goodbye." << endl;

  return 0;
}

void playGame()
{
  int rounds;
  int dieType1;
  int dieSides1;
  int dieType2;
  int dieSides2;
  vector<string> typeOptions{"Regular", "Loaded"};
  
  // Prompt user for how many rounds of war they would like to play.
  cout << "How many rounds of war would you like to be played?" << endl;
  cinValidInt(rounds, 1, 50);

  cout << "Choose a die type for Player One?" << endl;
  dieType1 = menu(typeOptions);

  cout << "How many sides will this die have?" << endl;
  cinValidInt(dieSides1, 2, 120);

  cout << "Choose a die type for Player Two?" << endl;
  dieType2 = menu(typeOptions);

  cout << "How many sides will this die have?" << endl;
  cinValidInt(dieSides2, 2, 120);


  Game war(rounds, dieType1, dieSides1, dieType2, dieSides2);

  war.play();
}