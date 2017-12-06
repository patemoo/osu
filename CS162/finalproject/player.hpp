/**
 * Author: Patrick Moore
 * Date: November 29, 2017
 * Description: Player class interface
 * */


#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
using std::string;

class State; // forward decloration.

enum Party{Dem = 1, Rep};

class Player
{
private:
  string name;
  Party party;
  State *currentLocation;
  int votes = 0;
public:
  Player(Party, string);
  string getParty();
  string getName();
  int getVotes();
  bool addVotes(int);
  void removeVotes(int);
  void setLocation(State *);
  State* getLocation();
};

#endif