#ifndef BOOK_H
#define BOOK_H

#include "item.h"
#include <iostream>
#include <string>
using namespace std;

class Book : public Item{
	public:
		Book();
		Book(int itemID, int cost, char status, string author, string title, double iSBNnum, string catagory);
		void setAuthor(string author);
		void setTitle(string title);
		void setISBNnum(double iSBNnum);
		void setCatagory(string catagory);
		string getAuthor();
		string getTitle();
		double getISBNnum();
		string getCatagory();
		void printItem() ;
	private:
		string Author;
		string Title;
		double ISBNnum;
		string Catagory;
};

#endif
