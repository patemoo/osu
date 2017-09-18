/*******************************************************************
 ** Author: Patrick Moore
 ** Date: July 2, 2017
 ** Description: This program takes in a Celsius temperature
                 converts it to Fahrenheit and prints the result.
*******************************************************************/

#include <iostream>
using namespace std;

int main()
{
  double c, // Celsius
         f; // Fahrenheit

  cout << "Please enter a Celsius temperature." << endl;
  cin >> c;
  
  // temperature convertion:
  f = 9.0 / 5.0 * c + 32.0;

  cout << "The equivalent Fahrenheit temperature is: \n" << f << endl;

  return 0;
}
