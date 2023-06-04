#ifndef MOUSE_H
#define MOUSE_H

#include <iostream>
#include <string>
using namespace std;

class Mouse{
	public:
		Mouse();
		Mouse(string type, float mass, string dName, char c, string food, string descript, string com);
		void SetBreed(string type);
		void SetWeight(float mass);
		void SetName(string dName);
		void SetGender(char c);
		void SetFavFood(string food);
		void SetDescription(string descript);
		void SetComments(string com);
		string GetBreed();
		float GetWeight();
		string GetName();
		char GetGender();
		string GetFavFood();
		string GetDescription();
		string GetComments();
		void PrintInfo();
	private:
		string breed;
		float weight;
		string name;
		char gender;
		string favFood;
		string description;
		string comments;
};

#endif
