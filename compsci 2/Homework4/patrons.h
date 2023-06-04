#ifndef PATRONS_H
#define PATRONS_H

#include <iostream>
#include <string>
#include "patron.h"
#include <vector>
using namespace std;

class Patrons{
	public:
		Patrons();
		Patrons(int count);
		void AddPatron();
		void EditPatron(int num);
		void PayFines(int num);
		void DeletePatron(int num);
		int FindPatron(int num);
		void PrintList();
		void PrintPdetailts();
	private:
		int Count;
		vector<Patron> pList;
};

#endif
