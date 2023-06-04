/*Nicholas Bright (nicholasbright@my.unt.edu)
11414467*/
#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int *int_ptr=(int*)malloc(4* sizeof(int));
	
	printf("Enter first integer: ");
	scanf("%i", int_ptr);
	printf("Enter second integer: ");
	scanf("%i", (int_ptr+1));
	
	printf("Original values: 1st =\t%i 2nd =\t%i\n",int_ptr[0], int_ptr[1]);
	
	int_ptr[0]^=int_ptr[1];
	int_ptr[1]^=int_ptr[0];
	int_ptr[0]^=int_ptr[1];
	
	printf("Swapped values: 1st =\t%i 2nd =\t%i\n",int_ptr[0], int_ptr[1]);
	
	free(int_ptr);
	return 0;
}


