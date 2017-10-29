/**
 * Author: Patrick Moore
 * Date: October 28, 2017
 * Description: Implementations of three recursive functions.
 * */

#include "recursive.hpp"

#include <iostream>
using std::cout;
using std::endl;

/**
 * Description: Prints the chars of a string in reverse order.
 * */
void functionOne(string text)
{
  if (text.size() > 0)
  {
    cout << text[text.size() - 1]; // print out the last char in the array.
    text.pop_back(); // remove the last char from the array.
    functionOne(text); // repeat until the string is empty.
  }
}

/**
 * Description: caluclates the sum of an integer array.
 * */
int functionTwo(int intArray[], int size)
{
  if (size > 1)
  {
    intArray[0] += intArray[size - 1];
    functionTwo(intArray, size - 1);
  }
  return intArray[0];
}

/**
 * Description: Takes an integer and returns its triangle number.
 *              With each return up the stack, the value returned
 *              is added to the previous version of the value.
 * */
int functionThree(int num)
{
  if (num > 0)
  {
    num += functionThree(num - 1); 
  }
  return num;
}