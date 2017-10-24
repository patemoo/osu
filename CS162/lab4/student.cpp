/**
 * Author: Patrick Moore
 * Date: October 22, 2017
 * Description: Student class implementation.
 * */

#include "student.hpp"

#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>
using std::rand;

Student::Student(string name) : Person(name)
{
  srand(time(0));
  Person::setAge(rand() % 4 + 18);
  this->GPA = ((double)rand() / (double)(RAND_MAX)) + rand() % 5;
}

double Student::getScore()
{
  return this->GPA;
}

void Student::doWork()
{
  int hours = rand() % 8 + 2;
  cout << "\n" << this->getName() << " did " << hours << " hours of homework.\n" << endl;
}

bool Student::isStudent()
{
  return true;
}