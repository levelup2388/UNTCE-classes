/*Nicholas Bright (nicholasbright@my.unt.edu)
10/5/20
shrestha
description-optain 10 grades and calulate the mean and standard deviation
*/
#include <iostream>
#include <cmath>
using namespace std;

int main(){
	//variable declaration
	const int SIZE = 10;
	float grade[SIZE];
	float mean;
	float sum = 0;
	float standDev = 0;
	cout << "Enter 10 grades:";
	//enters grades for array
	for(int i = 0;i < SIZE; i++){
		cin >> grade[i];
		sum = sum + grade[i];
	}
	//calculates mean
	mean = sum / SIZE;
	cout << mean << endl;
	//calculates standard deveation
	for(int j = 0;j < SIZE ;j++){
	standDev = standDev + pow(grade[j]-mean,2.0);
	}
	standDev = sqrt(standDev / SIZE);
	cout << standDev << endl;
	
	
	
	
	
	
	return 0;
}