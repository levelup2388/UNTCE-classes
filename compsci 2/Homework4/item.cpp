#include "item.h"

Item::Item(){
	ItemID = 0;
	Cost = 0;
	Status = 'x';
	//Period = 0;
}
Item::Item(int itemID, int cost, char status){
	ItemID = itemID;
	Cost = cost;
	Status = status;
	//Period = period;
}
void Item::setItemID(int itemID){
	ItemID = itemID;
}
void Item::setCost(int cost){
	Cost = cost;
}
void Item::setStatus(char status){
	Status = status;
}
int Item::getItemID(){
	return ItemID;
}
int Item::getCost(){
	return Cost;
}
char Item::getStatus(){
	return Status;
}
void Item::printItem() {
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
	cout << endl;
}