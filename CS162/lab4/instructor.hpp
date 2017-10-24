/**
 * Author: Patrick Moore
 * Date: October 22, 2017
 * Description: Instructor class interface.
 * */

#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include "person.hpp"

class Instructor : public Person
{
private:
  double rating;
public: 
  Instructor(string);
  double getScore();
  void doWork();
  bool isStudent();
};

#endif