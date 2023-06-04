#include "book.h"

Book::Book(){
	Author = "none";
	Title = "none";
	ISBNnum = 0;
	Catagory = "none";
}
Book::Book(int itemID, int cost, char status, string author, string title, double iSBNnum, string catagory) :Item(itemID, cost, status) {
	Author = author;
	Title = title;
	ISBNnum = iSBNnum;
	Catagory = catagory;
}
void Book::setAuthor(string author){
	Author = author;
}
void Book::setTitle(string title){
	Title = title;
}
void Book::setISBNnum(double iSBNnum){
	ISBNnum = iSBNnum;
}
void Book::setCatagory(string catagory){
	Catagory = catagory;
}
string Book::getAuthor(){
	return Author;
}
string Book::getTitle(){
	return Title;
}
double Book::getISBNnum(){
	return ISBNnum;
}
string Book::getCatagory(){
	return Catagory;
}
void Book::printItem() {

	//Item::printItem();
	cout << "Item ID: " << ItemID;
	cout << "\nCost: $" << Cost;
	cout << "\nStatus: ";
	if (Status == 'I') {
		cout << "In\n";
	}
	else if (Status == 'O') {
		cout << "Out\n";
	}
	else if (Status == 'R') {
		cout << "Repair\n";
	}
	else if (Status == 'L') {
		cout << "Lost\n";
	}
	cout << "\nAuthor: " << Author;
	cout << "\nTitle: " << Title;
	cout << "\nISBN number: " << ISBNnum;
	cout << "\ncategory: " << Catagory << endl;
}