/**
 * Author: Patrick Moore
 * Date: October 1, 2017
 * Description: readMatrix implementation.
 *              Prompts user for each number in the matrix.
 * **/

#include "readMatrix.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


void readMatrix(int** matrixPtr, int size) 
{
  int qty = size * size;
  cout << "Pleae enter " << qty << " integers." << endl;

  for (int i=0; i<size; i++)
  {
    for (int j=0; j<size; j++)
    {
      cin >> matrixPtr[i][j];
    }
  }
}