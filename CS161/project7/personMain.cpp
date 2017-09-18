// person main

#include <iostream>

#include "Person.cpp"
#include "stdDev.cpp"

using namespace std;

int main ()
{

  Person p1 = Person("patrick", 32);
  Person p2 = Person("Shelsea", 34);
  Person p3 = Person("Steve", 75);
  Person p4 = Person("Laurie", 65);

  const int SIZE = 4;

  Person people[SIZE] = {p1, p2, p3, p4};
  
  cout << stdDev(people, SIZE) << endl;

  return 0;
}