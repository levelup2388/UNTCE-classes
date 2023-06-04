

#include "loans.h"
#include <iostream>
#include <ctime>
using namespace std;

Loans::Loans(){
	Count = 0;
}
Loans::Loans(int count){
	Count = count;
}
bool Loans::CheckOverdue(int patronID, time_t currentDate){
	for(int i =0; i<Count;i++){
		if(lList.at(i).getPatronID() == patronID){
			if(lList.at(i).getDueDate() < currentDate){
				lList.at(i).setStatus('o');
				return true;
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}
}
void Loans::AddLoan(vector<Book> bList, vector<Patron> pList, time_t currentDate){
	Loan newLoan;
	int patronID;
	int bookID;
	time_t dueDate = currentDate + (10 * 24 *60 *60);
	int num;
	string time_str = ctime(&dueDate);
	
	cout << "Enter patron ID: ";
	cin >> patronID;
	cout << "Enter book ID: ";
	cin >> bookID;
	
	int patronLoc ;
	for(int i=0;i<Count;i++){
		if(pList.at(i).getIDnum() == num){
			patronLoc = i;
		}
	}
	
	if((CheckOverdue(patronID, currentDate) == false) && (pList.at(patronLoc).getNumBooksOut()<7)){
		for(unsigned i = 0;i<bList.size();i++){
			if(bList.at(i).getBookID() == bookID){
				bList.at(i).setStatus('o');
			}
		}
		num = pList.at(patronLoc).getNumBooksOut();
		pList.at(patronLoc).setNumBooksOut(num+1);
		newLoan.setLoanID(Count);
		newLoan.setBookID(bookID);
		newLoan.setPatronID(patronID);
		newLoan.setDueDate(dueDate);
		newLoan.setStatus('n');
		Count++;
		cout << "Book is due at: ";
		cout << time_str << endl;
		lList.push_back(newLoan);
	}
	else{
		cout << "unable to rent book";
		if(CheckOverdue(patronID, currentDate) == false){
			cout << " because patron has overdue books\n";
		}
		else{
			cout << " because you have more than 6 books checked out\n";
		}
	}	
}
void Loans::EditLoan( time_t currentDate){
	int patronID;
	int bookID;
	char c;
	
	cout << "Enter Patrons ID of loan: ";
	cin >> patronID;
	cout << "Enter books ID of loan: ";
	cin >> bookID;
	
	for(int i=0;i<Count;i++){
		if((lList.at(i).getBookID() == bookID)&&(lList.at(i).getPatronID() == patronID)){
			cout << "Would you like to re-check the book(Y/N): ";
			cin >> c;
			if(c == 'y'){
				time_t dueDate = currentDate + (10 * 24 *60 *60);
				lList.at(i).setDueDate(dueDate);
				string time_str = ctime(&dueDate);
				cout << "New due date is " << time_str << endl;
			}	
		}
	}		
}
void Loans::DeleteLoan(vector<Book> bList, vector<Patron> pList, time_t currentDate){
	int patronID;
	int bookID;
	int num;
	int fine=0;
	int patronBal;
	
	cout << "Enter Patrons ID of loan: ";
	cin >> patronID;
	cout << "Enter books ID of loan: ";
	cin >> bookID;
	
	int bookLoc ;
	int patronLoc ;
	for(int i=0;i<Count;i++){
		if(bList.at(i).getBookID() == bookID){
			bookLoc = i;
		}
	}
	for(int i=0;i<Count;i++){
		if(pList.at(i).getIDnum() == num){
			patronLoc = i;
		}
	}
	
	for(int i=0;i<Count;i++){
		if((lList.at(i).getBookID() == bookID)&&(lList.at(i).getPatronID() == patronID)){
			num = pList.at(patronLoc).getNumBooksOut();
			pList.at(patronLoc).setNumBooksOut(num-1);
			bList.at(bookLoc).setStatus('I');
			if(lList.at(i).getDueDate() < currentDate){
				fine =((lList.at(i).getDueDate(), currentDate)/ ( 24 *60 *60))*.25;
				patronBal = pList.at(patronLoc).getFineBal();
				pList.at(patronLoc).setFineBal(fine + patronBal);
			}
			lList.erase(lList.begin()+i);
		}
	}
			
}
void Loans::FindAllOver(vector<Book> bList, vector<Patron> pList, time_t currentDate){
	int patronID;
	int bookID;
	int num;
	int fine=0;
	int patronBal;
	
	int bookLoc ;
	int patronLoc ;
	for(int i=0;i<Count;i++){
		if(bList.at(i).getBookID() == bookID){
			bookLoc = i;
		}
	}
	for(int i=0;i<Count;i++){
		if(pList.at(i).getIDnum() == num){
			patronLoc = i;
		}
	}
	for(int i=0;i<Count;i++){
		if(lList.at(i).getDueDate() < currentDate){
			patronID = lList.at(i).getPatronID();
			bookID = lList.at(i).getBookID();
			if(lList.at(i).getStatus() == 'n'){
				fine = ((lList.at(i).getDueDate(), currentDate)/ ( 24 *60 *60))*.25;
				patronBal = pList.at(patronLoc).getFineBal();
				pList.at(patronLoc).setFineBal(fine + patronBal);
				lList.at(i).setStatus('o');
			}
			cout << "Loan: " << lList.at(i).getLoanID() << endl;
			cout << "Patron ID: " << lList.at(i).getPatronID() << endl;
			cout << "Patron name: " << pList.at(patronLoc).getName() << endl;
			cout << "Book ID: " << lList.at(i).getBookID() << endl;
			cout << "Book title: " << bList.at(bookLoc).getTitle() << endl;
		}
	}
}
void Loans::PrintListBookPatron(int patronID, int bookID, vector<Book> bList){
	
	
	int bookLoc ;
	for(int i=0;i<Count;i++){
		if(bList.at(i).getBookID() == bookID){
			bookLoc = i;
		}
	}
	
	for(int i=0;i<Count;i++){
		if((lList.at(i).getBookID() == bookID)&&(lList.at(i).getPatronID() == patronID)){
			cout << "Book ID:" << lList.at(i).getBookID() << endl;
			cout << "Book title: " << bList.at(bookLoc).getTitle() << endl;
		}
		cout << endl;
	}
}
void Loans::UpdateStatus(vector<Patron> pList, time_t currentDate){
	int patronID;
	int bookID;
	int num;
	int fine=0;
	int patronBal;
	
	int patronLoc ;
	for(int i=0;i<Count;i++){
		if(pList.at(i).getIDnum() == num){
			patronLoc = i;
		}
	}
	for(int i=0;i<Count;i++){
		if(lList.at(i).getDueDate() < currentDate){
			patronID = lList.at(i).getPatronID();
			bookID = lList.at(i).getBookID();
			if(lList.at(i).getStatus() == 'n'){
				fine = ((lList.at(i).getDueDate(), currentDate)/ ( 24 *60 *60))*.25;
				patronBal = pList.at(patronLoc).getFineBal();
				pList.at(patronLoc).setFineBal(fine + patronBal);
				lList.at(i).setStatus('o');
			}
		}
	}
}
void Loans::ReportLost(vector<Book> bList){
	int bookID;
	int patronID;
	int cost;
	int patBal;
	
	cout << "Enter Book ID of book lost:" ;
	cin >> bookID;
	cout << "Enter PatronID:" ;
	cin >> patronID;
	
	int bookLoc ;
	for(int i=0;i<Count;i++){
		if(bList.at(i).getBookID() == bookID){
			bookLoc = i;
		}
	}
	cost = bList.at(bookLoc).getCost();
	bList.at(bookLoc).setStatus('l');
	
	
}