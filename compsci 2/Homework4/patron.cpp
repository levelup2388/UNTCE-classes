#include "patron.h"

Patron::Patron(){
	Name = "none";
	IDnum = 0;
	FineBal = 0;
	NumBooksOut = 0;
}
Patron::Patron(string name, int num, int fineBal, int numBooksOut){
	Name = name;
	IDnum = num;
	FineBal = fineBal;
	NumBooksOut = numBooksOut;
}
void Patron::setName(string name){
	Name = name;
}
void Patron::setIDnum(int num){
	IDnum = num;
}
void Patron::setFineBal(int fineBal){
	FineBal = fineBal;
}
void Patron::setNumBooksOut(int numBooksOut){
	NumBooksOut = numBooksOut;
}
string Patron::getName(){
	return Name;
}
int Patron::getIDnum(){
	return IDnum;
}
int Patron::getFineBal(){
	return FineBal;
}
int Patron::getNumBooksOut(){
	return NumBooksOut;
}
