/*Nicholas Bright (nicholasbright@my.unt.edu)
10/12/20
shrestha
description:take a data file pick out users listed with gpa less than 3 and output into new file
*/
#include "my_header.h"
#include "mycopy.cpp"
int main(){
	
	ifstream in_s;
	ofstream ou_s;
	
	in_s.open("data.dat");
	ou_s.open("selected.dat");
	
	mycopy(in_s,ou_s);
	
	in_s.close();
	ou_s.close();
}
	
	