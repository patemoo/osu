/**
 * Author: Patrick Moore
 * Date: October 22, 2017
 * Description: Building class interface.
 * */

#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <string>
using std::string;

class Building
{
private:
  string name;
  int size;
  string address;
public: 
  Building(string, int, string);
  string getName();
  int getSize();
  string getAddress();
};

#endif