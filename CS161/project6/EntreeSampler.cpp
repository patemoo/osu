/****
 * Author: Patrick Moore
 * Date: July 24, 2017
 * Description: EntreeSampler class implementation.
 *****/

#include "EntreeSampler.hpp"
#include <iostream>

using std::cout;
using std::endl;

/****
 *
 * Description: This constructor takes in four entrees 
 *              and sets the respective member variables.
 *
 *****/
EntreeSampler::EntreeSampler(Entree ent1, Entree ent2, Entree ent3, Entree ent4)
{
  entree1 = ent1;
  entree2 = ent2;
  entree3 = ent3;
  entree4 = ent4;
}


/****
 *
 * Description: This method prints a comma separated string of entree names.
 *
 *****/
void EntreeSampler::listEntrees()
{
  string list = entree1.getName() + ", ";
  list       += entree2.getName() + ", ";
  list       += entree3.getName() + ", ";
  list       += entree4.getName() + ".";

  cout << list << endl;
}


 /****
 *
 * Description: This method adds up the calories for each entree and returns the total.
 *
 *****/
int EntreeSampler::totalCalories()
{
  int total = entree1.getCalories()
            + entree2.getCalories()
            + entree3.getCalories()
            + entree4.getCalories();

  return total;
}