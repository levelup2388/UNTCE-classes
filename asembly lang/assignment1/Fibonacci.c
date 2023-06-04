//Nicholas Bright (nicholasbright@my.unt.edu)
#include <stdio.h>

int main(){
	int seq[11];	 							//initalize seqence and size of sequence
	
	seq[0]=0;									// input begining of sequnece
	seq[1]=1;
	
	for(int i=2; i<11; i++){					//start of input sequence
		seq[i]=seq[i-1]+seq[i-2];				//fibonacci equation
	}
	
	for(int j=0; j<11; j++) printf("%i\n", seq[j]);	//output
	
	
	return 0;

}