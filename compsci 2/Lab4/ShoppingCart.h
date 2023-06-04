#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include "ItemToPurchase.h"
#include <vector>
using namespace std;

class ShoppingCart{
   private:
      string customerName;
      string currentDate;
      vector < ItemToPurchase > cartItems;
   public:
      ShoppingCart();
      ShoppingCart(string name, string Date);
      void SetCustomerName(string name);
      void SetDate(string Date);
      string GetCustomerName();
      string GetDate();
      void AddItem(ItemToPurchase currCart);
      void RemoveItem(string name);
      void ModifyItem(ItemToPurchase currCart);
      int GetNumItemsInCart();
      int GetCostOfCart();
      void PrintTotal();
      void PrintDecriptions();
};

#endif