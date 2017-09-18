// repeat array main

#include <iostream>
#include "repeatArray.cpp"

using std::cout;
using std::endl;

int main()
{
  double * myArray = new double[3];

  for (int i=0; i<3; i++)
    myArray[i] = (i+1)*3;

  repeatArray(myArray, 3);

  for (int i=0; i<6; i++)
    cout << myArray[i] << endl;

  delete [] myArray;
  myArray = nullptr;

  return 0;
}