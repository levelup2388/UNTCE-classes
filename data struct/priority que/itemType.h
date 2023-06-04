// itemType.h
#ifndef ITEMTYPE_FLAG
#define ITEMTYPE_FLAG

#include <string>
using namespace std;

struct itemType
{
	string payLoad;
	int payLoadWeight;
	
	itemType(); // constructor
	itemType(const itemType &); // copy constructor
	void operator =(itemType &);
	bool operator ==(itemType &);
	bool operator >(itemType &);
	bool operator <(itemType &);
	bool operator !=(itemType &);
	bool operator <=(itemType &);
	bool operator >=(itemType &);
	void operator =(string);
	friend ostream &operator << (ostream &, const itemType &);
};
#endif