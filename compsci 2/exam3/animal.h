#ifndef ANIMALH
#define ANIMALH

#include <iostream>
#include <string>

using namespace std;

class Animal {
	protected:
	   float Weight;
	   string Name;
	   char Gender;
	   string Color;
	public:
		Animal();
		Animal(float weight, string name, char gender, string color);
		void setWeight(float weight);
		void setName(string name);
		void setGender(char gender);
		void setColor(string color);
		float getWeight();
		string getName();
		char getGender();
		string getColor();
		virtual void PrintInfo()const;
};

#endif
