//Nicholas Bright (nicholasbright@my.unt.edu)
#include <stdio.h>

int main(){
	int A[5];//intialize the arrays
	int B[5];
	int vector;
	
	for(int i=0; i<5; i++){				//input numbers into array
		A[i]=2*i+1;
		B[i]=2*i+2;
	}
	
	for(int j=0; j<5; j++){
		vector = A[j]*B[j];		  //calculate vector
		printf("%i\n", vector);	 //output
	}
	
	return 0;

}