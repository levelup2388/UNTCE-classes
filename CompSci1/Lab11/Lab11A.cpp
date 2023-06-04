#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctype.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

void dispAverage(double* average,int numberOfStudent,int i){
		cout<<"Student #"<<i+1<<" average is:"<< average[i]<<endl;
}
void getGrades(int** grades,int numberOfStudent,double* average){
	int numberOfTest;
	double sum=0.0;
	for(int i = 0;i< numberOfStudent;i++){
		cout << "How many test for student #" << i+1 << ":";
		cin >> numberOfTest;
		
		average = new double [numberOfStudent];
		grades[i] = new int[numberOfTest];
		for(int j = 0;j<numberOfTest;j++){
			cout << "Enter student #" << i+1 << "'s #" << j+1 << " grade:";
			cin  >> grades[i][j];
			sum = sum + grades[i][j];
		}
		average[i]=sum/numberOfTest;
		dispAverage(average, numberOfStudent,i);
		cout << endl;
		//allocate dynamic memory each row
		//obtain scores for each row
		//compute the average and save in the average array
	}
	
}

int main(){
	int numberOfStudent;
	int numberOfTest;
	int** grades;
	double* average;
	
	cout << "How many students?";
	cin  >> numberOfStudent;
	cout<<endl;
	
	for(int i = 0;i< numberOfStudent;i++){
		average = new double [numberOfStudent];
		grades[i] = new int[numberOfTest];
		}//allocate dynamic memory to dynamic arrays
	
	
	getGrades(grades, numberOfStudent, average);
	
	
	delete[] average;//free allocatd dynamic memory
	for (int i =0;i<numberOfTest;i++){
		delete [] grades[i];
	}
	delete[] grades;
	
	return 0;
}