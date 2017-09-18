/****
 * Author: Patrick Moore
 * Date: July 24, 2017
 * Description: EntreeSampler class interface decloration.
 *****/

#ifndef ENTREE_SAMPLER_HPP
#define ENTREE_SAMPLER_HPP

#include "Entree.hpp"

class EntreeSampler
{
  private:
    Entree entree1;
    Entree entree2;
    Entree entree3;
    Entree entree4;
  public:
    EntreeSampler(Entree, Entree, Entree, Entree);
    void listEntrees();
    int totalCalories();
};

#endif