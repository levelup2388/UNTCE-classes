#include "loan.h"

Loan::Loan(){
	LoanID = 0 ;
	BookID = 0;
	PatronID = 0;
	DueDate = 0;
	Recheck = 0;
	Status = 'x';
}
Loan::Loan(int loanID, int bookID, int patronID, time_t dueDate, int recheck, char status){
	LoanID = loanID;
	BookID = bookID;
	PatronID = patronID;
	DueDate = dueDate;
	Recheck = recheck;
	Status = status;
}
void Loan::setLoanID(int loanID){
	LoanID = loanID;
}
void Loan::setItemID(int bookID){
	BookID = bookID;
}
void Loan::setPatronID(int patronID){
	PatronID = patronID;
}
void Loan::setDueDate(time_t dueDate){
	DueDate = dueDate;
}
void Loan::setRecheck(int recheck){
	Recheck = recheck;
}
void Loan::setStatus(char status){
	Status = status;
}
int Loan::getLoanID(){
	return LoanID;
}
int Loan::getItemID(){
	return BookID;
}
int Loan::getPatronID(){
	return PatronID;
}
time_t Loan::getDueDate(){
	return DueDate;
}
int Loan::getRecheck(){
	return Recheck;
}
char Loan::getStatus(){
	return Status;
}