/**
 * Author: Patrick Moore
 * Date: August 2, 2017
 * Description: repeatArray takes in a pointer to an array
 *              and an integer representing the size of that array.
 *              A tempPointer is initialized to save the original 
 *              address being pointed to. After that memory is
 *              dynamically allowcated to the passed in pointer,
 *              double the size of the initial array.
 *              The first and second half of the new array are set
 *              to match the values of the original array.
 *              finally the tempPointer is deleted 
 *              and the memory is returned to the heap.
 **/

void repeatArray(double * &arrayPointer, int size)
{
  // Store the array's original address in tempPointer.
  double* tempPointer = arrayPointer;
  // Create a const int that is double the size of the original array.
  const int NEW_SIZE = size * 2;

  // Allocate memory for double the size of the original array.
  arrayPointer = new double[NEW_SIZE];

  // Simultaneously starting from the begining and middle of the array 
  // add each vaule into their new respective locations.
  for (int i=0; i<size; i++)
  {
    arrayPointer[i] = arrayPointer[i+size] = tempPointer[i];
  }

  delete [] tempPointer;
  tempPointer = nullptr;
}