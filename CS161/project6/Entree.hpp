/****
 * Author: Patrick Moore
 * Date: July 24, 2017
 * Description: Entree class interface decloration.
 *****/

#ifndef ENTREE_HPP
#define ENTREE_HPP

#include <string>
using std::string;

class Entree
{
  private:
    string entreeName;
    int entreeCalories;
  public:
    Entree();
    Entree(string, int);
    void setName(string);
    void setCalories(int);
    string getName();
    int getCalories();
};

#endif