/*Nicholas Bright (nicholasbright@my.unt.edu)
10/12/20
shrestha
description:gets file and outputs the text
*/
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(){
	char c;
	ifstream in_s;
	ifstream ou_s;//declaration of the stream of type input
	
	char input_file[15];
	cout << "Enter the name of the input file: ";
	cin >> input_file;
	
	in_s.open(input_file);//connect to the input file and test
	if (in_s.fail()){
		cout << "Unable to open input file " << input_file << endl;
		exit (EXIT_FAILURE); //exit if cannot open file
	}
	
	cout << "Enter the name of the output file: ";
	cin >> output_file;
	ou_s.open(output_file);//connect to the input file and test
	if (in_s.fail()){
		cout << "Unable to open output file " << input_file << endl;
		exit (EXIT_FAILURE); //exit if cannot open file
	}
	
	cout << "*** HERE are the contents of the input file ***" << endl;
	
	//read all characters one-by-one to end of file
	while(!in_s.eof()){
		in_s.get(c);
		ou_s.get(c);
		cout<<c;
		
	}

	cout << endl << "*** Done writing the contents of the file ***" << endl;
	
	in_s.close();
	ou_s.close();	//close file
	
	return 0;
}