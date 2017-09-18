/**************************************************************************
 * Author: Patrick Moore
 * Date: July 14, 2017
 * Description: This program takes in a value. It takes one of two actions 
 *              on that value depending on whether it is odd or even.
 *              These actions continue to be taken on each resulting value
 *              until the result equals 1.
 *              The program then returns the number of iterations 
 *              taken to get there. 
 * *************************************************************************/

int hailstone (int value)
{
  int count = 0;

  // continue until value == 1.
  while ( value != 1 )
  { 
    if (value % 2 == 0) // value is even
    {
      value /= 2;
    } else { // or value is odd
      value *= 3;
      value += 1;
    }

    count++;  // increase count	
  }
  return count;

}
