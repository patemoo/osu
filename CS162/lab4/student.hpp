/**
 * Author: Patrick Moore
 * Date: October 22, 2017
 * Description: Student class interface.
 * */

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "person.hpp"

class Student : public Person
{
private:
  double GPA;
public:
  Student(string);
  double getScore();
  void doWork();
  bool isStudent();
};

#endif