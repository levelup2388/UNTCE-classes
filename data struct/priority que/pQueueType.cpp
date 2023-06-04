#ifndef pQueueType_FLAG
#define pQueueType_FLAG
#include <iostream>
#include <cstddef>
using namespace std;

template <class elementType>
class pQueueType
{
	private:
		static const int MAX=10;

		int top, envVar; 

		elementType* myList;

	public:
		pQueueType(){
			myList=NULL;
		} // constructor.

		~pQueueType(){
			delete[] myList;
		} // destructor.

		void create(){
			myList=new elementType[MAX];
			top=0;
		}

		bool isRoom(){
			return top<MAX;
		}

		void put(elementType &e){
			int i =0;
			while(i<top){
				if(myList[i] == e){
					myList[i].payLoadWeight++;
					return;
				}
				i++;
			}
			if(isRoom())
			myList[top++]=e;
		}
		
		bool isEmpty(){
			return top ==0;
		}
		int findMax(){
				int localMaxIndex=0;

				for(int i=1; i<top; i++){
					if(myList[localMaxIndex]<myList[i])
						localMaxIndex=i;
				}
				return localMaxIndex;
		}
		elementType deQueue(){
			int t = findMax();
			elementType temp = myList[t];
			myList[t]=myList[--top];
			return temp;
		}
		
	void print(){ 
		for(int k=0; k<top; k++)
			cout<<myList[k]<<'\n';
	}
};
#endif