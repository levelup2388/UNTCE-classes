#include "horse.h"
#include <vector>

using namespace std;

int main(){

Animal* animalPtr = nullptr;
Horse* horsePtr = nullptr;
vector<Animal*> animalList;

horsePtr = new Horse();
animalPtr = new Animal();


unsigned int i;
string breed;
float weight;
string name;
char gender;
string spayed;
string regID;
string color;
string comments;

for(i=0; i<3; i++){
	cout << "Enter info for horse #" << i+1 << endl;
	cout << "Breed: ";
	cin >> breed;
	cout << "Weight(lbs): ";
	cin >> weight;
	cout << "Name: ";
	cin >> name;
	cout << "Gender(m or f): ";
	cin >> gender;
	cout << "Spayed(yes or no): ";
	cin >> spayed; 
	cout << "Registration ID: ";
	cin >> regID;
	cout << "Color Description: ";
	cin.ignore();
	getline(cin, color);
	cout << "Comments: ";
	getline(cin, comments);
	
	animalPtr->setWeight(weight);
	animalPtr->setName(name);
	animalPtr->setGender(gender);
	animalPtr->setColor(color);
	horsePtr->setBreed(breed);
	horsePtr->setSpayed(spayed);
	horsePtr->setRegID(regID);
	horsePtr->setComments(comments);
	
	
	animalList.push_back(animalPtr);
	animalList.push_back(horsePtr);
	cout << endl;
}
int tempi;
int run =0;
for(i=0; i<3;i++){
	run = 0 ;
	cout << "Info for Horse #" << i+1 << endl;
	while(run <2){
		animalList.at(i+run)->PrintInfo();
		run ++;
	}
		cout << endl;
}

delete animalPtr;
delete horsePtr;




	return 0;
}