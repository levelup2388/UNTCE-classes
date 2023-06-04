#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
#include <string>
#include "item.h"
#include "audio.h"
#include "dvd.h"
#include "book.h"
#include <vector>
using namespace std;

class Items{
	public:
		Items();
		Items(int count);
		void AddItem();
		void EditItem(int itemID);
		void DeleteItem(int itemID);
		int FindItem(int itemID);
		void PrintList();
		void PrintIdetailts();
	private:
		int Count;
		vector<Item> bList;		
};

#endif
