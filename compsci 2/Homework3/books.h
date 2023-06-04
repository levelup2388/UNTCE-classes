#ifndef BOOKS_H
#define BOOKS_H

#include <iostream>
#include <string>
#include "book.h"
#include <vector>
using namespace std;

class Books{
	public:
		Books();
		Books(int count);
		void AddBook();
		void EditBook(int bookID);
		void DeleteBook(int bookID);
		int FindBook(int bookID);
		void PrintList();
		void PrintBdetailts();
	private:
		int Count;
		vector<Book> bList;		
};

#endif
