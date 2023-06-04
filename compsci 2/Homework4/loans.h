#ifndef LOANS_H
#define LOANS_H

#include <iostream>
#include <string>
#include <vector>
#include "loan.h"
#include "patron.h"
#include "items.h"
#include "patrons.h"
using namespace std;

class Loans{
	public:
		Loans();
		Loans(int count);
		bool CheckOverdue(int patronID, time_t currentDate);
		void AddLoan(vector<Item> blist, vector<Patron> pList, time_t currentDate);
		void EditLoan(time_t currentDate);
		void DeleteLoan(vector<Item> bList, vector<Patron> pList, time_t currentDate);
		void FindAllOver(vector<Item> bList, vector<Patron> pList, time_t currentDate);
		void PrintListItemPatron(int patronID, int ItemID, vector<Item> bList);
		void UpdateStatus(vector<Patron> pList, time_t currentDate);
		void ReportLost(vector<Item> bList);
	private:
		int Count;
		vector<Loan> lList;		
};

#endif
