/* Nicholas Bright (nicholasbright@my.unt.edu)
9/10/20
shrestha
description: entering string names ,variable entry, and random  number genrator
and using those numbers in an equation to find the bounus you made
*/
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{

	//variable entry
	string name;
	double salary;
	int rate;
	double bonus;

	//randnumber
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	srand(time(0));
	rate= (rand () % 5)+1;
	cout<< "rate ="<<rate<<endl;
	//procces begin

	cout<<"Enter your name: \n";
	getline(cin, name);
	cout<<"Enter your salary: ";
	cin>> salary;
	bonus = salary * (static_cast<double>(rate)/100);
	cout<< name<<" earned a bonus of "<<bonus<<endl;






	return 0;
}
