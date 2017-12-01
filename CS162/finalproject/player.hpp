/**
 * Author: Patrick Moore
 * Date: November 29, 2017
 * Description: Player class interface
 * */


#ifndef PLAYER_HPP
#define PLAYER_HPP

class State; // forward decloration.

enum Party{Dem = 1, Rep, Ind};

class Player
{
private:
  Party party;
  State *currentLocation;
  int votes;
public:
  Player(Party);
  Party getParty();
  int getVotes();
  void addVotes(int);
  void removeVotes(int);
  void setLocation(State *);
  State* getLocation();
};

#endif