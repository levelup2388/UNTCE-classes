#include "patrons.h"
using namespace std;


Patrons::Patrons(){
	Count = 0;
}
Patrons::Patrons(int count){
	Count = count;
}
void Patrons::AddPatron(){
	Patron newPatron;
	string name;
	int IDnum = Count;
	int fineBal;
	int numBooks;
	
	cout << "Please enter patrons name: ";
	cin.ignore();
	getline(cin, name);
	
	newPatron.setName(name);
	newPatron.setIDnum(IDnum);
	newPatron.setFineBal(0);
	newPatron.setNumBooksOut(0);
	Count++;

	pList.push_back(newPatron);
}
void Patrons::EditPatron(int num){
	string newName;
	
	cout << "Enter patrons new name";
	cin.ignore();
	getline(cin, newName);
	cout << endl;
	for(int i =0; i<Count;i++){
		if(pList.at(i).getIDnum() == num){
			pList.at(i).setName(newName);
		}
	}
}
void Patrons::DeletePatron(int num){
	int ext = 0;
	for(int i =0; i<Count;i++){
		if(pList.at(i).getIDnum() == num){
			pList.erase(pList.begin()+i);
			cout << endl;
			ext++;
		}
	}
	if(ext==0){
		cout << "Patron not found, Nothing removed.\n";
	}
	Count--;
}
int Patrons::FindPatron(int num){
	
	for(int i=0;i<Count;i++){
		if(pList.at(i).getIDnum() == num){
			return i;
		}
	}
}
void Patrons::PayFines(int num){
	char c;
	for(int i=0;i<Count;i++){
		if(pList.at(i).getIDnum() == num){
			cout << "Patrons fine balance is: $" << pList.at(i).getFineBal() << endl;
			cout << "Would you like to pay it off (Y/N): ";
			cin >> c;
			if(c == 'y'){
				cout << "Fine Balance paid\n";
				pList.at(i).setFineBal(0);
			}
			else{
				cout << "Patrons fine balance remains: $" << pList.at(i).getFineBal() << endl;
			}
		}
	}
			
}
void Patrons::PrintList(){
	for(int i = 0;i<Count; i++){
		cout << "Patron: " << pList.at(i).getIDnum();
		cout << "\nName: " << pList.at(i).getName();
		cout << "\nFine Balance: " << pList.at(i).getFineBal();
		cout << "\nNumber of Books Out: " << pList.at(i).getNumBooksOut();
	}
}
void Patrons::PrintPdetailts(){
	int num;
	
	cout << "Enter ID number for Patron";
	cin >> num;
	for(int i = 0;i<Count; i++){
		cout << "Patron: " << pList.at(i).getIDnum();
		cout << "\nName: " << pList.at(i).getName();
		cout << "\nFine Balance: " << pList.at(i).getFineBal();
		cout << "\nNumber of Books Out: " << pList.at(i).getNumBooksOut();
		cout << endl;
	}
}
