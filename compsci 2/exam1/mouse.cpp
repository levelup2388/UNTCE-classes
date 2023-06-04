#include <iostream>
using namespace std;

#include "mouse.h"

Mouse::Mouse(){
	breed = "none";
	weight = 0;
	name = "none";
	gender = 'x';
	favFood = "none";
	description = "none";
	comments = "none";
}
Mouse::Mouse(string type, float mass, string dName, char c, string food, string descript, string com){
	breed = type;
	weight = mass;
	name = dName;
	gender = c;
	favFood = food;
	description = descript;
	comments = com;
}
void Mouse::SetBreed(string type){
	breed =  type;
}
void Mouse::SetWeight(float mass){
	weight = mass;
}
void Mouse::SetName(string dName){
	name = dName;
}
void Mouse::SetGender(char c){
	gender = c;
}
void Mouse::SetFavFood(string food){
	favFood = food;
}
void Mouse::SetDescription(string descript){
	description = descript;
}
void Mouse::SetComments(string com){
	comments = com;
}
string Mouse::GetBreed(){
	return breed;
}
float Mouse::GetWeight(){
	return weight;
}
string Mouse::GetName(){
	return name;
}
char Mouse::GetGender(){
	return gender;
}
string Mouse::GetFavFood(){
	return favFood;
}
string Mouse::GetDescription(){
	return description;
}
string Mouse::GetComments(){
	return comments;
}
void Mouse::PrintInfo(){
	cout << "\nBreed:" << GetBreed();
	cout << "\nWeight:" << GetWeight() << "lbs";
	cout << "\nName:" << GetName();
	cout << "\nGender:" ;
	if (GetGender()== 'm'){
		cout << "male";
	}
	else if (GetGender()== 'f'){
		cout << "female";
	}
	else {
		cout << "invalid input";
	}
	cout << "\nFavFood:" << GetFavFood();
	cout << "\nDescription:" << GetDescription();
	cout << "\nComments:" << GetComments() << endl;
}