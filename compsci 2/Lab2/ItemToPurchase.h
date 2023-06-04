#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase{
   public:
      string GetName();
      void SetName(string name);
      void SetPrice(int price);
      int GetPrice();
      void SetQuantity(int quantity);
      int GetQuantity();
   private:
      string itemName = "none";
      int itemPrice = 0;
      int itemQuantity = 0;
};/* Type your code here */

#endif