/**
 * Author: Patrick Moore
 * Date: October 17, 2016
 * Description: Player class interface
 * */

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
  private: 
    double bankRoll;
  public:
    Player();
    double getBankRoll();
    bool widthdraw(double);
    void deposit(double);
};

#endif