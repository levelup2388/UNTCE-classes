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

		void put(elementType &e)
		{
			if(isRoom() && !isThere(e))
			myList[top++]=e;
		}

		//******************************

		bool isThere(elementType &e)
		{
			int j=0;

			while(j<top && myList[j]!=e)
				j++;

			if(j<top)
			{
				envVar=j;
				return true;
			}
			else return false;
		}

		//******************************

		void remove(elementType &e)
		{
			if(isThere(e))
				myList[envVar]=myList[--top];
		}

		//******************************

		void print() // for diagnostics only
		{
			for(int k=0; k<top; k++)
				cout<<myList[k]<<'\n';
		}
};
#endif

