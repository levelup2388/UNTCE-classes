#include "animal.h"


Animal::Animal(){
	Weight = 0;
	Name = "none";
	Gender = 'x';
	Color = "none";
}
Animal::Animal(float weight, string name, char gender, string color){
	Weight = weight;
	Name = name;
	Gender = gender;
	Color = color;
}
void Animal::setWeight(float weight){
	Weight = weight;
}
void Animal::setName(string name){
	Name = name;
}
void Animal::setGender(char gender){
	Gender = gender;
}
void Animal::setColor(string color){
	Color = color;
}
float Animal::getWeight(){
	return Weight;
}
string Animal::getName(){
	return Name;
}
char Animal::getGender(){
	return Gender;
}
string Animal::getColor(){
	return Color;
}
void Animal::PrintInfo()const{
	cout << "Weight: " << Weight << "lbs" << endl;
	cout << "Name: " << Name << endl;
	cout << "Gender: ";
		if(Gender == 'm'){
			cout << "male";
		}
		else if(Gender == 'f'){
			cout << "female";
		}
		else{ cout << "NA";}
	cout << endl;
	cout << "Color Description: " << Color << endl;
}