//Nicholas Bright (nicholasbright@my.unt.edu)
#include <stdio.h>

int main(){
	
	float x;			//initalize variables
	int input;
	float cos=0;
	float temp=1;
	float fact=1;
	
	
	printf("input value x:");		//gather input
	scanf("%f", &x);
	printf("input value a:");
	scanf("%i", &input);
	
	for(int i=0; i< input+1; i++){	//start summation loop
		fact=1;
		temp=1;
		for(int w=0; w<2*i; w++){	//x^2n
			temp= temp *x;
		}
		if (i%2==1) temp = temp *-1;	//(x^2n)*(-1)^n
		else{}
		for(int j=1; j<(2*i)+1; j++){   //factorial loop
			fact= fact* j;
		}
		cos = cos + (temp/fact);
	}
	printf("%f\n", cos);			//output
	
	return 0;
}