/**
 * Author: Patrick Moore
 * Date: November 9, 2017
 * Description: QueueNode struct interface 
 * */

#ifndef QUEUENODE_HPP
#define QUEUENODE_HPP

struct QueueNode
{
  QueueNode *next;
  QueueNode *prev;
  int val;
  QueueNode(int);
  QueueNode(int, QueueNode *, QueueNode *);
};

#endif