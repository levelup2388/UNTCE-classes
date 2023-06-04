/*Nicholas Bright (nicholasbright@my.unt.edu)
njb0130*/
#include <stdio.h>

int main(){
	unsigned char input;
	int temp;
	int check;
	printf("Enter an ASCII character: ");
	scanf("%c", &input);
	printf("\tdec -- %d \n\thex -- %x\n\tbin -- ", input, input);
	for(int i=0;i<8;i++){
		temp=128;					
		temp>>=i;				
		check= temp&input;		
		if(check==temp){
			printf("1");
		}
		else{
			printf("0");
		}
	}
	printf("\n");

	return 0;
}


