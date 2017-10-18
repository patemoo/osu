/**
 * Author: Patrick Moore
 * Date: October 17, 2016
 * Description: Player class implementation
 * */

#include "player.hpp"

/**
 * Description: 
 * */
Player::Player()
{
  this->bankRoll = 100000.00;
}


/**
 * Description: 
 * */
double Player::getBankRoll()
{
  return this->bankRoll;
}

/**
 * Description: 
 * */
bool Player::widthdraw(double amount)
{
  if (this->bankRoll > amount)
  {
    this->bankRoll -= amount;
    return true;
  }
  else 
  {
    return false;
  }
} 


/**
 * Description:
 * */
void Player::deposit(double amount)
{
  this->bankRoll += amount;
}