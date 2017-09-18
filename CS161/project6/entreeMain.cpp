// Entree main

#include "EntreeSampler.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{

  Entree ent1("di san xian", 200);
  Entree ent2("roast salmon", 250);
  Entree ent3("borscht", 100);
  Entree ent4("sour gummy worms", 300);
  EntreeSampler sampler1(ent1, ent2, ent3, ent4);
  sampler1.listEntrees();
  cout << sampler1.totalCalories() << endl; 

  return 0;
}