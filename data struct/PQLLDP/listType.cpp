// listType.cpp				S.W. Smith
#ifndef LISTTYPE_FLAG
#define LISTTYPE_FLAG
#include <iostream>
using namespace std;

template <class elementType>
class listType
{
	private:
		// the definition of the struct nodeType is private
		struct nodeType
		{
			elementType payLoad;
			nodeType* next;

			nodeType()
			{
				next=NULL;

				return;
			}
		};

		nodeType *root;
		nodeType** envPtr;
		//	nodeType *envPtr; // we will have *much* to say about this!

		//**************************************
/*
		void altCreate(nodeType *p)
		{
			if(p)
			{
				altCreate(p->next);
				delete p;
			}   // we'd like to have the recursive call after delete.

			return;
		}
*/
		//***********************************
		// wrapper method for create()
		void altCreate(nodeType *p) // a better version with recursion at end of the logic.
		{
			if( p )
			{
				nodeType *q;
				q=p->next; // maybe q is NULL, maybe not.

				p->next=NULL;
				delete p;
				altCreate( q );
			}

			return;
		}

		//***********************************
		// wrapper method for print()
		void altPrint(nodeType *p)
		{
			if(p)
			{
				cout<<p->payLoad<<'\n';
				altPrint(p->next);
			}

			return;
		}
		//************************************
	public:
		listType()
		{
			root=NULL;

			return;
		} // constructor.

		//******************************

		~listType()
		{
			altCreate(root); // this deletes an existing list

			return;
		} // destructor.

		//******************************

		void create()
		{
			altCreate(root);
			root=NULL;

			return;
		}

		//******************************

		bool isRoom()
		{
			return true; // this will do for now; more to come later on this.
		}

		//****************************************

		bool isThere(elementType &e)
		{
			envPtr = &root;
			while(*envPtr && (*envPtr)->payLoad>e)
					envPtr = &(*envPtr)->next;
				
				return *envPtr && (*envPtr)->payLoad ==e;
		}
		bool isEmpty()
		{
			return root;
		}
		//******************************
/*
		// one option for example:

		void put(elementType &e)
		{
			// inserting a node at the beginning of a linked list:
			if( !isThere(e) )
			{
				nodeType* p;
				p=new nodeType;
				p->payLoad=e;

				p->next=root;
				root=p;
			}

			return;
		}
*/
		//******************************
/*
		// A second example option:
		void put(elementType &e)
		{
			// inserting a node at the end of a linked list:
			if( !isThere(e) )
			{
				if(!root) // if root is NULL
				{
					root=new nodeType;
					root->payLoad=e;
				}
				else
				{
					nodeType* p;
					p=root;

					while(p->next)
						p=p->next;	// loop exits on last node

					p->next=new nodeType;
					p=p->next;
					p->payLoad=e;
				}
			}

			return;
		}
*/
		//****************************************
		// inserting a node into an ordered list.  This will be the class' working example
		// This logic will also be used in the enQueue method of the priority queue
		void put(elementType &e)
		{
			if(isThere(e)){
				nodeType *p;
				p = *envPtr;
				*envPtr= (*envPtr)->next;
				p->next=NULL;
				
				e= p->payLoad;
				++e;
				delete p;
				put(e);
				
			}
			else{
				nodeType *p;
				p = *envPtr;
				*envPtr= new nodeType;
				(*envPtr)->payLoad=e;
				(*envPtr)->next=p;
			}
			return;
		}

		//******************************
		void remove()
		{
			if(root){
				nodeType *p;
				p = root;
				root = root->next;
				p->next =NULL;
				delete p;
			}
			return;
		}
		void del(elementType &e){
			if(isThere(e))
			{
				nodeType *p, *q;
				p = root;
				q = NULL;

				while(p->payLoad != e)
				{
					q=p;
					p=p->next;
				}
				if(!q)
					root=root->next;
				else
					q->next = p->next;

				p->next=NULL;
				delete p;
			}
			return;
		}

		//******************************

		void print() // for diagnostics only
		{
			cout<<"\n\n*********************\n";
			if(root)
				altPrint(root); // this line is all that's needed; everything else is optional
									// altPrint is recursive
			else
				cout<<"Null root.\n";

			return;
		}
};
#endif

