/**
 * Author: Patrick Moore
 * Date: November 15, 2017
 * Description: Binary Search implimintation from the book.
 * */

#include "binarysearch.hpp"

int binarySearch(vector<int> nums, int target)
{
  int first = 0;
  int last = nums.size() - 1;
  int middle;
  int position = -1;
  bool found = false;
  
  while (!found && first <= last)
  {
    middle = (first + last) / 2;
    if (nums[middle] == target)
    {
      found = true;
      position = middle;
    }
    else if (nums[middle] > target)
    {
      last = middle - 1;
    }
    else 
    {
      first = middle + 1;
    }
  }
  return position;
}