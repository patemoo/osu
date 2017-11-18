/**
 * Author: Patrick Moore
 * Date: November 15, 2017
 * Description: Bubble sort implementation from class lecture:
 * */

#include "bubblesort.hpp" 

void bubbleSort(vector<int> &nums)
{
  int size = nums.size();
  for (int i=size-1; i >= 0; i--)
  {
    for (int j=1; j<=i; j++)
    {
      if (nums[j-1] > nums[j])
      {
        int temp = nums[j-1];
        nums[j-1] = nums[j];
        nums[j] = temp;
      }
    }
  }
}