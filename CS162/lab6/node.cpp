/**
 * Author: Patrick Moore
 * Date: Noverber 2, 2017
 * Description: Constructor for the Node struct.
 * */

#include "node.hpp"

Node::Node(int value)
{
  this->val = value;
}

Node::Node(int value, Node *next = nullptr)
{
  this->val = value;
  this->next = next;
}

Node::Node(int value, Node *next = nullptr, Node *prev = nullptr)
 {
   this->val = value;
   this->next = next;
   this->prev = prev;
 }