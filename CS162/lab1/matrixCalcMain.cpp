/**
 * Author: Patrick Moore
 * Date: October 1, 2017
 * Description: Matrix Calculator main file.
 * **/

#include "readMatrix.hpp"
#include "determinant.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void printMatrix(int**, int);

int main()
{
  int matrixSize;
  bool valid = false;

  // Prompt user for matrix size.
  cout << "Please select a matrix size." << endl;
  cout << "Enter 2 for (2x2) or 3 for (3x3)" << endl;

  // get and validate input.
  while (!valid)
  {
    cin >> matrixSize;

    if (cin.fail())
    {
      cin.clear();
      cin.ignore();
      cout << "Please enter an integer." << endl;
    }
    else if (!(matrixSize == 2 || matrixSize == 3))
    {
      cout << "You didn't enter 2 or 3. Try again." << endl;
    } 
    else 
    {
      valid = true;
    }
  }

  // Allocate memory for 2D array.
  int** matrixArray = new int*[matrixSize];
  for (int i=0; i<matrixSize; i++)
  {
    matrixArray[i] = new int[matrixSize];
  }
  
  readMatrix(matrixArray, matrixSize);

  printMatrix(matrixArray, matrixSize);

  cout << "\nDeterminant: " << determinant(matrixArray, matrixSize) << endl;

  // Deallocate memory
  delete [] matrixArray;
  matrixArray = nullptr;

  return 0;
}

/**
 * Description: printMatrix loops through the values of the matrix 
 *              and prints out to the console as a square display.
 * */

void printMatrix(int** arrayPtr, int size)
{
  cout << "\nMatrix:\n" << endl;
  for (int i=0; i<size; i++)
  {
    for (int j=0; j<size; j++)
    {
      cout << " " << arrayPtr[i][j];
    }
    cout << endl;
  }
}