/*Nicholas Bright (nicholasbright@my.unt.edu)
10/12/20
shrestha
description:use functions to compute the bonus outisde of the main function
*/
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

double compute_bonus(double base_salary, int experience);

int main(){
	//variable declaration
	double base_salary;
	int experience;
	//enters variables
	cout<< "Please enter your base salary:";
	cin >> base_salary;
	cout << "Please enter your experience:";
	cin >> experience;
	//enters function to check bonus
	double compute_bonus(double base_salary, int experience);
	cout<< "Your recived a bonus of " << compute_bonus(base_salary,experience) <<endl;
	
	return 0;
}
	//funtion compute the bonus
double compute_bonus(double base_salary, int experience)
{
	double bonus;
	if(experience<=15){
		bonus=.025;
	}
	else{
		bonus=.05;
	}
	
	return base_salary*bonus;
}
	