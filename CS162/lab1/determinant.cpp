/**
 * Author: Patrick Moore
 * Date: October 1, 2017
 * Description: determinant function implementation.
 *              
 * **/

#include "determinant.hpp"

int determinant(int** matrixPtr, int size)
{
  int result = 0;

  if (size == 2) // calculate determinate for 2x2 matrix:
  {
    result =
    matrixPtr[0][0] * matrixPtr[1][1] 
    -
    matrixPtr[0][1] * matrixPtr[1][0];
  }
  else if (size == 3) // calculate determinate for 3x3 matrix:
  {
    result = 
    matrixPtr[0][0] *
      (matrixPtr[1][1] * matrixPtr[2][2]
      -
      matrixPtr[1][2] * matrixPtr[2][1])
    -
    matrixPtr[0][1] *
      (matrixPtr[1][0] * matrixPtr[2][2]
      -
      matrixPtr[1][2] * matrixPtr[2][0])
    +
    matrixPtr[0][2] *
      (matrixPtr[1][0] * matrixPtr[2][1]
      -
      matrixPtr[1][1] * matrixPtr[2][0]);
  }

  return result;
}