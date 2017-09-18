/****************************************************************************************
 * Name: Jason Watson
 * Date: 7/27/2017
 * Description: This is the implementation file for the class Person.  This file has a default constructor and 
 * constructor that initializes the member variables name and age.  It also has two getter functions that
 * returns the data to the client program.
********************************************************************************************/


#include<string>
#include "Person.hpp"

/********************************************************************
 * Constructor: Takes two parameters and initializes name and age member variables of class Person
**********************************************************************/
Person::Person(std::string name1, double age1)
{
    name = name1;
    age = age1;
}
/***************************************************************************
 * Default constructor: Initializes the name variable to empty string and age variable to 0
*******************************************************************************/
Person::Person()
{
    name = "";
    age = 0;
}
/********************************************************************************
 * getName function: returns string name to client program
********************************************************************************/
std::string Person::getName()
{
    return name;
}
/**********************************************************************************
 * getAge function: returns age to client program
**********************************************************************************/
double Person::getAge()
{
    return age;
}

