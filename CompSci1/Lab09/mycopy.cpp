#include "my_header.h"
void mycopy(istream& in_s, ostream& output){
	string firstName = "";
	string lastName = "";
	int last=1;
	float gpa;
	char c;
	int idNum;
	
	while(!in_s.eof()){
		in_s >> firstName >> lastName >> gpa >> idNum;
		if(gpa<3.0){
			output << setw(10) << firstName;
			output << setw(10) << lastName;
			output << setw(5) << right << fixed << setprecision(1) << gpa;
			output << setw(5) << right << idNum << endl;
		}
	}
}