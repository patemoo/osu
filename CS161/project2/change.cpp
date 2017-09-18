/*********************************************************************
 * Author: Patrick Moore
 * Date: July 2, 2017
 * Description: This program takes a number of cents, from 0 to 99,
                calculates the quantity of each coin type 
                that would produce the fewest number of total coins,
                then prints out the result.    
*********************************************************************/

#include <iostream>
using namespace std;

int main ()
{
  const int QUARTER = 25,
            DIME = 10,
            NICKLE = 5;
  
  int cents,
      quarters,
      dimes,
      nickles,
      pennies,
      leftover;
      
  cout << "Please enter an amount in cents less than a dollar." << endl;
  cin >> cents;
  
  quarters = cents / QUARTER;
  leftover = cents % QUARTER;
  dimes = leftover / DIME;
  leftover %= DIME;
  nickles = leftover / NICKLE;
  leftover %= NICKLE;
  pennies = leftover; 

  cout << "Your change will be:" << endl;
  cout << "Q: " << quarters << endl;
  cout << "D: " << dimes << endl;
  cout << "N: " << nickles << endl;
  cout << "P: " << pennies << endl;

  return 0;
}
