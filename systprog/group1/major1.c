#include "major1.h"

int main(){
	int sel;
	char exit ='f';
	while(exit=='f'){
		printf("Enter the menu option for the operation to perform:\n");
		printf("(1) Count Leading Zeroes\n");
		printf("(2) Endian Swap\n");
		printf("(3) Rotate-right\n");
		printf("(4) Parity\n");
		printf("(5) EXIT\n");
		printf("--> ");
		scanf("%d",&sel);
		if (sel==1){
			//clz();
			//shift right until equal to 0 however many times you shift it -32
		}
		else if (sel==2){
			//endian();
			//mask each section, swap, or them back together
		}
		else if (sel==3){
			unsigned int input;
			unsigned int move;
			unsigned int output;

			printf("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): ");
			scanf("%u",&input);
			printf("Enter the number of positions to rotate-right the input (between 0 and 31, inclusively): ");
			scanf("%u",&move);
			output = rotate(input,move);
			printf("%u rotated by %u position gives: %u\n",input,move,output);
		}
		else if (sel==4){
			//partity 
		}
		else if (sel==5){
			exit='t';
		}
		else{
			printf("Error: Invalid option. Please try again.\n");
		}
	}
	printf("Program terminating. Goodbye...\n");
	return 0;
}