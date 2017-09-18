/**
 * Author: Patrick Moore
 * Date: August 14, 2017
 * Description: Store class implementation. A Store can have products
 *              and members added to it. It can look up those products and members
 *              based on their ids. It also has functions for searching for products,
 *              Adding products to a specific members cart as well as checking a member out.
 **/

#include <iostream>
#include <iomanip>

#include "Store.hpp"
#include "Product.hpp"
#include "Customer.hpp"

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

/**
 * Description: Adds a product to the inventory vector
 **/
void Store::addProduct(Product* p)
{
  inventory.push_back(p);
}


/**
 * Description: adds a customer to the members vector
 **/
void Store::addMember(Customer* c)
{
  members.push_back(c);
}


/**
 * Description: returns pointer to matching product or null
 **/
Product* Store::getProductFromID(string productID)
{
  for (int i=0; i<inventory.size(); i++)
  { 
    if (productID == inventory[i]->getIdCode())
    {
      return inventory[i];
    } 
  }
  return NULL;
}


/**
 * Description: returns pointer to matching customer or null
 **/
Customer* Store::getMemberFromID(string accountID)
{
  for (int i=0; i<members.size(); i++)
  {
    if (accountID == members[i]->getAccountID())
    {
      return members[i];
    }
  }
  return NULL;
}


/**
 * Description: Returns a list of products that match a given string
 *              with either their title or description. 
 *              matches case insensative of the first char in the string.
 **/
void Store::productSearch(string str)
{
  char upChar = toupper(str[0]);
  char lowChar = tolower(str[0]);
  
  str[0] = upChar;
  string upStr = str;

  str[0] = lowChar;
  string lowStr = str;

  for (int i=0; i<inventory.size(); i++)
  { 
    if (
      inventory[i]->getTitle().find(upStr) != string::npos || 
      inventory[i]->getDescription().find(upStr) != string::npos ||
      inventory[i]->getTitle().find(lowStr) != string::npos || 
      inventory[i]->getDescription().find(lowStr) != string::npos
    )
    {
      cout << "\n" << inventory[i]->getTitle() << endl;
      cout << "ID code: " << inventory[i]->getIdCode() << endl;
      cout << "price: $" << inventory[i]->getPrice() << endl;
      cout << inventory[i]->getDescription() << endl;
    } 
  }
}


/**
 * Description: addProductToMemberCart adds a product to a specific member's cart. 
 **/
void Store::addProductToMemberCart(string pID, string mID)
{
  Product* productPtr = getProductFromID(pID);
  Customer* memberPtr = getMemberFromID(mID);

  if (NULL == productPtr)
  {
    cout << "Product #" << pID << " not found." << endl;
  }
  if (NULL == memberPtr)
  {
    cout << "Member #" << mID << " not found." << endl;
  }
  if ( NULL != productPtr &&
       NULL != memberPtr &&
       productPtr->getQuantityAvailable() >= 1 )
  {
    memberPtr->addProductToCart(pID);
  } 
  else 
  {
    cout << "Sorry, product #" << pID << " is currently out of stock." << endl; 
  } 
}


/**
 * Description: checkOutMember displays the items in a member's cart 
 *              notifies the member if an item is unavailable 
 *              and gives price totals.
 **/
void Store::checkOutMember(string mID)
{
  Customer* memberPtr = getMemberFromID(mID);

  if (NULL == memberPtr)
  {
    cout << "Member #" << mID << " not found." << endl;
    return;
  }
  if (memberPtr->getCart().size() == 0)
  {
    cout << "There are no items in the cart." << endl;
    return;
  }

  double subtotal = 0;
  double shipping = 0;

  cout << "______________________________\n";

  for (int i=0;i<memberPtr->getCart().size(); i++)
  {
    string productID = memberPtr->getCart()[i];
    Product* productPtr = getProductFromID(productID);
    if (productPtr->getQuantityAvailable() >= 1)
    {
      cout << productPtr->getTitle() << " - $" << productPtr->getPrice() << endl;
      subtotal += productPtr->getPrice();
      productPtr->decreaseQuantity();
    }
    else 
    {
      cout << "Sorry, product #" 
            << productPtr->getIdCode() 
            << ", \"" 
            << productPtr->getTitle() 
            << "\", is no longer available." << endl;
    }
  }

  if (!memberPtr->isPremiumMember())
  {
    shipping = subtotal * .07;
  }

  cout << "\nSubtotal: $" << fixed << setprecision(2) << subtotal << endl;
  cout << "Shipping Cost: $" << fixed << setprecision(2) << shipping << endl;
  cout << "Total: $" << fixed << setprecision(2) << subtotal + shipping << "\n" << endl;

  memberPtr->emptyCart();
}