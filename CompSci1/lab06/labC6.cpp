/*Nicholas Bright (nicholasbright@my.unt.edu)
10/5/20
shrestha
description-
*/
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

int main(){
	
	const int ROWS = 3;
	const int COLS = 4;
	float sum = 0;
	float average=0;
	string names[ROWS] = {"John", "Sallie", "Mary"};
	int gradebook[ROWS][COLS]={{90, 40, 65, 80},{95, 93, 91, 88},{72, 57, 84, 91}};
	
	cout<<endl;
	for(int i=0; i<ROWS;++i){
		cout<<names[i]<<": ";
		for(int j=0; j<COLS;++j){
			cout<<gradebook[i][j];
			sum=sum+gradebook[i][j];
			if(j<(COLS-1)){
			cout<<", ";
			}
		}
		average=sum/COLS;
		cout<<"---Average="<<average<<endl;
		sum=0;
		average=0;
	}
	cout<<endl;
	
	
	
	return 0;
}