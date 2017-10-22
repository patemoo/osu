/**
 * Author: Patrick Moore
 * Date: October 17, 2016
 * Description: Zoo class interface
 * */

#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"

#include <vector>
using std::vector;

#ifndef ZOO_HPP
#define ZOO_HPP

enum AnimalName{TIGER, PENGUIN, TURTLE};

class Zoo
{
  private:
    vector<Tiger> tigers{};
    vector<Penguin> penguins{};
    vector<Turtle> turtles{};
  public:
    Zoo();
    void addAnimal(AnimalName, int, Age);
    int removeRandomAnimal();
    void increaseAgeOnAll();
    int getAnimalCount(AnimalName);
    vector<Tiger> getTigers();
    vector<Penguin> getPenguins();
    vector<Turtle> getTurtles();
};

#endif