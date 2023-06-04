
#include "dvd.h"


DVD::DVD(){
	Title = "none";
	Catagory = "none";
	RunTime = 0;
	Studio = "none";
	Date = "none";
}
DVD::DVD(int itemID, int cost, char status, string title, string catagory, int runTime, string studio, string date):Item(itemID, cost, status){
	Title = title;
	Catagory = catagory;
	RunTime = runTime;
	Studio = studio;
	Date = date;
}
void DVD::setTitle(string title){
	Title = title;
}
void DVD::setCatagory(string catagory){
	Catagory = catagory;
}
void DVD::setRunTime(int runTime){
	RunTime = runTime;
}
void DVD::setStudio(string studio){
	Studio = studio;
}
void DVD::setDate(string date){
	Date = date;
}
string DVD::getTitle(){
	return Title;
}
string DVD::getCatagory(){
	return Catagory;
}
int DVD::getRunTime(){
	return RunTime;
}
string DVD::getStudio(){
	return Studio;
}
string DVD::getDate(){
	return Date;
}
void DVD::printItem() {

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
	//Item::printItem();
	cout << "\nTitle: " << Title;
	cout << "\nCategory: " << Catagory;
	cout << "\nRunTime" << RunTime;
	cout << "\nStudio: " << Studio;
	cout << "\nDate: " << Date;
	cout << endl;
}