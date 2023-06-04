#include "items.h"
#include "loans.h"
#include "patrons.h"
#include <vector>
#include <ctime>
using namespace std;


void printMenu();

int main(){
	
	
vector<Item> BList;
vector<Patron> PList;
Loans loan;
Items book;
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
		book.AddItem();
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
		cout << "Enter item ID of item you would like to edit: ";
		cin >> BookID;
		book.EditItem(BookID);
		menu = false;
	}
	else if(choice == 'e'){
		loan.EditLoan(CurrentDate);
		menu = false;
	}
	else if(choice == 'f'){
		cout << "Enter patron ID of patron you would like to edit: ";
		cin >> Num;
		patron.EditPatron(Num);
		menu = false;
	}
	else if(choice == 'g'){
		cout << "Enter item ID of item you would like to delete: ";
		cin >> BookID;
		book.DeleteItem(BookID);
		menu = false;
	}
	else if(choice == 'h'){
		loan.DeleteLoan(BList, PList, CurrentDate);
		menu = false;
	}
	else if(choice == 'i'){
		cout << "Enter patron ID of patron you would like to delete: ";
		cin >> Num;
		patron.DeletePatron(Num);
		menu = false;
	}
	else if(choice == 'j'){
		book.PrintList();
		menu = false;
	}
	else if(choice == 'k'){
		book.PrintIdetailts();
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
		cout << "Enter patron ID: ";
		cin >> PatronID;
		cout << "Enter item ID: ";
		cin >> BookID;
		loan.PrintListItemPatron(PatronID, BookID, BList);
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
   << "a - Add Item\n"
   << "b - Add Loan\n"
   << "c - Add Patron\n"
   << "d - Edit Item\n"
   << "e - Edit Loan\n"
   << "f - Edit Patron\n"
   << "g - Delete Item\n"
   << "h - Delete Loan\n"
   << "i - Delete Patron\n"
   << "j - Print List of all Items\n"
   << "k - Print data for specific item\n"
   << "l - Pay Fines for Patron\n"
   << "m - Print List of all Patron\n"
   << "n - Print data for specific Patron\n"
   << "o - Print all overdue items\n"
   << "p - Print list of all items patron has checked out\n"
   << "r - Update loan status\n"
   << "s - Report item lost\n"
   << "q - Quit\n\n"
   << "Choose an option:\n";
}