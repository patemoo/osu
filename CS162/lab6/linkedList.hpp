/**
 * Author: Patrick Moore
 * Date: Noverber 2, 2017
 * Description: 
 * */


#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "node.hpp"


class LinkedList 
{
private:
  Node *head;
  Node *tail;
public:
  LinkedList();
  void addNodeAtHead(int);
  void addNodeAtTail(int);
  void deleteFirst();
  void deleteLast();
  void printInReverse();
  void printList();
  void printHead();
  void printTail();
};

#endif