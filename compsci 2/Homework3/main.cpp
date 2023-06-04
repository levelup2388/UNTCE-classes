#include "books.h"
#include "loans.h"
#include "patrons.h"
#include <vector>
#include <ctime>
using namespace std;


void printMenu();

int main(){
	
	
vector<Book> BList;
vector<Patron> PList;
Loans loan;
Books book;
Patrons patron;
//vectro<Loan> LList;


time_t CurrentDate;
CurrentDate = time(&CurrentDate);

int BookID;
int Num;
int PatronID;
char choice ;
int menu = 0;
bool quit = false;
  
   
while(quit == false){
	if(menu == 0){
		printMenu();
		cin >> choice;
	}
	else{
		printMenu();
		cin >> choice;
	}
	if(choice == 'a'){
		book.AddBook();
		menu = false;
	}
	else if(choice == 'b'){
		loan.AddLoan(BList, PList, CurrentDate);
		menu = false;
	}
	else if(choice == 'c'){
		patron.AddPatron();
		menu = false;
	}
	else if(choice == 'd'){
		book.EditBook(BookID);
		menu = false;
	}
	else if(choice == 'e'){
		loan.EditLoan(CurrentDate);
		menu = false;
	}
	else if(choice == 'f'){
		patron.EditPatron(Num);
		menu = false;
	}
	else if(choice == 'g'){
		book.DeleteBook(BookID);
		menu = false;
	}
	else if(choice == 'h'){
		loan.DeleteLoan(BList, PList, CurrentDate);
		menu = false;
	}
	else if(choice == 'i'){
		patron.DeletePatron(Num);
		menu = false;
	}
	else if(choice == 'j'){
		book.PrintList();
		menu = false;
	}
	else if(choice == 'k'){
		book.PrintBdetailts();
		menu = false;
	}
	else if(choice == 'l'){
		patron.PayFines(Num);
		menu = false;
	}
	else if(choice == 'm'){
		patron.PrintList();
		menu = false;
	}
	else if(choice == 'n'){
		patron.PrintPdetailts();
		menu = false;
	}
	else if(choice == 'o'){
		loan.FindAllOver(BList, PList, CurrentDate);
		menu = false;
	}
	else if(choice == 'p'){
		loan.PrintListBookPatron(PatronID, BookID, BList);
		menu = false;
	}
	else if(choice == 'r'){
		loan.UpdateStatus(PList, CurrentDate);
		menu = false;
	}
	else if(choice == 's'){
		loan.ReportLost(BList);
		menu = false;
	}
	else if(choice == 'q'){
		quit = true;
	}
	else{
		menu=1;
	}
}
	
	
	return 0;
}


void printMenu(){
   cout 
   << "MENU\n"
   << "a - Add Book\n"
   << "b - Add Loan\n"
   << "c - Add Patron\n"
   << "d - Edit Book\n"
   << "e - Edit Loan\n"
   << "f - Edit Patron\n"
   << "g - Delete Book\n"
   << "h - Delete Loan\n"
   << "i - Delete Patron\n"
   << "j - Print List of all Books\n"
   << "k - Print data for specific book\n"
   << "l - Pay Fines for Patron\n"
   << "m - Print List of all Patron\n"
   << "n - Print data for specific Patron\n"
   << "o - Print all overdue books\n"
   << "p - Print list of all books patron has checked out\n"
   << "r - Update loan status\n"
   << "s - Report book lost\n"
   << "q - Quit\n\n"
   << "Choose an option:\n";
}