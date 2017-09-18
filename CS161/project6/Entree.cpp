/****
 * Author: Patrick Moore
 * Date: July 24, 2017
 * Description: Entree class implementation.
 *****/

 #include "Entree.hpp"

/****
 *
 * Description: This default constructor intializes the
 *              member variables to and empty string and zero.
 *
 *****/
Entree::Entree()
{
  setName("");
  setCalories(0);
}


 /****
 *
 * Description: This constructor takes in arguments for
 *              name and calories and sets the member variables.
 *
 *****/
Entree::Entree(string name, int calories)
{
  setName(name);
  setCalories(calories);
}

 /****
 *
 * Description: This method takes a string argument and sets it to entreeName.
 *
 *****/
void Entree::setName(string name)
{
  entreeName = name;
}


 /****
 *
 * Description: This method takes a int argument and sets it to entreeCalories.
 *
 *****/
void Entree::setCalories(int calories)
{
  entreeCalories = calories;
}

 /****
 *
 * Description: This method returns the value of entreeName
 *
 *****/
string Entree::getName()
{
  return entreeName;
}


 /****
 *
 * Description: This method returns the value of entreeCalories.
 *
 *****/
int Entree::getCalories()
{
  return entreeCalories;
}