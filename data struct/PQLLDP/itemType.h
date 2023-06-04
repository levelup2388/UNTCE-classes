// itemType.h
#ifndef ITEMTYPE_FLAG
#define ITEMTYPE_FLAG
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct itemType
{
	// Notice that I changed the name from "payLoad".  An itemType may have any
	// number of fields.
	string identifier;
	string payLoad_name;
	int payLoad_weight;

	// itemType needs a constructor and a copy constructor
	itemType(); // constructor
	itemType(const itemType &i); // copy constructor

	// itemType must implement the six relational operators
	bool operator ==	(itemType i);
	bool operator >	(itemType i);
	bool operator <	(itemType i);
	bool operator !=	(itemType i);
	bool operator <=	(itemType i);
	bool operator >=	(itemType i);

	// assignment of itemType=itemType must be defined
	itemType operator = (const itemType i);
	// itemType=string is optional
	itemType operator = (const string s);
	itemType operator++();

	// insertion is used to print the list
	friend ostream &operator << (ostream &, const itemType);
};
#endif

