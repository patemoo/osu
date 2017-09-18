/**
 * Author: Patrick Moore
 * Date: July 27, 2017
 * Description: This program creates a function that returns 
 *              the median value from a set of numbers
 **/

/**
 * 
 * Description: This function takes two arguments. 
 *              An array of integers and an iterger for the size of that array.
 *              It returns the median value.
 * 
 **/
double findMedian(int numbers[], int size)
{
  double median; // variable to store the median value.
  bool sorted; // Used in conditional to tell when array is sorted
  
  do
  {
    sorted = true; // this will remain true if the array is fully sorted.

    // loop through each number in the array 
    // and compare it to the following number
    // unless it is the last number in the list.
    // If there needs to be a switch set sorted to false.
    for (int i = 0; i < size; i++)
    {
      if (i+1 != size && numbers[i] > numbers[i+1])
      {
        int temp = numbers[i];
        numbers[i] = numbers[i+1];
        numbers[i+1] = temp;
        sorted = false;
      }
    }

  // repeat until the array has been sorted.
  } while (sorted == false);

  // If the array is even calculate the median value.
  if (size % 2 == 0)
  {
    double med1 = static_cast<double>(numbers[size/2-1]);
    double med2 = static_cast<double>(numbers[size/2]);
    median = (med1 + med2)/2;
  } else // else use the middle number of the sorted array
  {
    int index = size/2;
    median = static_cast<double>(numbers[index]);
  }

  // return the median value.
  return median;
};
