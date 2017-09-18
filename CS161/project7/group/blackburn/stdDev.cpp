/************************************************************************
** Author:      Nicholas Blackburn
** Date:        07/29/17
** Description: This file is contains a function called stdDev that
		takes two parameters, an array of Persons and the size
		of the array.  It returns the standard deviation of all
		of the ages in the array (using N).
************************************************************************/

//  stdDev.cpp
#include "Person.hpp"
#include <cmath>

//  function stdDev
//  	two parameters
//  		array of Persons
//  		size of that array
//	Steps to find the standard deviation
//		calculate the mean of the ages
//		for each age, subtract the mean, and square the result
//		find the mean of all of the squared differences
//		find the square root of that second mean
double stdDev(Person myArray[], int size)
{
	//  initialize two means to zero
	double meanFirst = 0;
	double meanSecond = 0;

	//  Sum up the first mean
	for (int i = 0; i < size; i++)
	{
		//  Add up each age
		meanFirst += myArray[i].getAge();
	}

	//  Average the first mean
	meanFirst /= size;

	//  Sum up the squared differences
	for (int i = 0; i < size; i++)
	{
		//  Subtract each age from the mean, square the result
		double differenceSquared = std::pow((myArray[i].getAge()
					   - meanFirst), 2.0);
		//  Add up each result
		meanSecond += differenceSquared;
	}

	//  Average the second mean
	meanSecond /= size;

	//  Calculate the variance, the square root of the second mean
	double standardDev = std::sqrt(meanSecond);

	//  return the standard deviation
	return standardDev;
}
