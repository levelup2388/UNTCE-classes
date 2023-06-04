#include <iostream>
using namespace std;

struct demoType
{
	int foo;
	void fee()
	{
		cout<<"hello world\n";
	}

	demoType* next;

	demoType()
	{
		next = NULL;
	}
};

int main()
{

	int i; // an integer variable
	i = 5;

	int* q; // a variable that may contain the address of an integer variable or constant

	q = &i; // q points to i

	cout<<i<<'\t'<<*q<<'\n';  // print i and the target of p (same thing)

	*q = 7; // sets i to 7.

	q = NULL;
	//    *q = 13;  // fatal error!

	q = new int; // allocates a new integer

	delete q;  // what is allocated must be returned


//		It is good programming style never to have an uninitialized pointer... ever!
//		A pointer can be NULL, that's OK.  If your code tries to dereference it, the program
//		dies... this isn't good; however, it's better than unpredictable behavior.
//
//		Some programmers will declare pointers thus:
//
//		int *p=NULL;
//
//		This is legal; however, it looks like you're saying "the target of p gets NULL"
//		and that's not so.  I prefer doing it in two steps... at least while we're learning;
//
//		int* p;
//		p=NULL;
//
//		int* p;  		and		int *p; 		are the same statement; I prefer the former.

	//**************************

	demoType* root;  // d is a pointer to a struct

	root = new demoType;         //  sometimes you will see:    demoType *d=new demoType;   I discussed that above.

	root->foo = -3;  // I will say:  "root hat foo gets 23"

	root->fee();

	root->next=new demoType;

	root->next->foo = -13;

	cout<<root->foo<<'\t'<<root->next->foo<<'\n';

	root->next->next=new demoType;

	root->next->next->foo = -23;

	cout<<root->foo<<'\t'<<root->next->foo<<'\t'<<root->next->next->foo<<'\n';

	demoType* p;

	cout<<"\n\nprint loop 1:\n";
	p=root;
	while(p)
	{
		cout<<p->foo<<'\t';
		p = p->next;
	}
	cout<<'\n';

	// put a new record at the end
	p=root;
	while(p->next)
		p = p->next;

	p->next=new demoType;
	p=p->next;
	p->foo=-33;

	cout<<"\n\nprint loop 2:\n";
	p=root;
	while(p)
	{
		cout<<p->foo<<'\t';
		p = p->next;
	}
	cout<<'\n';

	// in general
	// put a new record at the end
	p=root;
	while(p->next)
		p = p->next;

	p->next=new demoType;
	p=p->next;
	p->foo=-43;

	cout<<"\n\nprint loop 2:\n";
	p=root;
	while(p)
	{
		cout<<p->foo<<'\t';
		p = p->next;
	}
	cout<<'\n';




/*
*/



	return 0;
}
