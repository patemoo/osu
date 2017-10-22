/**
 * Author: Patrick Moore
 * Date: October 17, 2016
 * Description: random event function prototype.
 * */

#ifndef RANDOM_HPP
#define RANDOM_HPP

#include "zoo.hpp"

double randomEvent(Zoo &);
void sicknessDeath(Zoo &);
double attendanceBoom(int);
void babyBoom(Zoo &);
void normalDay();

#endif