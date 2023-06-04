#ifndef LOAN_H
#define LOAN_H

#include <iostream>
#include <string>
using namespace std;

class Loan{
	public:
		Loan();
		Loan(int loanID, int bookID, int patronID, time_t dueDate, int recheck, char status);
		void setLoanID(int loanID);
		void setItemID(int bookID);
		void setPatronID(int patronID);
		void setDueDate(time_t dueDate);
		void setRecheck(int recheck);
		void setStatus(char status);
		int getLoanID();
		int getItemID();
		int getPatronID();
		time_t getDueDate();
		int getRecheck();
		char getStatus();
	private:
		int LoanID;
		int BookID;
		int PatronID;
		time_t DueDate;
		int Recheck;
		char Status;
};

#endif
