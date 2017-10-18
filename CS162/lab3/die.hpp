/**
 * Author: Patrick Moore
 * Date: October 15, 2017
 * Description: Die class interface
 * */

#ifndef DIE_HPP
#define DIE_HPP

class Die
{
  private:
    int sides;
  public:
    Die(int);
    int roll();
    int getSides();
};

#endif