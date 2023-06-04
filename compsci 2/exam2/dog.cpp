#include "dog.h"
#include <iostream>
using namespace std;

Dog::Dog(){
	breed = "none";
	weight = 0;
	name = "none";
	gender = 'x';
	spayed = "none";
	regID = "none";
	descript = "none";
	comment = "none";
}
Dog::Dog(string role, float mass, string nameType, char type, string neutered, string regestratID, string description, string comments){
	breed = role;
	weight = mass;
	name = nameType;
	gender = type;
	spayed = neutered;
	regID = regestratID;
	descript = description;
	comment = comments;
}
void Dog::setBreed(string role){
	breed = role;
}
void Dog::setWeight(float mass){
	weight = mass;
}
void Dog::setName(string nameType){
	name = nameType;
}
void Dog::setGender(char type){
	gender = type;
}
void Dog::setSpayed(string neutered){
	spayed = neutered;
}
void Dog::setRegID(string regestratID){
	regID = regestratID;
}
void Dog::setDescript(string description){
	descript = description;
}
void Dog::setComment(string comments){
	comment = comments;
}
string Dog::getBreed(){
	return breed;
}
float Dog::getWeight(){
	return weight;
}
string Dog::getName(){
	return name;
}
char Dog::getGender(){
	return gender;
}
string Dog::getSpayed(){
	return spayed;
}
string Dog::getRegID(){
	return regID;
}
string Dog::getDescript(){
	return descript;
}
string Dog::getComment(){
	return comment;
}
void Dog::printInfo(){
	cout 
	<< "\nBreed: " << getBreed()
	<< "\nWeight: " << getWeight() << "lbs"
	<< "\nName: " << getName()
	<< "\nGender: ";
	if (getGender()== 'm'){
		cout << "male";
	}
	else if (getGender()== 'f'){
		cout << "female";
	}
	else {
		cout << "invalid input";
	}
	cout << "\nSpayed: ";
	if ((getSpayed()== "yes")||(getSpayed()== "no")){
		cout << getSpayed();
	}
	else {
		cout << "invalid input";
	}
	cout << "\nRegistration ID: " << getRegID()
	<< "\nColor description: " << getDescript()
	<< "\nOther comments: " << getComment()
	<< endl;
}