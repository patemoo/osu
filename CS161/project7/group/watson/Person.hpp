/***************************************************************************************
 * Name: Jason Watson
 * Date: 7/27/2017
 * Description: This is the class declaration file for the class Person. The class
 * initializes the name and age variables of a person class and then returns the data
 * to the client program.
***************************************************************************************/
#ifndef PERSON_HPP
#define PERSON_HPP
#include<string>

class Person
{
private:
    std::string name;
    double age;
public:
    Person(std::string, double);
    Person();
    std::string getName();
    double getAge();
};
#endif

