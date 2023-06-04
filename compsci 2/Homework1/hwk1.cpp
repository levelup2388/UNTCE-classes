/*Nicholas Bright (nicholasbright@my.unt.edu)
1/26/21
keathly
description:using structers and pointers reads in student names and grades in order to output in order students with average as well as the stats for the class.
*/

#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "bubble.h"

struct classStats{//stats variable struct
	float mean;
	float min;
	float max;
	float median;
	char *name;
};

int main()
{		//variable decleration with pointer
		classStats cStats;
		student *students[19];
		int classSum=0;
		//file declration, openning and testing
		FILE *fp;
		fp = fopen("grades", "r");
		if (fp == NULL){
		printf("Unable to open file\n");
		exit(EXIT_FAILURE);
		}
		//pointer memory allocation
		cStats.name = (char*)malloc(sizeof(char)*8);
		for(int i=0;i<19;i++){
			students[i] = (student*)malloc(sizeof(student));
			students[i]->first = (char*)malloc(sizeof(char)*10);
			students[i]->last = (char*)malloc(sizeof(char)*10);
		}
		
		fscanf(fp,"%s" ,cStats.name);//reads in class name
		for(int i=0; i<19; i++){//read in loop
			fscanf(fp, "%s %s %d %d %d", students[i]->first,students[i]->last,&students[i]->exam1,&students[i]->exam2,&students[i]->exam3);//reads in student info for line
			students[i]->mean = (students[i]->exam1 + students[i]->exam2 + students[i]->exam3) / 3.00;//creats mean or student
			classSum += students[i]->mean;//adds to sum for total mean
		}
		bubble(students,19);//bubble sort file sorts info
		//declaring what stats equal to
		cStats.mean = classSum / 19.00;
		cStats.min = students[0]->mean;
		cStats.max = students[18]->mean;
		cStats.median = students[9]->mean;
		
		printf("%s MEAN: %.2f MIN: %.2f MAX: %.2f MEDIAN: %.2f\n", cStats.name, cStats.mean, cStats.min, cStats.max, cStats.median);//printing title line/class stats
		for(int i=0;i<19;i++){//loop for students
			printf("%12s %11s %.2f\n", students[i]->first,students[i]->last,students[i]->mean);//prints student info
		}
		
		//closes file and frees memory
		fclose(fp);
		for(int i=0; i<19; i++){
			free(students[i]);
		}
		free(cStats.name);
		
  return 0;
}
