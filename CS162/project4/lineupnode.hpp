/**
 * Author: Patrick Moore
 * Date: November 19, 2017
 * Description: 
 * */

#ifndef LINEUPNODE_HPP
#define LINEUPNODE_HPP

#include "character.hpp"

#include "vector"
using std::vector;

struct LineupNode
{
  LineupNode *next;
  LineupNode *prev;
  Character *type;
  string name;
  LineupNode(Character *, string);
  LineupNode(Character *, string, LineupNode *, LineupNode *);
};

#endif