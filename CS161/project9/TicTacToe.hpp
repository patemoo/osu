/**
 * Author: Patrick Moore
 * Date:
 * Description: TicTacToe class interface decloration.
 *              It has two private member variables gameBoard and activePlayer
 *              as well as a private method switchActivePlayer.
 *              It has a public method of play.
 **/

#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include "Board.hpp"

class TicTacToe
{
  private:
    Board gameBoard;
    char activePlayer;
    char switchActivePlayer(char);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
  public:
    TicTacToe(char);
    void play();
};

#endif