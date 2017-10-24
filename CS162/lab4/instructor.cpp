/**
 * Author: Patrick Moore
 * Date: October 22, 2017
 * Description: Instructor class implementation.
 * */

#include "instructor.hpp"

#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>
using std::rand;

Instructor::Instructor(string name) : Person(name)
{
  srand(time(0));
  Person::setAge(rand() % 30 + 24);
  this->rating = ((double)rand() / (double)(RAND_MAX)) + rand() % 6;
}

double Instructor::getScore()
{
  return this->rating;
}

void Instructor::doWork()
{
  int hours = rand() % 8 + 2;
  cout << "\n" << this->getName() << " graded papers for " << hours << " hours.\n" << endl;
}

bool Instructor::isStudent()
{
  return false;
}