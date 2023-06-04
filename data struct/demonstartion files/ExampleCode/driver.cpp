#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "itemType.h"
#include "listType.cpp"
using namespace std;

const int STR_MAX=8;

int main()
{
    listType<itemType> lis;
	itemType e;
	string randStr="";

	lis.create(); // I *always* forget this one and then I wonder why it isn't working!

	//srand (time(NULL)); // initialize random generator with clock seed:
	srand(54);

	while(lis.isRoom())
	{
		// generate an 8 character random string of capital letters
		for(int i=0; i<STR_MAX; i++)
			randStr = randStr+char(rand()%26 + 65);

		e=randStr.substr(0,2); // load the string into a list element
		randStr=""; // clear the string variable
		lis.put(e); // put the element into the list
	}

	lis.print("Raw Data");

	lis.testHeap();

	lis.print("the data as a Heap:");

	lis.heapSort();

	lis.print("The Sorted List");

    // cin.get(); // pauses the program (needed in some platforms)
    return 0;
}
