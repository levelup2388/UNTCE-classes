#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctype.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int main(){

	ifstream input;
	ofstream output;
	
	input.open("data.dat");
	output.open("selected.dat");
	
	input.close();
	output.close();
	
	return 0;
	
}
	