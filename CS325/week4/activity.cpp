/**
 * Author: Patrick Moore
 * Date: 02/03/2019
 * Description: Activity class implementation
 * */

#include "activity.hpp"


Activity::Activity(int number, int start, int finish)
{
  this->number = number;
  this->start = start;
  this->finish = finish;
}

int Activity::getNumber()
{
  return this->number;
}

int Activity::getStart()
{
  return this->start;
}

int Activity::getFinish()
{
  return this->finish;
}

void Activity::setValues(int number, int start, int finish) {
    this->number = number;
    this->start = start;
    this->finish = finish;
}