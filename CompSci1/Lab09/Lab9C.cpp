/*Nicholas Bright (nicholasbright@my.unt.edu)
10/12/20
shrestha
description:gets file and utputs the text
*/
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(){
	
	int num;
	ifstream in_s;
	ofstream ou_s;
	string output_file;
	string filename;
	cout << "Enter the name of the input file: ";
	cin >> filename;
	
	in_s.open(filename);//connect to the input file and test
	if (in_s.fail()){
		cout << "Unable to open input file " << filename << endl;
		exit (EXIT_FAILURE); //exit if cannot open file
	}
	
	cout << "Enter the name of the output file: ";
	cin >> output_file;
	ou_s.open(output_file);//connect to the input file and test

	
	int data[15];
	int eofNum = 0;
	while(in_s >> num){
				data[eofNum] = num;
				eofNum++;// only one I/O
	}
	int temp;
	for(int i=eofNum-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(data[j]> data[j+1]){
				temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
		}	
	}
	int p=0;
	while(p<eofNum){
		//cout<< data[p] <<endl;
		ou_s<< data[p] <<endl;
		p++;
	}
	
	in_s.close();
	ou_s.close();
	return 0;
}