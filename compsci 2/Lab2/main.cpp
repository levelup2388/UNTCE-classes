#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

int main() {
   
   ItemToPurchase item1;
   ItemToPurchase item2;
   string name;
   int price;
   int quant;
   int product;
   int total=0;
   
   //item 1 collect
   cout << "Item 1\nEnter the item name:\n";
   getline(cin,name);
   cout << "Enter the item price:\n";
   cin >> price;
   cout << "Enter the item quantity:\n\n";
   cin >> quant;
   item1.SetName(name);
   item1.SetPrice(price);
   item1.SetQuantity(quant);
   cin.ignore();
   //item 2 collect
   cout << "Item 2\nEnter the item name:\n";
   getline(cin,name);
   cout << "Enter the item price:\n";
   cin >> price;
   cout << "Enter the item quantity:\n\n";
   cin >> quant;
   item2.SetName(name);
   item2.SetPrice(price);
   item2.SetQuantity(quant);
   //calc and output
   cout <<  "TOTAL COST\n";
   product = item1.GetPrice() * item1.GetQuantity();
   total+=product;
   cout << item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = $" << product << endl;
   product = item2.GetPrice() * item2.GetQuantity();
   total+=product;
   cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $" << product << "\n\n";
   cout << "Total: $" << total << endl;/* Type your code here */
   
   
   return 0;
}