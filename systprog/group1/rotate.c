#include <stdio.h>

unsigned int rotate(unsigned int input,unsigned int move){

		
	unsigned int out=input;
	unsigned int bmask = 1;
	unsigned int fmask = 2147483648;
	
	for (int i=0; i<move; i++){
		if((out & bmask) == 1){
			out= ((out>>1) | fmask);
		}
		else{
			out= out>>1;
		}
	}
//	if((out<0)&&(check=='f')){
//		printf("%d\n",out);
//		out=out*-1;
//	}
	//mask front bit, shift left, or front bit to last bit
	
	

	return out;
}