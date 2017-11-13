/**
 * Author: Patrick Moore
 * Date: November 9, 2017
 * Description: Queue class implementation
 * */

#include "queue.hpp"

#include <iostream>
using std::cout;
using std::endl;

Queue::Queue()
{

}

Queue::~Queue()
{

}

bool Queue::isEmpty()
{
  return this->head == nullptr;
}


void Queue::addBack(int val)
{
  if (this->isEmpty())
  {
    this->head = new QueueNode(val);
  }
  else if (this->head == this->head->next)
  {
    QueueNode *newNode = new QueueNode(val, this->head, this->head);
    this->head->next = newNode;
    this->head->prev = newNode;
  }
  else
  {
    QueueNode *last = this->head->prev;
    QueueNode *newNode = new QueueNode(val, this->head, last);
    this->head->prev = newNode;
    last->next = newNode;
  }
}


int Queue::getFront()
{
  if (!this->isEmpty())
  {
    return this->head->val;
  }
  return 0;
}


void Queue::removeFront()
{
  if (!this->isEmpty())
  {
    if (this->head == this->head->next)
    {
      delete this->head;
      this->head = nullptr;
    }
    else
    {
      QueueNode *garbage = this->head;
      this->head->next->prev = this->head->prev;
      this->head->prev->next = this->head->next;
      this->head = this->head->next;
      delete garbage;
    }
    cout << "\nFront node has been removed.\n" << endl;
  }
  else
  {
    cout << "\nYour queue is empty. Nothing to remove.\n" << endl;
  }
}


/**
 * Description: prints a space separated list of nodes values from the queue
 *              or a message notifying of an empty queue.
 * */
void Queue::printQueue()
{
  if (!this->isEmpty())
  {
    cout << "\nYour queue is: " << this->head->val << " ";
    QueueNode *current = this->head->next;
    while(current != this->head)
    {
      cout << current->val << " ";
      current = current->next;
    }
    cout << "\n" << endl;
  }
  else
  {
    cout << "\nYour queue is empty.\n" << endl;
  }
}