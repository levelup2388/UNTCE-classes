// problem 1
//njb0130
//Nicholas Bright

#include "dog.h"
#include <vector>
using namespace std;

int main(){
	//object declare
	int size = 5;
	vector<Dog> *subject;
	subject = new vector<Dog> (size);
	
	//input delcare
	string role;
	float mass;
	string nameType;
	char type;
	string neutered;
	string regestratID;
	string description;
	string comments;
	
	//input
	for(int i = 0;i<size ; i++){
		cout << endl;
		cout << "Please enter dog " << i+1 << "'s Breed: " ;
		cin >> role;
		cout << "Please enter dog " << i+1 << "'s Weight(lbs): " ;
		cin >> mass;
		cout << "Please enter dog " << i+1<< "'s Name: " ;
		cin >> nameType;
		cout << "Please enter dog " << i+1 << "'s Gender(m for male, f for female): " ;
		cin >> type;
		cout << "Please enter if dog " << i+1 << "'s is spayed or not(yes/no): " ;
		cin >> neutered;
		cout << "Please enter dog " << i+1 << "'s Registration ID: " ;
		cin >> regestratID;
		cout << "Please enter dog " << i+1 << "'s Color Description: ";
		cin.ignore();
		getline(cin, description);
		cout << "Please enter dog " << i+1 << "'s Comments: " ;
		getline(cin, comments);
		cout << endl;
		//set input to object
		subject->at(i).setBreed(role);
		subject->at(i).setWeight(mass);
		subject->at(i).setName(nameType);
		subject->at(i).setGender(type);
		subject->at(i).setSpayed(neutered);
		subject->at(i).setRegID(regestratID);
		subject->at(i).setDescript(description);
		subject->at(i).setComment(comments);
	}
	
	//output
	for(int i = 0;i<size ; i++){
		cout << "Dog " << i+1 << endl;
		subject->at(i).printInfo();
		cout << endl;
	}

	delete subject;//clear space
	
	
	
	return 0;
}
	