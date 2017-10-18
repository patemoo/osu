/**
 * Author: Patrick Moore
 * Date: October 15, 2017
 * Description: LoadedDie interface
 * */

#ifndef LOADED_DIE_HPP
#define LOADED_DIE_HPP

#include "die.hpp"

class LoadedDie : public Die
{
  public:
    LoadedDie(int);
    int roll();
};

#endif