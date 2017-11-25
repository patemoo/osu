/**
 * Author: Patrick Moore
 * Date: November 19, 2017
 * Description: LineupNode struct implementation.
 * */

#include "lineupnode.hpp"

LineupNode::LineupNode(Character *type, string name)
{
  this->type = type;
  this->name = name;
  this->next = this;
  this->prev = this;
}


LineupNode::LineupNode(Character *type, string name, LineupNode *next, LineupNode *prev)
{
  this->type = type;
  this->name = name;
  this->next = next;
  this->prev = prev;
}