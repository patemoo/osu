/************************************************************************
** Author:      Nicholas Blackburn
** Date:        07/29/17
** Description: This header file is a class declaration for the class
		Person.  It has two data attributes, a string variable
		called name and a double variable called age.  It has
		a default constructor that initializes the values to
		the empty string and zero respectively (while the spec,
		did not mention a default constructor, my g++ compiler
		on the flip server was giving an error when I was
		testing in my Main file upon attempting to create an
		array of Persons. It seemed that adding a default
		constructor made this error go away due to the compiler
		error about not having the proper type of constructor).
		It has a constructor that takes two values of string 
		and double to initialize each data attribute for name
		and age.  It has a getName() method that returns the
		name and a getAge() method that returns the age.
************************************************************************/

//  Person.hpp
#include <string>

//  class Person
//  	private
//  		name and age
//  	public
//  		default constructor
//  		constructor
//  		get methods
//  			getName
//  			getAge
class Person
{
	private:
		std::string name;
		double age;
	public:
		std::string getName();
		double getAge();
		Person();
		Person(std::string nameVal, double ageVal);
		~Person();
};
