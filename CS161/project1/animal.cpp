/*****************
 ** Author: Patrick Moore
 ** Date: June 22, 2017
 ** Description: This program creates a variable called faveAnimal. 
                 Then prompts the user to enter their favorite animal 
                 and stores the imput in faveAnimal.
                 After that a message prints out telling the user
                 what their favorite animal is.
 *****************/

#include <iostream>
#include <string>

// a simple example program
int main()
{
  std::string faveAnimal;
  std::cout << "Please enter your favorite animal." << std::endl;
  std::cin >> faveAnimal;
  std::cout << "Your favorite animal is the " << faveAnimal;
  std::cout << "." << std::endl;

  return 0;
}


