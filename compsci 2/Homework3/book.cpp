#include "book.h"

Book::Book(){
	Author = "none";
	Title = "none";
	ISBNnum = 0;
	BookID = 0;
	Cost = 0;
	Status = 'x';
}
Book::Book(string author, string title, double iSBNnum, int bookID, int cost, char status){
	Author = author;
	Title = title;
	ISBNnum = iSBNnum;
	BookID = bookID;
	Cost = cost;
	Status = status;
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
void Book::setBookID(int bookID){
	BookID = bookID;
}
void Book::setCost(int cost){
	Cost = cost;
}
void Book::setStatus(char status){
	Status = status;
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
int Book::getBookID(){
	return BookID;
}
int Book::getCost(){
	return Cost;
}
char Book::getStatus(){
	return Status;
}