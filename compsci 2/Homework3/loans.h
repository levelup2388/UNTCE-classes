#ifndef LOANS_H
#define LOANS_H

#include <iostream>
#include <string>
#include <vector>
#include "loan.h"
#include "book.h"
#include "patron.h"
#include "books.h"
#include "patrons.h"
using namespace std;

class Loans{
	public:
		Loans();
		Loans(int count);
		bool CheckOverdue(int patronID, time_t currentDate);
		void AddLoan(vector<Book> blist, vector<Patron> pList, time_t currentDate);
		void EditLoan(time_t currentDate);
		void DeleteLoan(vector<Book> bList, vector<Patron> pList, time_t currentDate);
		void FindAllOver(vector<Book> bList, vector<Patron> pList, time_t currentDate);
		void PrintListBookPatron(int patronID, int bookID, vector<Book> bList);
		void UpdateStatus(vector<Patron> pList, time_t currentDate);
		void ReportLost(vector<Book> bList);
	private:
		int Count;
		vector<Loan> lList;		
};

#endif
