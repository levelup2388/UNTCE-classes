#include <iostream>
#include "itemType.h"
#include "listType.cpp"   // for class templates, the source file (.cpp) is included
										// other methods exist; however, none are particularly graceful.
using namespace std;


int main()
{
	// test code; modify as needed
    listType<itemType> myLinkedList;
	myLinkedList.create();

	itemType e;
	
	e="test value 2";
	myLinkedList.put(e);
	//myLinkedList.print();

	e="test value 3";
	for(int i=0; i<50; i++)
	myLinkedList.put(e);
	//myLinkedList.print();

	e="test value 1";
	for(int i=0; i<25; i++)
	myLinkedList.put(e);
	//myLinkedList.print();

	e="test value 6";
	myLinkedList.put(e);
	//myLinkedList.print();

	e="test value 4";
	for(int i=0; i<110; i++)
	myLinkedList.put(e);
	//myLinkedList.print();

	e="test value 5";
	for(int i=0; i<100; i++)
	myLinkedList.put(e);
	myLinkedList.print();

	cout<<"\n***** Removing ***\n";
	/*while(!myLinkedList.isEmpty()){
		cout<< myLinkedList.remove()<< "\n***********************\n";
	}
	cout<<"\n***********************\n";*/
	e="test value 1"; // delete at roo
	myLinkedList.remove();
	myLinkedList.print();

	e="test value 4"; // delete mid-list
	myLinkedList.remove();
	myLinkedList.print();

	e="test value 6"; // delete at end
	myLinkedList.remove();
	myLinkedList.print();


	e="test value 2"; // delete at root
	myLinkedList.remove();
	myLinkedList.print();

	e="test value 3"; // delete mid-list
	myLinkedList.remove();
	myLinkedList.print();

	e="test value 5"; // delete at end
	myLinkedList.remove();
	myLinkedList.print();


	cout<<"\n\t*** Run Complete ***\n\n";
    return 0;
}
