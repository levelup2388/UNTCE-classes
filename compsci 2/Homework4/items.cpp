#include "items.h"
using namespace std;


Items::Items(){
	Count = 0;
}
Items::Items(int count){
	Count = count;
}
void Items::AddItem(){
	string choice;
	int itemID = Count;

	cout << "Enter type of item(book, CD, DVD): ";
	cin >> choice;
	if (choice == "book") {
		
		string author;
		string title;
		double iSBNnum;
		string type;
		int cost;
		char status;

		cout << "Enter items author: ";
		cin.ignore();
		getline(cin, author);
		cout << "Enter items title: ";
		getline(cin, title);
		cout << "Enter items ISBN number: ";
		cin >> iSBNnum;
		cout << "Enter cost of book($): ";
		cin >> cost;
		cout << "Enter category(Biography, Fiction, SciFi, History, etc.): ";
		cin >> type;
		cout << "Enter items status (I = In, O = Out, R = Repair, L = Lost): ";
		cin >> status;
		cout << endl;

		Item *newBook = new Book(itemID, cost, status, author, title, iSBNnum, type);

		Count++;
		bList.push_back(*newBook);
	}
	else if (choice == "CD") {
		char status;
		int cost;
		string artist;
		string title;
		int num;
		string date;
		string type;

		cout << "Enter title of CD: ";
		cin.ignore();
		getline(cin, title);
		cout << "Enter the CD's artist: ";
		getline(cin, artist);
		cout << "Enter number of tracks in CD: ";
		cin >> num;
		cout << "Enter CD's release date: ";
		cin.ignore();
		getline(cin, date);
		cout << "Enter Genere(Pop, Classic Rock, Classical, Christian, Jazz, New age, etc): ";
		getline(cin, type);
		cout << "Enter cost of CD: ";
		cin >> cost;
		cout << "Enter items status (I = In, O = Out, R = Repair, L = Lost): ";
		cin >> status;
		cout << endl;
		
		Item* newCD = new Audio(itemID, cost, status, artist, title, num, date, type);

		Count++;
		bList.push_back(*newCD);
	}
	else if (choice == "DVD") {
		char status;
		int cost;
		string title;
		string type;
		int time;
		string studio;
		string date;

		cout << "Enter DVD title: ";
		cin.ignore();
		getline(cin, title);
		cout << "Enter Category of DVD: ";
		getline(cin, type);
		cout << "Enter run time of DVD in minutes: ";
		cin >> time;
		cout << "Enter Studio that made DVD: ";
		cin.ignore();
		getline(cin, studio);
		cout << "Enter release date of DVD: ";
		getline(cin, date);
		cout << "Enter cost of DVD: ";
		cin >> cost;

		cout << "Enter items status (I = In, O = Out, R = Repair, L = Lost): ";
		cin >> status;
		cout << endl;


		Item* newDVD = new DVD(itemID, cost, status, title, type, time, studio, date);


		Count++;
		bList.push_back(*newDVD);
	}
	else {
		cout << "Invaild input: ";
		return;
	}
}
void Items::EditItem(int itemID){
	char c;
	
	cout << "What is new status";
	cin >> c;
	cout << endl;
	for(int i =0; i<Count;i++){
		if(bList.at(i).getItemID() == itemID){
			bList.at(i).setStatus(c);
		}
	}
}
void Items::DeleteItem(int itemID){
	int ext = 0;
	for(int i =0; i<Count;i++){
		if(bList.at(i).getItemID() == itemID){
			bList.erase(bList.begin()+i);
			cout << endl;
			ext++;
		}
	}
	if(ext==0){
		cout << "Item not found, Nothing removed.\n";
	}
	Count--;
}
int Items::FindItem(int itemID){
	
	for(int i=0;i<Count;i++){
		if(bList.at(i).getItemID() == itemID){
			return i;
		}
	}
}
void Items::PrintList(){
	for(int i = 0;i<Count; i++){
		bList.at(i).printItem();
	}
}
void Items::PrintIdetailts(){
	int itemID;
	
	cout << "Enter ID number for Item";
	cin >> itemID;
	for(int i = 0;i<Count; i++){
		if(bList.at(i).getItemID() == itemID){
			bList.at(i).printItem();
		}
	}
}







