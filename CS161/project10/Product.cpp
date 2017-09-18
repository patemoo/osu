/**
 * Author: Patrick Moore
 * Date: August 14, 2017
 * Description: Product class implementation. Methods include the constructor,
 *              decreaseQuantity and get functions for idCode, title, description,
 *              price and quantityAvailable.
 **/

#include "Product.hpp"
using std::string;

/**
 * Description: This function takes in values to instanciate a new Product.
 **/
Product::Product(string id, string t, string d, double p, int qa)
{
  idCode = id;
  title = t;
  description = d;
  price = p;
  quantityAvailable = qa;
}


string Product::getIdCode()
{
  return idCode;
}

string Product::getTitle()
{
  return title;
}

string Product::getDescription()
{
  return description;
}

double Product::getPrice()
{
  return price;
}

int Product::getQuantityAvailable()
{
  return quantityAvailable;
}


/**
 * Description: This function decreases the quantity available by one.
 **/
void Product::decreaseQuantity()
{
  quantityAvailable--;
}