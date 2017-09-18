/*****************************************************************************
 * Author: Ruben M Torres
 * Date:; July 30, 2017
 * Description: This file contains a function, stdDev, that takes an array of 
 * Persons, the size size of the array, and computes the standard deviation
 * by finding the mean of the ages of the array, 
 * **************************************************************************/
#include "Person.hpp"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

double stdDev(Person array[], int size);

double stdDev(Person array[], int size)
{
	double sum = 0.0;
	double squareSum = 0.0;

	double mean = 0.0;
	double squareMean = 0.0;

	
	for(int i=0; i<=(size-1); i++)
	{
		sum += array[i].getAge();
	}
	
	mean = (sum / size);	

	for(int i=0; i<=(size-1); i++)
	{
		squareSum += ((array[i].getAge()-mean)*(array[i].getAge()-mean));
	}

	squareMean = (squareSum / size);

	return sqrt(squareMean);
}	 
