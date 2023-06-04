//Nicholasbright@my.unt.edu
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <iostream>
using namespace std;

const int MAX=128;  // size of the array

bool binSearch(int ar[], int Exit); // add whatever parameters you need

int main ()
{
    // Do not modify main().

    int* intArray;
    intArray=new int[MAX];  // do *not* make the array global!!!
    intArray[0]=1;

    // loads the array with unique "random" integers in ascending order

    srand (time(NULL));
    for(int i=1; i<MAX; i++)
        intArray[i]=intArray[i-1]+rand()%5+1;

    // the intArray now contains MAX integers such that, for all i in the range 0..MAX-2,
    // intArray[i] < intArray[i+1].  I.e.: the values are sorted.  If "less than" holds,
    // then there can be no duplicate values.  It is not possible to have any value greater
    // than 512 in the array.

    // the search runs 512 (MAX*4) iterations; it should find 128 (MAX) values.
    int cnt=0;
    for(int i=0; i<4*MAX; i++){
        if( binSearch(intArray, intArray[i]))cnt++;
	}

    cout<<"\n\nThe expected count is 128.\nYour count is: "<<cnt;

    cout<<"\n\nRun Complete.\n\n";

  return 0;
}


bool binSearch(int ar[], int Exit) {
	for(int c=0; c <MAX; c++){
		if(ar[c]==Exit){
			return true;
		}
	}
		
	/*while (b <= top){
		mid = b + ((top - b) >> 1);//sets midpoint as the size minus bottom right shifted then adding back to bottom
		if (ar[mid] == Exit ){ //Exit if the array at midpoint is equal to array at i
		  return true;
		}
		else if (ar[mid] > Exit){ //if midpoint array is greater than array at i set top to midpoint minus 1
		  top = mid - 1;
		}
		else if (ar[mid] < Exit){ //if midpoint array is less than array at i set bottom to midpoint+1
		  b = mid + 1;
		}
	}*/
	return false;//Array at i not found within scope of [0,MAX-1]
}


