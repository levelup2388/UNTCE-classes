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
		static const int MAX=15;

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

			// calling bubbleSort() here would be efficient
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
		// public methods added to demonstrate sorting
		// returns the index of the greatest element from index >= s and < top
private:

		void swap(elementType &a, elementType &b)
		{
			elementType t=a;
			a=b;
			b=t;
		}

		//*****************************************

// buildHeap must be treated as private because it's initially called with parameter "top

	void buildHeap( int first, int last )
	{
    	int largest = first; // Initialize largest as first
    	int l = 2 * first + 1; // left = 2*first + 1
    	int r = 2 * first + 2; // right = 2*first + 2

    	// If left child is larger than first
    	if (l < last && myList[l] > myList[largest])
        	largest = l;

    	// If right child is larger than largest so far
    	if (r < last && myList[r] > myList[largest])
        	largest = r;

    	// If largest is not first
    	if (largest != first)
		{
        	swap(myList[first], myList[largest]);

        	// Recursively buildHeap the affected sub-tree
        	buildHeap(largest, last);
   		 }
	}

	//******************************************
public:

	void testHeap() // wrapper function
	{
    	// Build heap (rearrange array)
    	for (int i = top / 2 - 1; i >= 0; i--)
        	buildHeap(i, top);

    	// One by one extract an element from heap
    	for (int i = top - 1; i > 0; i--)
        	buildHeap(0, i);
	}
/*
	testHeap() is for demonstration only.  It causes the array
	to be a *complete binary tree* or a "heap".  buildHeap(start, end) is
	used by heapSort, but not called like this one is.

	An array is a *heap* when, for any node, n, its left child is found
	at array position 2n+1 and it's right child is at position 2n+2.  The root
	value in the subTree rooted at 2n+1 is greater than the value at n; the
	root value in the subTree rooted at 2n+2 is less than or equal to the
	value at n.
*/

//******************************************************



	void heapSort() //(int arr[], int n) n is top
	{
    	// Build heap (rearrange array)
    	for (int i = top / 2 - 1; i >= 0; i--)
        	buildHeap(i, top);

    	// One by one extract an element from heap
    	for (int i = top - 1; i > 0; i--)
		{
        	// Move current root to end
        	swap(myList[0], myList[i]);

        	// call max buildHeap on the reduced heap
        	buildHeap(0, i);
		}
	}

		//*****************************************


		void print(string caption="") // for diagnostics only (modified to print array index)
		{
			cout<<'\n'<<caption<<"\n**********************************\n\n";

			for(int k=0; k<top; k++)
				cout<<'\t'<<k<<' '<<myList[k]<<'\n';

			cout<<"\n\n**********************************\n\nPrint has paused; press enter to continue:";
			cin.get();
		}
};
#endif

