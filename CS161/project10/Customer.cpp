/**
 * Author: Patrick Moore
 * Date: August 14, 2017
 * Description: Customer class implementation. Has a constructor
 *              and the member functions addProductToCart, isPremiumMember, emptyCart,
 *              as well as get functions for accountId and Cart.
 **/

#include "Customer.hpp"

using std::string;
using std::vector;

/**
 * Description: This constructor instanciates a new Customer 
 * using the values passed to it.
 **/
Customer::Customer(string n, string a, bool pm)
{
  name = n;
  accountID = a;
  premiumMember = pm;
}


string Customer::getAccountID()
{
  return accountID;
}

vector<string> Customer::getCart()
{
  return cart;
}


/**
 * Description: addProductToCart pushes a product's id to the end of a customer's cart vector.
 **/
void Customer::addProductToCart(string productID)
{
  cart.push_back(productID);
}


/**
 * Description: isPremiumMember returns a boolean reperesenting whether a customer is a premium member.
 **/
bool Customer::isPremiumMember()
{
  return premiumMember;
}


/**
 * Description: emptyCart clears the customer's cart vector.
 **/
void Customer::emptyCart()
{
  cart.clear();
}