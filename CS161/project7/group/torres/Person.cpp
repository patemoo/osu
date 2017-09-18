/*****************************************************************************
 * Author: Ruben M Torres
 * Date: July 30, 2017
 * Description: This is the implementation file for the class Person. 
 * Must include Person.hpp. It contains a constructor for Person whe passed
 * a string and double that are intitalized to name and age respectively. It
 * also contains functions to get both name and age by returning them.
 * ***************************************************************************/
#include "Person.hpp"
#include <string>
using namespace std;

/**Person(string, double)****************************************************
 * Description: This is the constructor to initialize age and name to the 
 * string and double that are passed to it.
 * *************************************************************************/
Person::Person(string nameEntered, double ageEntered)
{
	name = nameEntered;
	age = ageEntered;
}

/**getName()****************************************************************
 * Description: This function returns the string name. 
 * *************************************************************************/
string Person::getName()
{
	return name;
}

/**getAge()******************************************************************
 * Description: This function returns the double age.
 * *************************************************************************/
double Person::getAge()
{
	return age;
}
