// listType.cpp				S.W. Smith
#ifndef LISTTYPE_FLAG
#define LISTTYPE_FLAG
#include <iostream>
#include <cstddef>
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
			}
		};

		nodeType* root;


	public:
		listType()
		{
			root=NULL;
		} // constructor.

		//******************************

		~listType()
		{

		} // destructor.

		//******************************

		void create()
		{
			// Later
		}

		//******************************

		bool isRoom()
		{
			return true; // OK for now
		}

		//******************************

		// Look carefully at the file pointerReview.cpp (which is included in the .zip package)
		// All I'm doing here is exactly what I did there.
		//
		// So, help me out... why is it dying?  How can I fix it?

		void put(elementType &e)
		{
			cout<<"checkpoint1\n";
			cin.get();

			nodeType* p;
			p=root;

			while(p->next)
				p=p->next;

			p->next=new nodeType;
			p=p->next;
			p->payLoad=e;

			cout<<"checkpoint2\n";
			cin.get();
		}

		//******************************

		bool isThere(elementType &e)
		{
			return true;
		}

		//******************************

		void remove(elementType &e)
		{

		}

		//******************************

		void print() // for diagnostics only
		{

		}
};
#endif

