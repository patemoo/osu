/**********************************************************************
 * Author: Patrick Moore
 * Date: July 9, 2017
 * Description: This program prompts the user for an integer 
 *              that a player will later guess.
 *              The number is stored and the player 
 *              is pormpted to begin guessing. 
 *              Each guess is compared to the initial number. 
 *              The player is notified  whether their guess was
 *              too high or too low. When there is finally a match 
 *              the program prints out how many attempts were made. 
 * *******************************************************************/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
  int number,
      guess,
      tries = 0;

  // prompt for and save secret number:
  cout << "Enter the number for the player to guess." << endl;
  cin >> number;

  cout << "Enter your guess." << endl;

  do
  {
    // track number of attempts: 
    tries++;
    
    // compare guess to the secret number:
    cin >> guess;
    if ( guess < number )
    {
      cout << "Too low - try again." << endl;
    } else if ( guess > number )
    {
      cout << "Too high - try again." << endl;
    }
    // repeat if guess and number are not equal:
  } while ( guess != number ); 

  // dispaly attempt amount:
  cout << "You guessed it in " << tries << " tries." << endl;

  return 0;
}
