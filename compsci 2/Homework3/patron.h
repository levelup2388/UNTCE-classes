#ifndef PATRON_H
#define PATRON_H

#include <iostream>
#include <string>
using namespace std;

class Patron{
	public:
		Patron();
		Patron(string name, int num, int fineBal, int numBooksOut);
		void setName(string name);
		void setIDnum(int num);
		void setFineBal(int fineBal);
		void setNumBooksOut(int numBooksOut);
		string getName();
		int getIDnum();
		int getFineBal();
		int getNumBooksOut();
	private:
		string Name;
		int IDnum;
		int FineBal;
		int NumBooksOut;
};

#endif
