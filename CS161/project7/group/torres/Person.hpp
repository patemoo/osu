/****************************************************************************
 * Author: Ruben M Torres
 * Date: July 30, 2017
 * Description: This is the declaration file for the Class Person.
 * It has name and age class variables that are string and double respectively.
 * It also contains a constructor prototpye and functions to call for age and 
 * name. Implementation file is in Person.cpp. 
 * *************************************************************************/
#ifndef PERSON_HPP
#define PERSON_HPP
#include <string>
using namespace std;

class Person
{
	private:
	string name;
	double age;

	public:
	Person(string, double);
	string getName();
	double getAge();
};
#endif
