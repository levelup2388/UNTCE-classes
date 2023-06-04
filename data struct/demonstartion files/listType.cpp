// listType.cpp				S.W. Smith
#ifndef LISTTYPE_FLAG
#define LISTTYPE_FLAG
#include <iostream>
#include <cstddef>
using namespace std;

// in-line method definitions are OK for a template
// because the .cpp file must be included

template <class elementType>
class listType
{
	private:
		static const int MAX=10;

		int top, envVar; // discuss the uses of the environmental variable: envVar

		elementType* myList;

	public:
		listType()
		{
			myList=NULL;
		} // constructor.

		//******************************

		~listType()
		{
			delete[] myList;
		} // destructor.

		//******************************

		void create()
		{
			myList=new elementType[MAX];
			top=0;
		}

		//******************************

		bool isRoom()
		{
			return top<MAX;
		}

		//******************************

		// This example will use a modified version of the insertionSort algorithm to insert an element
		// into its correct position in the array.

		//******************************

		bool isThere(elementType &e)
		{
			/*
				We could iterate through the list using envVar; however, as a rule, using
				a local variable within the method is more efficient... or so some people say.
			*/
			int j=0;
			while(j<top && myList[j]<e) // note that it's now *less than*!
				j++;

			envVar=j; // slight modification of isThere

			if(j==top)
				return false;
			else
				return myList[j]==e;
		}

		//******************************

		void put(elementType &e)
		{
			if(isRoom() && !isThere(e))
			{
					for( int i=top; i>envVar; i--)
						myList[i]=myList[i-1];

					top++;

					myList[envVar]=e;
			}
		}

		//******************************

		void remove(elementType &e)
		{
			if(isThere(e))
			{
				top--;

				for(int i=envVar; i<top; i++)
					myList[i]=myList[i+1];
			}
		}

		//******************************

		void print() // for diagnostics only (modified to print array index)
		{
			cout<<"\n\n**********************************\n\n";

			cout<<top<<'\t'<<'\n';

			for(int k=0; k<top; k++)
				cout<<'\t'<<k<<' '<<myList[k]<<'\n';

			cout<<"\n\n**********************************\n\nPrint has paused; press enter to continue:";
			cin.get();
		}
};
#endif

