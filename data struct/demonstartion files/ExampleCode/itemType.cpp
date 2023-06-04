
#include "itemType.h"
#include <iostream>
using namespace std;

itemType::itemType()
{
	payLoad="";
} // stubbed constructor

itemType::itemType(const itemType &p)
{
	payLoad = p.payLoad;
} // copy constructor

void itemType::operator =(itemType &i)
{
	payLoad=i.payLoad;
}

bool itemType::operator ==(itemType &i)
{
	return payLoad==i.payLoad;
}

bool itemType::operator >(itemType &i)
{
	return payLoad>i.payLoad;
}

bool itemType::operator <(itemType &i)
{
	return payLoad<i.payLoad;
}

bool itemType::operator !=(itemType &i)
{
	return payLoad!=i.payLoad;
}

bool itemType::operator >=(itemType &i)
{
	return payLoad>=i.payLoad;
}

bool itemType::operator <=(itemType &i)
{
	return payLoad<=i.payLoad;
}


void itemType::operator =(string s) // included only for the programmer's convieniance
{
	payLoad=s;
}
/*	in driver.cpp, the code:

		itemType i;
		i.payLoad="foo";

	would be perfectly legal.  This operator allows it to be simply:		i="foo";
	It's entirely optional.
*/

ostream &operator << (ostream &out, const itemType &c) // needed to print the list
{
    out << c.payLoad;
    return out;
}


