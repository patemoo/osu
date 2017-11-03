/**
 * Author: Patrick Moore
 * Date: Noverber 2, 2017
 * Description: Node struct interface
 * */

#ifndef NODE_HPP
#define NODE_HPP

struct Node 
{
  int val;
  Node *next;
  Node *prev;
  Node(int);
  Node(int, Node *);
  Node(int, Node *, Node *);
};

#endif