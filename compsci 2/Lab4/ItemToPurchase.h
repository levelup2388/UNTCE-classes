#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase{
   public:
      ItemToPurchase();
      ItemToPurchase(string name, string description, int price, int quantity);
      void SetName(string name);
      void SetPrice(int price);
      void SetQuantity(int quantity);
      void SetDescription(string description);
      int GetPrice();
      int GetQuantity();
      string GetName();
      string GetDescription();
      void PrintItemCost(string name, int price, int quantity);
      void PrintItemDescription(string name, string description);
   private:
      string itemName;
      int itemPrice;
      int itemQuantity ;
      string itemDescription;
};

#endif