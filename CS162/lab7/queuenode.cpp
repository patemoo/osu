/**
 * Author: Patrick Moore
 * Date: November 9, 2017
 * Description: QueueNode struct implementation.
 * */

#include "queuenode.hpp"

QueueNode::QueueNode(int val)
{
  this->val = val;
  this->next = this;
  this->prev = this;
}


QueueNode::QueueNode(int val, QueueNode *next, QueueNode *prev)
{
  this->val = val;
  this->next = next;
  this->prev = prev;
}