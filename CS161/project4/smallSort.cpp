/***********************************************************************
 * Author: Patrick Moore
 * Date: July 14, 2017
 * Description: This program sorts 3 numbers from lowest to hightest. 
 * **********************************************************************/

void smallSort(int &a, int &b, int &c)
{
  // keep looping until order is correct.
  while (!(a < b && b < c))
  {
    int temp;

    // compare and swap first two values if needed
    if (a > b)
    {
      temp = a;
      a    = b;
      b = temp;
    }

    // compare and swap last two values if needed
    if (b > c)
    {
      temp = b;
      b    = c;
      c = temp;
    }
  }
}
