#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase(){
   itemName = "none";
   itemPrice = 0;
   itemQuantity = 0;
   itemDescription = "none";
}
ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity){
   itemName = name;
   itemPrice = price;
   itemQuantity = quantity;
   itemDescription = description;
}
void ItemToPurchase::SetName(string name){
   itemName=name;
}
string ItemToPurchase::GetName(){
   return itemName;
}
void ItemToPurchase::SetPrice(int price){
   itemPrice=price;
}
int ItemToPurchase::GetPrice(){
   return itemPrice;
}
void ItemToPurchase::SetQuantity(int quantity){
   itemQuantity=quantity;
}
int ItemToPurchase::GetQuantity(){
   return itemQuantity;
}
void ItemToPurchase::SetDescription(string description){
   itemDescription = description;
}
string ItemToPurchase::GetDescription(){
   return itemDescription;
}
void ItemToPurchase::PrintItemCost(string name, int price, int quantity){
   int total = price * quantity;
   cout << name << " " << quantity << " @ $" << price << " = $" << total << endl;
}
void ItemToPurchase::PrintItemDescription(string name, string description){
   cout << name << ": " << description << endl;
}