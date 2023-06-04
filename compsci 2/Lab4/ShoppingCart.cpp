#include <iostream>
using namespace std;

#include "ShoppingCart.h"

ShoppingCart::ShoppingCart(){
   customerName = "none";
   currentDate = "January 1, 2016";
}
ShoppingCart::ShoppingCart(string name, string Date){
   customerName = name;
   currentDate = Date;
}
void ShoppingCart::SetCustomerName(string name){
   customerName = name;
}
void ShoppingCart::SetDate(string Date){
   currentDate = Date;
}
string ShoppingCart::GetCustomerName(){
   return customerName;
}
string ShoppingCart::GetDate(){
   return currentDate;
}
void ShoppingCart::AddItem(ItemToPurchase currCart){
   cartItems.push_back(currCart);
}
void ShoppingCart::RemoveItem(string name){
   int size =cartItems.size();
   int ext = 0;
   for(int i =0; i<size;i++){
      if(cartItems[i].GetName()==name){
         cartItems.erase(cartItems.begin()+1);
         cout << endl;
         ext++;
      }
   }
   if(ext==0){
      cout << "Item not found in cart. Nothing removed.\n\n";
   }
}
void ShoppingCart::ModifyItem(ItemToPurchase currCart){
   string name;
   string checkName;
   int newQuantity;
   //int place;
   int size =cartItems.size();
   cout << "CHANGE ITEM QUANTITY\nEnter the item name:\n";
   cin.ignore();
   getline(cin, name);
   cout << "Enter the new quantity:\n";
   cin >> newQuantity;
   for(int i =0; i<size;i++){
      checkName=cartItems[i].GetName();
      if(checkName==name){
         //place=i;
         cartItems[i].SetQuantity(newQuantity);
      }
      else if((checkName!=name)&&(i==size-1)){
         cout << "Item not found in cart. Nothing modified.\n";
      }
   }
   cout << endl;
}
int ShoppingCart::GetNumItemsInCart(){
   ItemToPurchase currCart;
   int cartSize=0;
   int size =cartItems.size();
   for(int i=0;i<size;i++){
      cartSize += cartItems[i].GetQuantity();
   }
   return cartSize;
}
int ShoppingCart::GetCostOfCart(){
   ItemToPurchase currCart;
   int cartPrice=0;
   int total = 0;
   int size =cartItems.size();
   for(int i=0;i<size;i++){
      total = cartItems[i].GetPrice() * cartItems[i].GetQuantity();
      cartPrice += total;
   }
   return cartPrice;
}
void ShoppingCart::PrintTotal(){
   ItemToPurchase currCart;
   int total;
   int size =cartItems.size();
   cout << "OUTPUT SHOPPING CART\n";
   cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() <<endl;
   cout << "Number of Items: " << GetNumItemsInCart() << "\n\n";
   if(GetNumItemsInCart() == 0){
      cout << "SHOPPING CART IS EMPTY\n";
   }
   else{
      for(int i = 0; i < size; i++){
         total = cartItems[i].GetQuantity() * cartItems[i].GetPrice();
         cout << cartItems[i].GetName() << " " << cartItems[i].GetQuantity() << " @ $" << cartItems[i].GetPrice() << " = $" << total << endl;
      }
   }
   cout << "\nTotal: $" << GetCostOfCart() << "\n\n";
}
void ShoppingCart::PrintDecriptions(){
   ItemToPurchase currCart;
   int size =cartItems.size();
   cout << "OUTPUT ITEMS' DESCRIPTIONS\n";
   cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() << "\n\n" ;
   cout << "Item Descriptions\n";
   for(int i = 0; i < size; i++){
      cout << cartItems[i].GetName() << ": " << cartItems[i].GetDescription() << endl;
   }
   cout << endl;
}