/**
 * Author: Patrick Moore
 * Date: October 22, 2017
 * Description: Person class interface.
 * */

#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
using std::string;

class Person
{
private:
  string name = "John Doe";
  int age;
public:
  Person(string);
  virtual string getName();
  int getAge();
  void setAge(int);
  virtual double getScore() = 0;
  virtual void doWork() = 0; 
  virtual bool isStudent() = 0;
};

#endif