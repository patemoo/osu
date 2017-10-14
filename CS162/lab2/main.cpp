/**
 * Author: Patirck Moore
 * Date: October 7, 2017
 * Description: Main program file.
 * */

#include "count.hpp"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
  string fileName;
  ifstream inputFile;

  // allocate memory for letters array.
  int* letters = new int[26];

  // loop until inputFile is open.
  while (!inputFile.is_open())
  {
    // prompt user for a file to read from.
    cout << "Enter a file name to read from." << endl;
    cin >> fileName; // store file name

    // open ifstream.
    inputFile.open(fileName);

    // If the file did not open prompt user to retry.
    if (!inputFile.is_open())
    {
      cout << "No such file. Please try again." << endl;
    }
  }

  count_letters(inputFile, letters);

  // close ifstream.
  inputFile.close();

  // deallocate memory.
  delete [] letters;
  letters = nullptr;

  return 0;
}

