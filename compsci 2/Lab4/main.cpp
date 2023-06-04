#include "ItemToPurchase.h"
#include "ShoppingCart.h"
#include <iostream>
#include <string>
using namespace std;

void PrintMenu(ShoppingCart cartList);

int main(){
   ShoppingCart myCart;
   string customerName;
   string Date;
   
   cout << "Enter customer's name:\n";
   getline(cin, customerName);
   cout << "Enter today's date:\n";
   getline(cin, Date);
   
   cout << "\nCustomer name: " << customerName;
   cout << "\nToday's date: " << Date << "\n\n";
   
   myCart.SetCustomerName(customerName);
   myCart.SetDate(Date);
   
   PrintMenu(myCart);

   return 0;   
}

void PrintMenu(ShoppingCart cartList){
   ItemToPurchase currCart;
   char choice ;
   int menu = 0;
   bool quit = false;
   
   while(quit == false){
   if(menu == 0){
   cout << "MENU\na - Add item to cart\nd - Remove item from cart\nc - Change item quantity";
   cout << "\ni - Output items' descriptions\no - Output shopping cart\nq - Quit\n\n";
   cout << "Choose an option:\n";
   cin >> choice;
   }
   else{
   cout << "Choose an option:\n";
   cin >> choice;
   }
   
   if(choice == 'd'){
      string removeItemName;
      cout << "REMOVE ITEM FROM CART\nEnter name of item to remove:\n";
      cin.ignore();
      getline(cin, removeItemName);
      cartList.RemoveItem(removeItemName);
   }
   else if(choice == 'a'){
      string name;
      string description;
      int price;
      int quant;
      cout << "ADD ITEM TO CART\nEnter the item name:\n";
      cin.ignore();
      getline(cin,name);
      currCart.SetName(name);
      cout << "Enter the item description:\n";
      getline(cin,description);
      currCart.SetDescription(description);
      cout << "Enter the item price:\n";
      cin >> price;
      currCart.SetPrice(price);
      cout << "Enter the item quantity:\n";
      cin >> quant;
      currCart.SetQuantity(quant);
      cartList.AddItem(currCart);
      cout << endl;
   } 
   else if(choice == 'c'){
      cartList.ModifyItem(currCart);
   }
   else if(choice == 'i'){
      cartList.PrintDecriptions();
   }
   else if(choice == 'o'){
      cartList.PrintTotal();
   }
   else if(choice == 'q'){
      quit = true;
   }
   else{
      menu=1;
      }
   }
}