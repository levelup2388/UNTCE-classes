#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using namespace std;

class Item {
	public:
		Item();
		Item(int itemID, int cost, char status);
		void setItemID(int itemID);
		void setCost(int cost);
		void setStatus(char status);
		int getItemID();
		int getCost();
		char getStatus();
		virtual void printItem();
	protected:
		int ItemID;
		int Cost;
		char Status;
};

#endif