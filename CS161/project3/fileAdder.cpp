/**************************
 * Author: Patrick Moore
 * Date: July 9, 2017
 * Description: This program reads numbers from a file
 *              adds them together and prints the result 
 *              to an output file.  
 * *****************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  string fileName;
  ifstream inputFile;
  ofstream outputFile;
  int number,
      sum;

  cout << "What file would you like to read from?" << endl;
  cin >> fileName;

  inputFile.open(fileName);

  // If file does not exist or can not be opened 
  // prompt user and exit program.
  if ( !inputFile.is_open() )
  {
    cout << "Could not access file." << endl;
    return 0;
  }
  
  // Add numbers from file to sum until EOF is reached.
  while ( inputFile >> number ) 
  {
    sum += number;
  }
 
  // close inputFile stream.
  inputFile.close();  

  // output result to sum.txt
  outputFile.open("sum.txt");
  outputFile << sum;
  outputFile.close(); 

  return 0;
} 
