/************************************************************
 ** Author: Patrick Moore
 ** Date: July 2, 2017
 ** Description: This program accepts five numbers
		 calculates the average of those numbers
		 then prints out the result.
*************************************************************/

#include <iostream>
using namespace std;

int main()
{
  double number1, 
         number2, 
         number3, 
         number4, 
         number5, 
         average;
  
  cout << "Please enter five numbers." << endl;
  
  cin >> number1; 
  cin >> number2;
  cin >> number3;
  cin >> number4;
  cin >> number5;

  average = (number1 + number2 + number3 + number4 + number5) / 5;

  cout << "The average of those numbers is: " << average << endl;

  return 0;
}

