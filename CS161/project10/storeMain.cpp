// store main

#include <iostream>

#include "Store.hpp"

using std::cout;
using std::endl;

int main()
{
  Store store1;

  Product p1(
    "123", 
    "red blender", 
    "sturdy blender perfect for making smoothies and sauces",
    350,
    10
  );
  
  Product p2(
    "345",
    "hot air balloon",
    "fly into the sky in your own balloon - comes in red, blue or chartreuse",
    700,
    1
  );

  Product p3(
    "678",
    "dinner chair",
    "mid-century modern danish dinner chair",
    299.99,
    6
  );
  
  // cout << p1.getIdCode() << endl;
  // cout << p1.getTitle() << endl;
  // cout << p1.getDescription() << endl;
  // cout << p1.getPrice() << endl;
  // cout << p1.getQuantityAvailable() << endl;
  // p1.decreaseQuantity();
  // cout << p1.getQuantityAvailable() << endl;

  Customer c1("Patrick", "001", false);
  Customer c2("Shelsea", "002", true);

  cout << c1.getAccountID() << endl;
  cout << c1.isPremiumMember() << endl;


  store1.addProduct(&p1);
  store1.addProduct(&p2);
  store1.addProduct(&p3);

  store1.productSearch("Red");

  store1.addMember(&c1);
  store1.addMember(&c2);

  store1.checkOutMember("002");

  store1.addProductToMemberCart("345", "002");

  store1.addProductToMemberCart("345", "001");
  store1.addProductToMemberCart("123", "001");
  store1.addProductToMemberCart("678", "001");

  store1.checkOutMember("002");
  store1.checkOutMember("001");


  store1.checkOutMember("001");


  
  

  return 0;
}

