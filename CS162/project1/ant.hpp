/**
 * Author: Patirck Moore
 * Date: October 6, 2017
 * Description: Ant class interface 
 * */

#ifndef ANT_HPP
#define ANT_HPP

class Ant
{
  private:
    char** board;
    int rows;
    int cols;
    int steps;
    int antY;
    int antX;
    char antDir;
    char whiteSpace = ' ';
    char blackSpace = '#';
    char antSpace = '*';
    char currentSpace = ' '; // initial current space will always be white.
    void createBoard();
    void printBoard();
    void move();
    void updateSpace();
    void updateDir(int, int);
  public:
    Ant(int rows, int cols, int steps, int sRow, int sCol, int sDir);
    void run();
};

#endif