/***********************************************************************************************
 * Name: Jason Watson
 * Date: 2/27/2017
 * Description: This is function stdDev that takes two parameters and returns the standard deviation
 * of the ages found in the class Person.  It takes in its parameter an array of objects.
 ************************************************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include "Person.hpp"
using namespace std;
/********************************************************************************************************
double stdDev(Person [], int);

int main()
{
	Person person1("George", 18);
	Person person2("Julie", 22);
	Person person3("Frank", 110);
	Person person4("Jason", 87);
	Person person5("Bob", 66);
	Person persons[5] = {person1, person2, person3, person4, person5};
	double standard_dev= stdDev(persons, 5);
	cout << "standard deviation: " << standard_dev << endl;
	return 0; 
}
***************************************************************************************************************/

/*****************************************************************************************************
 * function stdDev: This function takes two parameters, an array of objects, and size of the array.
 * It returns the standard deviation of the values found in the array of objects.  
*******************************************************************************************************/
double stdDev(Person person[], int size)
{
    double sum = 0.0;
    double mean;
    double meanSum = 0.0;
    double standard_deviation;
	
    for (int index = 0; index < size; index++)
    {
        sum = sum + person[index].getAge();            // first find the sum of the ages
    }
        
    mean = sum / size;                 // calculates the mean
    
    for (int index = 0; index < size; index++)
    {
        meanSum = meanSum + pow(person[index].getAge() - mean, 2);   // subracts the mean from each array object and then squares the answer
    }
	   
	
    standard_deviation = sqrt(meanSum / size);                  // find the standard deviation by finding the square root of the value in meanSum
    
    return standard_deviation;
}
        
        


