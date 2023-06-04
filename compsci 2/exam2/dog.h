#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <string>
using namespace std;

class Dog{
	public:
		Dog();
		Dog(string role, float mass, string nameType, char type, string neutered, string regestratID, string description, string comments);
		void setBreed(string role);
		void setWeight(float mass);
		void setName(string nameType);
		void setGender(char type);
		void setSpayed(string neutered);
		void setRegID(string regestratID);
		void setDescript(string description);
		void setComment(string comments);
		string getBreed();
		float getWeight();
		string getName();
		char getGender();
		string getSpayed();
		string getRegID();
		string getDescript();
		string getComment();
		void printInfo();
	private:
		string breed;
		float weight;
		string name;
		char gender;
		string spayed;
		string regID;
		string descript;
		string comment;
};

#endif
