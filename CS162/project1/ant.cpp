/**
 * Author: Patirck Moore
 * Date: October 6, 2017
 * Description: Ant class implementation.
 * */

#include "ant.hpp"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

/**
 * Description: Constructor function.
 * */
Ant::Ant(int r, int c, int s, int startRow, int startCol, int startDir)
{
  rows = r;
  cols = c;
  steps = s;
  antY = startRow - 1;
  antX = startCol - 1;
  antDir = startDir;
}


/**
 * Description: public function used to run the simulation from the outside.
 * */
void Ant::run()
{
  createBoard();
  printBoard();
  
  for (int i=0; i< steps; i++)
  {
    move();
    printBoard();
  }

  // deallocate memory
  delete [] board;
  board = nullptr;
}


/**
 * Description: creates board based on user input.
 * */
void Ant::createBoard()
{
  // allocate memory for board
  board = new char*[rows];
  for (int i=0; i<rows; i++)
  {
    board[i] = new char[cols];
  }

  for (int y=0; y<rows; y++)
  {
    for (int x=0; x<cols; x++)
    { 
      if (y == antY && x == antX)
      {
        board[y][x] = antSpace;
      }
      else
      {
        board[y][x] = whiteSpace;
      }
    }
  }
}


/**
 * Description: This function prints the board
 * */
void Ant::printBoard()
{
  // top border
  cout << " ";
  for (int t=0; t<cols; t++)
  {
    cout << " —";
  }
  cout << endl;

  // board
  for (int x=0; x<rows; x++)
  {
    cout << "|";
    for (int y=0; y<cols; y++)
    {
      cout << " " << board[x][y];
    }
    cout << " |" << endl;
  }

  // bottom border
  cout << " ";
  for (int b=0; b<cols; b++)
  {
    cout << " —";
  }
  cout << "\n" << endl;
}


/**
 * Description: This function updates the space the ant was previously on.
 * */
void Ant::updateSpace()
{
  if (currentSpace == whiteSpace)
  {
    board[antY][antX] = blackSpace;
  } else if (currentSpace == blackSpace)
  {
    board[antY][antX] = whiteSpace;
  }
}


/**
 * Description: this function updates the ant's direction
 * */
void Ant::updateDir(int right, int left)
{
  if (currentSpace == whiteSpace)
  {
    antDir = right; // relative right
  }
  else
  {
    antDir = left; // relative left
  }
}


/**
 * Description: This function handles all the move logic.
 * */
void Ant::move()
{
  enum Dir {up = 1, right, down, left};

  switch (antDir)
  {
    case up:
      updateSpace();

      // move ant
      if (antY == 0)
      {
        antY = rows - 1;
      }
      else 
      {
        antY -= 1; 
      }
      // save color of the new space
      currentSpace = board[antY][antX];
      // set the ant to its new space
      board[antY][antX] = antSpace;

      updateDir(2,4);
      break;

    case right:
      updateSpace();

      // move ant
      if (antX == cols - 1)
      {
        antX = 0;
      }
      else 
      {
        antX += 1; 
      }
      // save color of the new space
      currentSpace = board[antY][antX];
      // set the ant to its new space
      board[antY][antX] = antSpace;

      updateDir(3,1);
      break;

    case down:
      updateSpace();

      // move ant
      if (antY == rows - 1)
      {
        antY = 0;
      }
      else 
      {
        antY += 1; 
      }
      // save color of the new space
      currentSpace = board[antY][antX];
      // set the ant to its new space
      board[antY][antX] = antSpace;

      updateDir(4,2);
      break;

    case left:
      updateSpace();

      // move ant
      if (antX == 0)
      {
        antX = cols - 1;
      }
      else 
      {
        antX -= 1; 
      }
      // save color of the new space
      currentSpace = board[antY][antX];
      // set the ant to its new space
      board[antY][antX] = antSpace;

      updateDir(1,3);
      break;
  }
}