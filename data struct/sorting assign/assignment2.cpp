//nicholasbright@my.unt.edu
// programming assignment

/*
	In this assignment, we will implement four sorting algorithms.  I have stubbed
	the sorting routines.  Before each sort, my code calls loadArr.  The counts in
	the array should sum to 3946 after loading.  before sorting, the array index may
	be interpreted as an ASCII code; however, the character and its weight stay together.

	You may choose the direction of your sort.
*/

#include <iostream>
#include <fstream>
#include <cstddef>
#include <ctype.h>
using namespace std;

struct statType
{
	char ascii;
	int	weight;
	/*
		This is what you will be sorting by weight.
        
        You may define any operators you need (or want) on these objects.
		(I would think that, since we're sorting, the six relational operators
         and assignment would come in real handy!)
         
        I have written the printArr routine without using insertion on statType.         
	*/
	bool operator ==(statType &p){
	return ascii==p.ascii;
	}
	bool operator >(statType &p){
		if(weight == p.weight)
			return ascii>p.ascii;
		else
			return weight>p.weight;
	}
	bool operator <(statType &p){
		if(weight == p.weight)
			return ascii<p.ascii;
		else
			return weight<p.weight;
	}
	bool operator !=(statType &p){
		if(weight == p.weight)
			return ascii!=p.ascii;
		else
			return weight!=p.weight;
	}
	bool operator >=(statType &p){
		if(weight == p.weight)
			return ascii>=p.ascii;
		else
			return weight>=p.weight;
	}
	bool operator <=(statType &p){
		if(weight == p.weight)
			return ascii<=p.ascii;
		else
			return weight<=p.weight;
	}
};

const int ARR_BOUND=256;

void loadArr(statType*);
void printArr(statType*, string="");

void selectionSort(statType*);
void bubbleSort(statType*);
void insertionSort(statType*);
void heapSort(statType*);

int main()
{
	statType* dataArr;
	dataArr=new statType[ARR_BOUND];

	loadArr(dataArr);			// counts the occurrences of each  UTF-8 character in 
                                // a file by using the character's ASCII code as an
                                // array index and incrementing that array position.
                                // Your code will sort the array by weight.
                                
	printArr(dataArr, "Unsorted Data");			// prints the non-zero array positions
	selectionSort(dataArr);
	printArr(dataArr, "Selection Sort");			// prints the non-zero positions of the sorted array

//	Uncomment the lines as you implement them

	loadArr(dataArr);
	bubbleSort(dataArr);
	printArr(dataArr, "Bubble Sort");

	loadArr(dataArr);
	insertionSort(dataArr);
	printArr(dataArr, "Insertion Sort");

	loadArr(dataArr);
	heapSort(dataArr);
	printArr(dataArr, "Heap Sort");


	return 0;
}

// *************************************************

void loadArr(statType* arr)
{
	ifstream inFile;
	inFile.open("assignment2.input.txt");  // The input file must be in same directory as source file
	if( inFile.fail() )
	{
		cout<<"file error\n";
		cin.get();
		exit(1);
	}

	for(int i=0; i<ARR_BOUND; i++) // initialize the array
	{
		arr[i].ascii=(char)i;
		arr[i].weight=0;
	}

	char ch;
	while(true)
	{
		ch=inFile.get();
		//cout<<ch;  // stream to console (optional).  
                   // Comment this line to suppress the echo print.

		if( inFile.eof() )
			break;

		arr[(int)ch].weight++;
	}
	inFile.close();
	inFile.clear(); // resets the IO flags
	cin.get();
}

// **************************************************

void printArr(statType* arr, string caption)
{
	int chCnt=0;
	cout<<"\n\n\t"<<caption<<'\n';
	for(int i=0; i<ARR_BOUND; i++){
		if(arr[i].weight)
		{
			cout<<"\t*\t"<<i<<'\t'<<arr[i].ascii<<'\t'<<arr[i].weight<<" ~\n";
			chCnt+=arr[i].weight;
		}
	}
		cout<<"\n\n\t"<<chCnt<<" characters processed.\n\tInput paused, press 'Enter'"; // I get 3946
		cin.get();
}

//***************************************************
void swap(struct statType *x, struct statType *y) { 
    struct statType temp = *x; 
    *x = *y; 
    *y = temp; 
}/*
int findMax(statType* arr, int i){
	int localMaxIndex=0;
	for(int i=0; i<ARR_BOUND; i++){
		if(arr[localMaxIndex].weight<arr[i].weight)
			localMaxIndex=i;
	}
	return localMaxIndex;
}*/
void selectionSort(statType* arr){
	int i, j, min_idx; ///initialize variables
	for (int i = 0; i < ARR_BOUND; i++){//outer loop
		for (j = i+1; j < ARR_BOUND; j++) {//inner loo[
			if (arr[j] < arr[min_idx]) {
				min_idx = j; //if arr at j is less than arr at min j equals min
			}
			swap(arr[min_idx], arr[i]);//swap arr min and arr i
		}	
	}
}

void bubbleSort(statType* arr){ 
    for (int i = 0; i < ARR_BOUND-1; i++){//outer loop
		for (int j = 0; j < ARR_BOUND-i-1; j++){// inner loop
			if (arr[j] > arr[j+1])
				swap(arr[j], arr[j+1]);// swap points if first is larger than second
		}
	}
}

void insertionSort(statType* arr){
	int j;				//inittialize variables
	statType exit;
	
    for (int i = 1; i < ARR_BOUND; i++){//loop unitl end of array
        exit = arr[i];
        j = i - 1;
        while ( j >= 0 && arr[j] > exit){//while arr at j is greater than exit and j DNE 0
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = exit;
    }
}
void heapify(statType* arr, int first, int last){
    int largest = first; // Initialize variables
    int l = 2 * first + 1; 
    int r = 2 * first + 2; 
	
    if (l < last && arr[l].weight > arr[largest].weight)//if left child is larger than largest
        largest = l;
    if (r < last && arr[r].weight > arr[largest].weight)//if right child is larger than largest
        largest = r;
    if (largest != first) {//if largest is not in the heap
        swap(arr[first], arr[largest]);//swap first and last
        heapify(arr, largest, last);// heapify until conditions met
    }
}
void heapSort(statType* arr){
    // Build heap (rearrange array)
    for (int i = ARR_BOUND / 2 - 1; i >= 0; i--)
        heapify(arr, i, ARR_BOUND);// extracts element from heap
    for (int i = ARR_BOUND - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // swap current with last
        heapify(arr, 0, i);// reduces heap to max i
    }
}
