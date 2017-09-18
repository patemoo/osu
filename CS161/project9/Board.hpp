/**
 * Author: Patrick Moore
 * Date:
 * Description: Board class interface decloration.
 *              This class has one private variable,
 *              a two dimensional char array, boardArray.
 *              It has a privat method checkWinCases.
 *              It also includes public methods makeMove,
 *              gameState, and print.
 **/

#ifndef BOARD_HPP
#define BOARD_HPP

// Game state values.
enum State {X_WON, O_WON, DRAW, UNFINISHED};

class Board 
{
  private:
    char boardArray[3][3];
    char checkWinCases();
  public:
    Board();
    bool makeMove(int, int, char);
    State gameState();
    void print();
};

#endif