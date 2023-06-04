#include "books.h"
using namespace std;


Books::Books(){
	Count = 0;
}
Books::Books(int count){
	Count = count;
}
void Books::AddBook(){
	Book newBook;
	string author;
	string title;
	double iSBNnum;
	int bookID = Count;
	int cost;
	char status;
	
	cout << "Please enter books author: ";
	cin.ignore();
	getline(cin, author);
	cout << "Please enter books title: ";
	getline(cin, title);
	cout << "Please enter books ISBN number: ";
	cin >> iSBNnum;
	cout << "Please enter cost of book($): ";
	cin >> cost;
	cout << "Please enter books status (I = In, O = Out, R = Repair, L = Lost): ";
	cin >> status;
	cout << endl;
	
	newBook.setAuthor(author);
	newBook.setTitle(title);
	newBook.setISBNnum(iSBNnum);
	newBook.setBookID(bookID);
	newBook.setCost(cost);
	newBook.setStatus(status);
	Count++;

	bList.push_back(newBook);
}
void Books::EditBook(int bookID){
	char c;
	
	cout << "What is new status";
	cin >> c;
	cout << endl;
	for(int i =0; i<Count;i++){
		if(bList.at(i).getBookID() == bookID){
			bList.at(i).setStatus(c);
		}
	}
}
void Books::DeleteBook(int bookID){
	int ext = 0;
	for(int i =0; i<Count;i++){
		if(bList.at(i).getBookID() == bookID){
			bList.erase(bList.begin()+i);
			cout << endl;
			ext++;
		}
	}
	if(ext==0){
		cout << "Book not found, Nothing removed.\n";
	}
	Count--;
}
int Books::FindBook(int bookID){
	
	for(int i=0;i<Count;i++){
		if(bList.at(i).getBookID() == bookID){
			return i;
		}
	}
}
void Books::PrintList(){
	for(int i = 0;i<Count; i++){
		cout << "Book ID: " << bList.at(i).getBookID();
		cout << "\nAuthor: " << bList.at(i).getAuthor();
		cout << "\nTitle: " << bList.at(i).getTitle();
		cout << "\nISBN number: " << bList.at(i).getISBNnum();
		cout << "\nCost: $" << bList.at(i).getCost() ;
		cout << "\nStatus: ";
		if(bList.at(i).getStatus() == 'I'){
			cout << "In\n";
		}
		else if(bList.at(i).getStatus() == 'O'){
			cout << "Out\n";
		}
		else if(bList.at(i).getStatus() == 'R'){
			cout << "Repair\n";
		}
		else if(bList.at(i).getStatus() == 'L'){
			cout << "Lost\n";
		}
		cout << endl;
	}
}
void Books::PrintBdetailts(){
	int bookID;
	
	cout << "Enter ID number for Book";
	cin >> bookID;
	for(int i = 0;i<Count; i++){
		if(bList.at(i).getBookID() == bookID){
			cout << "Book ID: " << bList.at(i).getBookID();
		cout << "\nAuthor: " << bList.at(i).getAuthor();
		cout << "\nTitle: " << bList.at(i).getTitle();
		cout << "\nISBN number: " << bList.at(i).getISBNnum();
		cout << "\nCost: $" << bList.at(i).getCost() ;
		cout << "\nStatus: ";
		if(bList.at(i).getStatus() == 'I'){
			cout << "In\n";
		}
		else if(bList.at(i).getStatus() == 'O'){
			cout << "Out\n";
		}
		else if(bList.at(i).getStatus() == 'R'){
			cout << "Repair\n";
		}
		else if(bList.at(i).getStatus() == 'L'){
			cout << "Lost\n";
		}
		cout << endl;
		}
	}
}







