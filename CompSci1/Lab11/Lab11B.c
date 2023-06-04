#include <stdio.h>
#include <stdlib.h>


int main(){
	
	char end='Y';
	int i=0;
	double sum=0;
	int numNum=0;
	double average;
	int size=2;
	double *ptr=(double*)malloc(0* sizeof(double));
	
	while(end=='Y'){
		ptr=realloc(ptr,size*sizeof(double));
		printf("Enter a number:");
		scanf("%lf",(ptr+numNum));
		numNum++;
		sum+=ptr[i];
		printf("List of numbers:\n");
		for(int i = 0;i<numNum;i++){
			printf("%lf",ptr[i]);
			//printf("%lf",*(ptr+numNum));
			printf("\n");
		}
		average=sum/numNum;
		printf("Updated average is:");
		printf("%lf",average);
		printf("\nMore numbers (Y/N):");
		scanf(" %c", &end);
		i++;
		size++;
	}
		
	
	
	
	
	
	free(ptr);
}