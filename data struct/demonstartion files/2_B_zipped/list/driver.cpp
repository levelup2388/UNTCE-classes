#include <iostream>
#include "itemType.h"
/*	I would like to #include itemType.h only
	but that does not work for class templates.  */
#include "listType.cpp"   // for class templates, the source file (.cpp) is included
										// other methods exist; however, none are particularly graceful.
using namespace std;

int main()
{
    listType<itemType> lis;
	itemType e;

	lis.create();

	e="fee";
	lis.put(e);
	e="fie";
	lis.put(e);
	e="foe";
	lis.put(e);
	e="fum";
	lis.put(e);

	e="fee";
	if(lis.isThere(e))
		cout<<"good-1\n";
	else
		cout<<"bad-1\n";

	e="fum";
	if(lis.isThere(e))
		cout<<"good-2\n";
	else
		cout<<"bad-2\n";

	e="foo";
	if(lis.isThere(e))
		cout<<"bad-3\n";
	else
		cout<<"good-3\n";
	lis.print();
	cout<<"\n***********\n\n";

	e="foe";
	lis.remove(e);

	lis.print();
	cout<<"\n***********\n\n";

	e="fee";
	lis.remove(e);

	lis.print();
	cout<<"\n***********\n\n";

    // cin.get(); // pauses the program (needed in some platforms)
    return 0;
}
