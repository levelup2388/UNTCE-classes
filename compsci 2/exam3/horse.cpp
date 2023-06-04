#include "horse.h"

Horse::Horse(){
	Breed = "none" ;
	Spayed = "none" ;
	RegID = "none";
	Comments = "none";
}
Horse::Horse(string breed, string spayed, string regID, string comments){
	Breed = breed;
	Spayed = spayed;
	RegID = regID;
	Comments = comments;
}
void Horse::setBreed(string breed){
	Breed = breed;
}
void Horse::setSpayed(string spayed){
	Spayed = spayed;
}
void Horse::setRegID(string regID){
	RegID = regID;
}
void Horse::setComments(string comments){
	Comments = comments;
}
string Horse::getBreed(){
	return Breed;
}
string Horse::getSpayed(){
	return Spayed;
}
string Horse::getRegID(){
	return RegID;
}
string Horse::getComments(){
	return Comments;
}
void Horse::PrintInfo() const{
	cout << "Breed: " << Breed << endl;
	//cout << "Weight: " << Weight << "lbs" << endl;
	//cout << "Name: " << Name << endl;
	/*cout << "Gender: ";
		if(Gender == 'm'){
			cout << "male";
		}
		else if(Gender == 'f'){
			cout << "female";
		}
		else{ cout << "NA";}
	cout << endl;*/
	cout << "Spayed: " << Spayed << endl;
	cout << "Registration ID: " << RegID << endl;
	//cout << "Color Description: " << Color << endl;
	cout << "Other Comments: " << Comments << endl;
}