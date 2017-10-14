/**
 * Author: Patirck Moore
 * Date: October 6, 2017
 * Description: main program function.
 *              Handles all the user prompts for info.
 * */

#include "ant.hpp"
#include "menu.hpp"
#include "validate.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void runSimulation();

int main()
{
  int selection;

  // Prompt the user to run sim or quit.
  // create vecotr of menu options
  vector<string> menu1{"Start Langton’s Ant simulation", "Quit"};

  // Run menu and store selection.
  selection = menu(menu1);

  // repeat simulation until user chooses to quit.
  while (selection == 1)
  {
    runSimulation();

    vector<string> menu2{"Run simulation again", "Quit"};
    selection = menu(menu2);
  }

  cout << "Goodbye." << endl;

  return 0;
}

void runSimulation()
{
  int rows;
  int cols;
  int steps;
  int startRow;
  int startCol;
  int startDir;
  
  // Prompt user for initial board and ant info.
  cout << "How many rows would you like your board to have?" << endl;
  cinValidInt(rows);

  cout << "How many columns would you like your board to have?" << endl;
  cinValidInt(cols);

  cout << "How many steps would you like the simulation to go through?" << endl;
  cinValidInt(steps);

  cout << "In which row would you like your ant to start?" << endl;
  cinValidInt(startRow);

  cout << "In which column would you like your ant to start?" << endl;
  cinValidInt(startCol);

  cout << "In which Direction would you like your ant to start?" << endl;
  vector<string> menu3{"up", "right", "down", "left"};
  startDir = menu(menu3);

  Ant simulation(rows, cols, steps, startRow, startCol, startDir);

  simulation.run();
}