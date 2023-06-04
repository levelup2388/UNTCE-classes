/*Nicholas Bright (nicholasbright@my.unt.edu)
10/12/20
shrestha
description:gets file and utputs the text
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define METERS_TO_FEET 3.28084
#define convert(x) ((x)*METERS_TO_FEET)
 int main(){
	FILE *fp;
	FILE *outp;
	char c;
	double met;
	double *dp;
	dp = &met;
	
	fp = fopen("meters.txt", "r");
	if (fp == NULL){
		printf("Unable to open file\n");
		exit(EXIT_FAILURE);
	}
	outp = fopen("Meters_To_Feet.txt", "w");
	if (outp == NULL){
		printf("Unable to open file\n");
		exit(EXIT_FAILURE);
	}
	while(fscanf(fp,"%lf ",&met)!=EOF){
		met = convert(met);
		fprintf(outp,"%0.3lf ",met);
	}
	
	fclose(fp);
	fclose(outp);
	 
	return 0;
 }