/**
 * Author: Patrick Moore
 * Date: Noverber 2, 2017
 * Description: 
 * */

#include "linkedList.hpp"

#include <iostream>
using std::cout;
using std::endl;

LinkedList::LinkedList()
{
  this->head = nullptr;
  this->tail = nullptr;
}

/**
 * Description: 
 * */
void LinkedList::addNodeAtHead(int val)
{
  // if empty set the head and tail to a new Node with the passed in value.
  if (this->head == nullptr)
  {
    this->head = new Node(val);
    this->tail = this->head;
  }
  else // If not empty add a Node at the head of the list.
  {
    Node *temp = this->head;
    this->head = new Node(val, temp);
    temp->prev = this->head;
  }
}


/**
 * Description: 
 * */
void LinkedList::addNodeAtTail(int val)
{
  // if empty set the tail and head to a new Node with the passed in value.
  if (this->tail == nullptr)
  {
    this->tail = new Node(val);
    this->head = this->tail;
  }
  else // if not empty add a Node at the tail of the list.
  {
    Node *temp = this->tail;
    this->tail = new Node(val, nullptr, temp);
    temp->next = this->tail;
  }
}


/**
 * Description: 
 * */
void LinkedList::deleteFirst()
{
  if (this->head && this->head->next)
  {
    Node *garbage = this->head;
    this->head = garbage->next;
    this->head->prev = nullptr;
    delete garbage;
  }
  else if (this->head != nullptr)
  {
    this->head = nullptr;
    this->tail = nullptr;
  }
  else
  {
    cout << "\nThe list is empty!\n" << endl;
  }
}


/**
 * Description: 
 * */
void LinkedList::deleteLast()
{
  if (this->tail && this->tail->prev)
  {
    Node *garbage = this->tail;
    this->tail = garbage->prev;
    this->tail->next = nullptr;
    delete garbage;
  }
  else if (this->tail != nullptr)
  {
    this->tail = nullptr;
    this->head = nullptr;
  }
  else
  {
    cout << "\nThe list is empty!\n" << endl;
  }
}


/**
 * Description: 
 * */
void LinkedList::printInReverse()
{
  Node *node = this->tail;
  cout << "Your linked list in reverse: ";
  if (!node)
  {
    cout << "empty";
  }
  while (node)
  {
    cout << node->val << " ";
    node = node->prev;
  }
  cout << endl;
}


/**
 * Description: 
 * */
void LinkedList::printList()
{
  Node *node = this->head;
  cout << "Your linked list is: ";
  if (!node)
  {
    cout << "empty";
  }
  while (node)
  {
    cout << node->val << " ";
    node = node->next;
  }
  cout << endl;
}


/**
 * Description: 
 * */
void LinkedList::printHead()
{
  if (this->head)
  {
    cout << "Head value: " << this->head->val << endl;
  }
}


 /**
 * Description: 
 * */
void LinkedList::printTail()
{
  if (this->tail)
  {
    cout << "Tail value: " << this->tail->val << endl;
  }
}