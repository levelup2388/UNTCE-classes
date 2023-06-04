//Nicholas Bright (nicholasbright@my.unt.edu)
#include <iostream>
using namespace std;

template <class elementType>
class listType{
private:
	static const int HASH_SPACE = 0x10; // 16 in hex

	// the definition of the struct nodeType is private
	struct nodeType{
		elementType payLoad;
		nodeType* next;

		nodeType()
		{
			next=NULL;
			return;
		}
	};

	nodeType **roots, **envPtr;

	void altCreate(nodeType *p){
		if(p)
		{
			nodeType *q;
			q=p->next; // maybe q is NULL, maybe not.

			p->next=NULL;
			delete p;
			altCreate(q);
		}
		return;
	}

	void altPrint(nodeType *p){
		if(p)
		{
			cout<<"	  "<<p->payLoad<<'\n';
			altPrint(p->next);
		}
		return;
	}

	int getHashIndex(unsigned long k){
		return k%HASH_SPACE;
	}

public:
	listType(){
		roots = new nodeType*[HASH_SPACE];

		for(int i=0; i<HASH_SPACE; i++)
			roots[i]=NULL;

		envPtr=NULL;
	}
	~listType(){
		for(int i=0; i<HASH_SPACE; i++)
		{
			altCreate(roots[i]);
		}
		return;
	}
	void create(){
		for(int i=0; i<HASH_SPACE; i++)
		{
			altCreate(roots[i]);
			roots[i] = NULL;
		}
		return;
	}

	bool isThere(elementType &e) { // demonstrating getHashIndex{
		unsigned long h = e.getHash();
		int i = getHashIndex(h);

		//cout<<"The long int (in hex) returned from itemType is: "
		//	<<hex<<h<<'\n'<<"The index for "<<e.identifier
		//	<<" will be "<<hex<<i<<" in hex or "<<dec<<i
		//	<<" in decimal.\n\n";

		envPtr = &roots[i];
		while(*envPtr && (*envPtr)->payLoad != e)
			envPtr = &(*envPtr)->next;

		return *envPtr && (*envPtr)->payLoad == e;
	}
	void put(elementType &e){
		if( !isThere(e) )
		{
			nodeType *p;
			p = *envPtr;
			*envPtr = new nodeType;
			(*envPtr)->payLoad = e;
			(*envPtr)->next = p;
		}
		return;
	}

	void remove(elementType &e){
		if(isThere(e))
		{
			nodeType *p;
			p = *envPtr;
			*envPtr = (*envPtr)->next;
			p->next = NULL;
			delete p;
		}
		return;
	}

	void print(){
		for(int i=0; i<HASH_SPACE; i++)
		{
			cout << "\n	Bucket: " << i << "\n";
			if(roots[i])
				altPrint(roots[i]);
		}
		cout << "\n\n*********************\n";
		return;
	}
};
