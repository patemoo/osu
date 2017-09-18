/**
 * Author: Patrick Moore
 * Date: July 29, 2017
 * Description: Person class interface declaration.
 *              Person has two member variables name(string) and age(double).
 **/

 #ifndef PERSON_HPP
 #define PERSON_HPP

 #include <string>
 using std::string;

class Person 
{
  private:
    string name;
    double age;
  public:
    Person(string, double);
    string getName();
    double getAge();
};

 #endif