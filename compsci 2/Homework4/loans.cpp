

#include "loans.h"
#include <iostream>
#include <ctime>
#pragma warning(disable : 4996)
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
			if(lList.at(i).getDueDate() > currentDate){
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
void Loans::AddLoan(vector<Item> bList, vector<Patron> pList, time_t currentDate){
	Loan newLoan;
	int patronID;
	int itemID;
	time_t dueDate = currentDate + (10 * 24 *60 *60);
	int num;
	string time_str = ctime(&dueDate);
	
	cout << "Enter patron ID: ";
	cin >> patronID;
	cout << "Enter item ID: ";
	cin >> itemID;
	
	int patronLoc ;
	for(int i=0;i<Count;i++){
		if(pList.at(i).getIDnum() == patronID){
			patronLoc = i;
		}
	}
	
	if((CheckOverdue(patronID, currentDate) == false) && (pList.at(patronLoc).getNumBooksOut()<7)){
		for(unsigned i = 0;i<bList.size();i++){
			if(bList.at(i).getItemID() == itemID){
				bList.at(i).setStatus('o');
			}
		}
		num = pList.at(patronLoc).getNumBooksOut();
		pList.at(patronLoc).setNumBooksOut(num+1);
		newLoan.setLoanID(Count);
		newLoan.setItemID(itemID);
		newLoan.setPatronID(patronID);
		newLoan.setDueDate(dueDate);
		newLoan.setStatus('n');
		Count++;
		cout << "item is due at: ";
		cout << time_str << endl;
		lList.push_back(newLoan);
	}
	else{
		cout << "unable to rent item";
		if(CheckOverdue(patronID, currentDate) == true){
			cout << " because patron has overdue items\n";
		}
		else{
			cout << " because you have more than 6 books checked out\n";
		}
	}	
}
void Loans::EditLoan( time_t currentDate){
	int patronID;
	int itemID;
	char c;
	
	cout << "Enter Patrons ID of loan: ";
	cin >> patronID;
	cout << "Enter items ID of loan: ";
	cin >> itemID;
	
	for(int i=0;i<Count;i++){
		if((lList.at(i).getItemID() == itemID)&&(lList.at(i).getPatronID() == patronID)){
			cout << "Would you like to re-check the item(Y/N): ";
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
void Loans::DeleteLoan(vector<Item> bList, vector<Patron> pList, time_t currentDate){
	int patronID;
	int itemID;
	int num;
	int fine=0;
	int patronBal;
	
	cout << "Enter Patrons ID of loan: ";
	cin >> patronID;
	cout << "Enter items ID of loan: ";
	cin >> itemID;
	
	int bookLoc ;
	int patronLoc ;
	for(int i=0;i<Count;i++){
		if(bList.at(i).getItemID() == itemID){
			bookLoc = i;
		}
	}
	for(int i=0;i<Count;i++){
		if(pList.at(i).getIDnum() == patronID){
			patronLoc = i;
		}
	}
	
	for(int i=0;i<Count;i++){
		if((lList.at(i).getItemID() == itemID)&&(lList.at(i).getPatronID() == patronID)){
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
void Loans::FindAllOver(vector<Item> bList, vector<Patron> pList, time_t currentDate){
	int patronID;
	int bookID;
	int num;
	int fine=0;
	int patronBal;
	
	int bookLoc ;
	int patronLoc ;
	cout << "Enter Item ID: ";
	cin >> bookID;
	cout << "Enter patron ID: ";
	cin >> patronID;
	for(int i=0;i<Count;i++){
		if(bList.at(i).getItemID() == bookID){
			bookLoc = i;
		}
	}
	for(int i=0;i<Count;i++){
		if(pList.at(i).getIDnum() == patronID){
			patronLoc = i;
		}
	}
	for(int i=0;i<Count;i++){
		if(lList.at(i).getDueDate() < currentDate){
			patronID = lList.at(i).getPatronID();
			bookID = lList.at(i).getItemID();
			if(lList.at(i).getStatus() == 'n'){
				fine = ((lList.at(i).getDueDate(), currentDate)/ ( 24 *60 *60))*.25;
				patronBal = pList.at(patronLoc).getFineBal();
				pList.at(patronLoc).setFineBal(fine + patronBal);
				lList.at(i).setStatus('o');
			}
			cout << "Loan: " << lList.at(i).getLoanID() << endl;
			cout << "Patron ID: " << lList.at(i).getPatronID() << endl;
			cout << "Patron name: " << pList.at(patronLoc).getName() << endl;
			cout << "Item ID: " << lList.at(i).getItemID() << endl;
			//cout << "Item title: " << bList.at(bookLoc).getTitle() << endl;
		}
	}
}
void Loans::PrintListItemPatron(int patronID, int bookID, vector<Item> bList){
	
	
	int bookLoc ;
	for(int i=0;i<Count;i++){
		if(bList.at(i).getItemID() == bookID){
			bookLoc = i;
		}
	}
	
	for(int i=0;i<Count;i++){
		if((lList.at(i).getItemID() == bookID)&&(lList.at(i).getPatronID() == patronID)){
			cout << "Item ID:" << lList.at(i).getItemID() << endl;
			//cout << "Item title: " << bList.at(bookLoc).getTitle() << endl;
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
	cout << "Enter patron ID: ";
	cin >> patronID;
	for(int i=0;i<Count;i++){
		if(pList.at(i).getIDnum() == patronID){
			patronLoc = i;
		}
	}
	for(int i=0;i<Count;i++){
		if(lList.at(i).getDueDate() < currentDate){
			patronID = lList.at(i).getPatronID();
			bookID = lList.at(i).getItemID();
			if(lList.at(i).getStatus() == 'n'){
				fine = ((lList.at(i).getDueDate(), currentDate)/ ( 24 *60 *60))*.25;
				patronBal = pList.at(patronLoc).getFineBal();
				pList.at(patronLoc).setFineBal(fine + patronBal);
				lList.at(i).setStatus('o');
			}
		}
	}
}
void Loans::ReportLost(vector<Item> bList){
	int bookID;
	int patronID;
	int cost;
	int patBal;
	
	cout << "Enter Item ID of book lost:" ;
	cin >> bookID;
	cout << "Enter PatronID:" ;
	cin >> patronID;
	
	int bookLoc ;
	for(int i=0;i<Count;i++){
		if(bList.at(i).getItemID() == bookID){
			bookLoc = i;
		}
	}
	cost = bList.at(bookLoc).getCost();
	bList.at(bookLoc).setStatus('l');
	
	
}