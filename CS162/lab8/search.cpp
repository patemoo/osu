/**
 * Author: Patrick Moore
 * Date: November 15, 2017
 * Description: 
 * */

#include "search.hpp"

int search(vector<int> nums, int target)
{
  int position = -1;
  for (int i=0; i<nums.size(); i++)
  {
    if (nums[i] == target)
    {
      position = i;
    }
  }
  return position;
}