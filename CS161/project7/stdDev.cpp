/**
 * Author: Patrick Moore
 * Date: July 29, 2017
 * Description: This program contains two functions.
 *              Both take in a Person array and its size.
 *              One returns the standard deviation of ages 
 *              and the other returns the age mean.
 **/

#include <cmath>
#include "Person.hpp"

using std::pow;
using std::sqrt;

double calcMean(Person people[], int size);

/**
 * Description: This function takes a Person array and its size
 *              then calculates and returns the standard deviation of ages.
 **/
double stdDev(Person people[], int size)
{
  double sigma;
  double numerator = 0.0;
  double mean = calcMean(people, size);

  // For all ages subtract the mean then square and add to the numerator variable.
  for (int i = 0; i < size; i++)
  {
    numerator += pow(people[i].getAge() - mean, 2);
  }

  // Calculate the square root of the numerator var divided by the size of the array.
  sigma = sqrt(numerator / static_cast<double>(size));

  return sigma;
}


/**
 * Description: This function takes a Person array and its size
 *              and returns the mean of the ages.
 **/
double calcMean(Person people[], int size)
{
  double ageSum = 0.0;
  double mean;

  // Add up all ages.
  for (int i = 0; i < size; i++)
  {
    ageSum += people[i].getAge();
  }

  // Divide the sum of ages by the size of the array.
  mean = ageSum / static_cast<double>(size);
  
  return mean;
}