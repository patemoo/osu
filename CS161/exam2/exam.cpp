// exam main

#include <iostream>
using namespace std;


class Number
{
  public:
  int value;
};

int printNum(Number num)
{
  num.value = 6;
  return num.value;
}

int main()
{

  // int* myArray[10];

  // for (int i=0;i<10;i++)
  // {
  //   cout << myArray[i] << endl;
  // }

  Number newNum;

  newNum.value = 4;

  cout << printNum(newNum) << endl;

  return 0;
}