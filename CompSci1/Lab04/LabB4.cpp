/* Nicholas Bright ( nicholasbright@my.unt.edu)
9/14/20
shrestha
description:User enters number of credit hours and program tells user if
they are a freshman,sophomore,junior,senior,or graduating senior.
*/
#include<iostream>
using namespace std;

int main()
{
	int CrH;
	int CrH_simp;

	cout<<"Enter the number of credit hours you have recived ";
	cin>>CrH;

	CrH_simp = CrH / 10;//credit hours put to single digit

	//case structure
	switch (CrH_simp){
		case 0:
		case 1:
		case 2:
			cout<<"You are a Freshman\n";
			break;
		case 3:
		case 4:
		case 5:
			cout<<"You are a Sophomore\n";
			break;
		case 6:
		case 7:
		case 8:
			cout<<"You are a Junior\n";
			break;
		case 9:
		case 10:
		case 11:
			cout<<"You are a Senior\n";
			break;
		default:
			cout<<"You are a Graduation Senior\n";
			break;
		}

	return 0;
}
