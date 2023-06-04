/*Nicholas Bright (nicholasbright@my.unt.edu)
10/12/20
shrestha
description:gets file and utputs the text
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
 int main(){
	FILE *fp;
	char filename[55];
	int chars=0, words=0, lines=0;
	char c;
	int end=0;
	
	
	fp = fopen("text.txt", "r");//connect to the input file
	
	if (fp == NULL){
		printf("Unable to open file\n");
		exit(EXIT_FAILURE);
	}
	while(end==0){
		c = getc(fp);
		if(c==' '){
			words++;
		}
		else if(c == '\n'){
			lines++;
			words++;
		}
		else{
			chars++;
		}
		if(c == EOF){
			end=1;
		}
	}
	printf("There are %i Words, %i characters, and %i lines.\n",words,chars,lines);
	fclose(fp);
	return 0;
 }