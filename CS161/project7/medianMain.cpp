// median main:

#include <iostream>

#include "findMedian.cpp"

using std::cout;
using std::endl;

// double findMedian(int array[], int size);

int main ()
{
  const int SIZE = 5;
  int array[SIZE] = {5, 4, 3, 2, 1};

  cout << findMedian(array, SIZE) << endl;

  return 0;
}

