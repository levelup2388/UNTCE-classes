#ifndef DVD_H
#define DVD_H

#include "item.h"
#include <iostream>
#include <string>
using namespace std;

class DVD : public Item{
	public:
		DVD();
		DVD(int itemID, int cost, char status, string title, string catagory, int runTime, string studio, string date);
		void setTitle(string title);
		void setCatagory(string catagory);
		void setRunTime(int runTime);
		void setStudio(string studio);
		void setDate(string date);
		string getTitle();
		string getCatagory();
		int getRunTime();
		string getStudio();
		string getDate();
		void printItem();
	private:
		string Title;
		string Catagory;
		int RunTime;
		string Studio;
		string Date;
};

#endif
