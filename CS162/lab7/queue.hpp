/**
 * Author: Patrick Moore
 * Date: November 9, 2017
 * Description: Queue class interface.
 * */

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "queuenode.hpp"

class Queue
{
private:
  QueueNode *head = nullptr;
public:
  Queue();
  ~Queue();
  bool isEmpty();
  void addBack(int val);
  int getFront();
  void removeFront();
  void printQueue();
};

#endif