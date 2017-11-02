/**
 * Author: Patrick Moore
 * Date: Noverber 2, 2017
 * Description: 
 * */

#include "node.hpp"

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

class LinkedList 
{
private:
  Node* head;
  Node* tail;

public:
  LinkedList();
  void addNodeAtHead(int);
  void addNodeAtTail(int);
  void deleteFirst();
  void deleteLast();
  void printInReverse();
};

#endif