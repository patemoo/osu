/**
 * Author: Patrick Moore
 * Date:
 * Description: This file includes the implementation of the Board class methods.
 **/

#include "Board.hpp"
#include <iostream>

using std::cout;
using std::endl;

/**
 * Description: Constructor that instantiates each board value to a period. 
 **/
Board::Board()
{
  for (int i=0;i<3;i++)
  {
    for (int j=0;j<3;j++)
    {
      boardArray[i][j] = '.';
    }
  }
}

/**
 * Description: makeMove takes in an x and y coordinate
 *              as well as the active player, checks if
 *              a move has been made at the specificed coordinates.
 *              If so false is returned if not the move is made
 *              and true is returned.
 **/
bool Board::makeMove(int xCoord, int yCoord, char activePlayer)
{
  if (boardArray[xCoord][yCoord] != '.')
  {
    return false;
  }

  boardArray[xCoord][yCoord] = activePlayer;
  return true;
}

/**
 * Description: gameState first stores the result of checkWinCases in to a variable.
 *              It then compares that result to each of the player's chars. If there is no winner
 *              it loops through all the values on the board to see if any of the initial
 *              periods are still present. If not the game is a draw. For each of these
 *              logic blocks the proper enum value is returned when true.
 **/
State Board::gameState()
{
  char result = checkWinCases();
  if (result == 'x')
  {
    return X_WON;
  }
  if (result == 'o')
  {
    return O_WON;
  }
  for (int i=0;i<3;i++)
  {
    for (int j=0;j<3;j++)
    {
      if (boardArray[i][j] == '.')
      {
        return UNFINISHED;
      }
    }
  }
  return DRAW;
}


/**
 * Description: checkWinCases checks for a matching char across all values
 *              in each of the possible winning scequences. If a match is found
 *              and it is not of the initial period then the matching char is returned
 *              otherwise an 'n' is returned to siginify no winner.
 **/
char Board::checkWinCases()
{
  if (boardArray[0][0] != '.' && boardArray[0][0] == boardArray[0][1] && boardArray[0][1] == boardArray[0][2])
    return boardArray[0][0];
  
  if (boardArray[1][0] != '.' && boardArray[1][0] == boardArray[1][1] && boardArray[1][1] == boardArray[1][2])
    return boardArray[1][0];

  if (boardArray[2][0] != '.' && boardArray[2][0] == boardArray[2][1] && boardArray[2][1] == boardArray[2][2])
    return boardArray[2][0];

  if (boardArray[0][0] != '.' && boardArray[0][0] == boardArray[1][0] && boardArray[1][0] == boardArray[2][0])
    return boardArray[0][0];

  if (boardArray[0][1] != '.' && boardArray[0][1] == boardArray[1][1] && boardArray[1][1] == boardArray[2][1])
    return boardArray[0][1];

  if (boardArray[0][2] != '.' && boardArray[0][2] == boardArray[1][2] && boardArray[1][2] == boardArray[2][2])
    return boardArray[0][2];

  if (boardArray[0][0] != '.' && boardArray[0][0] == boardArray[1][1] && boardArray[1][1] == boardArray[2][2])
    return boardArray[0][0];

  if (boardArray[0][2] != '.' && boardArray[0][2] == boardArray[1][1] && boardArray[1][1] == boardArray[2][0])
    return boardArray[0][2];
  
  return 'n';
}


/**
 * Description: This functions prints out the current board in a matrix pattern.
 **/
void Board::print()
{
  cout << "\n  0 1 2";
  for (int i=0;i<3;i++)
  {
    cout << "\n" << i; 
    for (int j=0;j<3;j++)
    {
      cout << " " << boardArray[i][j];
    }
  }
  cout << "\n" << endl;
}