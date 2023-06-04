// problem 12
//njb0130
//Nicholas Bright

#include "mouse.h"
using namespace std;

int main(){
	//object declare
	int size = 6;
	Mouse *subject;
	subject = new Mouse [size];
	
	//input delcare
	string type;
	float mass;
	string dName;
	char c;
	string food;
	string descript;
	string com;
	
	//input
	for(int i = 0;i<size ; i++){
		cout << endl;
		cout << "Please enter mouse " << i+1 << "'s Breed:" ;
		cin >> type;
		cout << "Please enter mouse " << i+1 << "'s Weight(lbs):" ;
		cin >> mass;
		cout << "Please enter mouse " << i+1<< "'s Name:" ;
		cin >> dName;
		cout << "Please enter mouse " << i+1 << "'s Gender(m for male, f for female):" ;
		cin >> c;
		cout << "Please enter mouse " << i+1 << "'s FavFood:" ;
		cin >> food;
		cout << "Please enter mouse " << i+1 << "'s Description:";
		cin.ignore();
		getline(cin, descript);
		cout << "Please enter mouse " << i+1 << "'s Comments:" ;
		getline(cin, com);
		cout << endl;
		//set input to object
		subject[i].SetBreed(type);
		subject[i].SetWeight(mass);
		subject[i].SetName(dName);
		subject[i].SetGender(c);
		subject[i].SetFavFood(food);
		subject[i].SetDescription(descript);
		subject[i].SetComments(com);
	}
	
	//output
	for(int i = 0;i<size ; i++){
		cout << "Mouse " << i+1 << endl;
		subject[i].PrintInfo();
		cout << endl;
	}

	delete []subject;//clear space
	return 0;
}