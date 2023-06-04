#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

class Book{
	public:
		Book();
		Book(string author, string title, double iSBNnum, int bookID, int cost, char status);
		void setAuthor(string author);
		void setTitle(string title);
		void setISBNnum(double iSBNnum);
		void setBookID(int bookID);
		void setCost(int cost);
		void setStatus(char status);
		string getAuthor();
		string getTitle();
		double getISBNnum();
		int getBookID();
		int getCost();
		char getStatus();
	private:
		string Author;
		string Title;
		double ISBNnum;
		int BookID;
		int Cost;
		char Status;
};

#endif
