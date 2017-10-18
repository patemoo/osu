/**
 * Author: Patrick Moore
 * Date: October 15, 2017
 * Description: Game class interface
 * */

#ifndef GAME_HPP
#define GAME_HPP

#include <string>
using std::string;

class Game
{
  private:
    int rounds;
    int p1DieType;
    int p1DieSides;
    int p1Score = 0;
    int p2DieType;
    int p2DieSides;
    int p2Score = 0;
    int getRoll(int, int);
    string getType(int);
  public:
    Game(int, int, int, int, int);
    void play();
};


#endif