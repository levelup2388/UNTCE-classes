#include "itemType.h"
#include "pQueueType.cpp"
#include <iostream>
using namespace std;

int main(){
		
	cout<<"\n\nbegin main()\n\n";
	pQueueType<itemType> pq;
	pq.create();
	itemType e;

	e="fee";
	pq.put(e);

	e="fie";
	pq.put(e);
	pq.put(e);

	e="foe";
	pq.put(e);

	e="fum";
	pq.put(e);

	e="baz";
	for(int i=0; i<100; i++)
		pq.put(e); // 99

	e="quux";
	for(int i=0; i<100; i++)
		pq.put(e); // 99

	e="fie";
	for(int i=0; i<500; i++)
		pq.put(e); // 499

	e="foo";
	for(int i=0; i<50; i++) 
		pq.put(e); //49

	e="bar";
	pq.put(e); // 500
	pq.print();

	/*
	begin main()
	fee     0
	fie     501
	foe     0
	fum     0
	baz     99
	quux    99
	foo     49
	bar     0
	*/
	cout<<"\n\n\n\n";

	while(!pq.isEmpty())
		cout<<pq.deQueue()<<"\n***********************\n";

	/*
	fie     501
	***********************
	quux    99
	***********************
	baz     99
	***********************
	foo     49
	***********************
	fum     0
	***********************
	foe     0
	***********************
	fee     0
	***********************
	bar     0
	***********************
	end main()
	*/
	cout<<"\nend main()\n\n";

	return 0;

}

 
