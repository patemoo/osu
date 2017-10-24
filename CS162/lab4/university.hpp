/**
 * Author: Patrick Moore
 * Date: October 22, 2017
 * Description: University class interface.
 * */

#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include "building.hpp"
#include "person.hpp"
#include "student.hpp"
#include "instructor.hpp"

#include <string>
using std::string;

#include <vector>
using std::vector;

class University
{
private:
  string name = "Oregon State University";
  vector<Building*> buildings;
  vector<Person*> people; 
public:
  University();
  void addBuilding(Building *);
  void printBuildings();
  void addPerson(Person *);
  void printPeople();
  string getName();
  vector<Person*> getPeople();
};

#endif