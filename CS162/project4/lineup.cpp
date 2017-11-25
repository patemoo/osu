/**
 * Author: Patrick Moore
 * Date: November 19, 2017
 * Description: 
 * */

#include "lineup.hpp"

Lineup::Lineup()
{

}

Lineup::~Lineup()
{
  while (!this->isEmpty())
  {
    if (this->head == this->head->next)
    {
      delete this->head;
      this->head = nullptr;
    }
    else
    {
      LineupNode *garbage = this->head;
      this->head->next->prev = this->head->prev;
      this->head->prev->next = this->head->next;
      this->head = this->head->next;
      delete garbage;
    }
  }
}


bool Lineup::isEmpty()
{
  return this->head == nullptr;
}


void Lineup::addBack(Character *type, string name)
{
  if (this->isEmpty())
  {
    this->head = new LineupNode(type, name);
  }
  else if (this->head == this->head->next)
  {
    LineupNode *newNode = new LineupNode(type, name, this->head, this->head);
    this->head->next = newNode;
    this->head->prev = newNode;
  }
  else
  {
    LineupNode *last = this->head->prev;
    LineupNode *newNode = new LineupNode(type, name, this->head, last);
    this->head->prev = newNode;
    last->next = newNode;
  }
}

Character * Lineup::getFighterType()
{
  return this->head->type;
}

string Lineup::getFighterName()
{
  return this->head->name;
}


void Lineup::moveToBack()
{
  // should be able to just change where head is pointing.
  LineupNode * temp = this->head;
  this->head = temp->next;
}


void Lineup::removeDefeated(vector<string> *defeatedList)
{
  // delete the node at the head and add name to the defeated list.
  if (this->head == this->head->next)
    {
      defeatedList->push_back(this->getFighterName());
      delete this->head;
      this->head = nullptr;
    }
    else
    {
      defeatedList->push_back(this->getFighterName());
      LineupNode *garbage = this->head;
      this->head->next->prev = this->head->prev;
      this->head->prev->next = this->head->next;
      this->head = this->head->next;
      delete garbage;
    }
}