/*Nicholas Bright (nicholasbright@my.unt.edu)
10/12/20
shrestha
description:
*/
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(){
	
	int i = 0;
	
	do{
		int* grades;
		double sum = 0;
		int numGrades; //number of grades
		
		cout << "Enter the number of grades : ";
		cin  >> numGrades;
		grades = new int[numGrades];
		
		for (int j = 0; j < numGrades; j++){
			cout << "Enter grade #" << (j + 1) << ": ";
			cin  >> grades[j];
			
			sum += grades[j];
		}
		
		cout << "Student " << (i + 1) << " average: " << sum/numGrades << endl;
		delete []grades;
		i++;
	} while (i < 2);
	
	return 0;
}