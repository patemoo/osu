/*********************************************************************** 
 * Author: Patrick Moore
 * Date: July 8, 2017
 * Description: This program asks the user how many numbers 
 *              they would like to enter. Then takes in that many numbers.
 *              The program compares all the numbers
 *              then outputs the min and max number from the set. 
***********************************************************************/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
  int iterations,
      min, 
      max;

  // prompt the user for integer quantity and store the value
  cout << "How many integers would you like to enter?" << endl;
  cin >> iterations;

  // prompt the user to begin entering integers
  cout << "Please enter " << iterations << " integer(s)." << endl;
  for ( int i = 0; i < iterations; i++ ) 
  {
    int input;
    cin >> input;
    
    // set min and max to the first input value
    if (i == 0) 
    {
      min = input;
      max = input;
    }
    // then compare each additional value as they are entered 
    else { 
      if (min > input)
      {
        min = input;
      }
      if (max < input)
      {
        max = input;
      }	
    }
  } 
  // after all inputs are entered print results
  cout << "min: " << min << endl;
  cout << "max: " << max << endl;

  return 0;
}
