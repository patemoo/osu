/**
 * Author: Patrick Moore
 * Date: November 25, 2017
 * Description: Palindrome function implementation
 * */

#include "palindrome.hpp"

#include <iostream>
using std::cout;

#include <stack>
using std::stack;

void palindrome(string initString)
{
  int size = initString.size();
  stack<char> temp;
  cout << "\n" << initString;

  for (int i=0; i<size; i++)
  {
    temp.push(initString[i]);
  }
  for (int i=0; i<size; i++)
  {
    cout << temp.top();
    temp.pop();
  }

  cout << "\n";
}
