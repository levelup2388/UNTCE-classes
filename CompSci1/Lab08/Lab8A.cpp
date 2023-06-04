/*Nicholas Bright (nicholasbright@my.unt.edu)
10/12/20
shrestha
description:using function gather grades and check if they need to be curved or not then add curve if nessccary
*/
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

const int PASS_GRD = 70;//int declared,,, functions declared
float get_grades(float& grd1, float& grd2);
float curve_grades(float& avg, float& grd1, float& grd2);

int main()
{
	float grd1, grd2, avg;//variable declaraton
	//get grades and output
	avg = get_grades(grd1, grd2);
	cout<< "grd1=" << grd1 << " grd2=" << grd2 << endl;
	//if statement if curve function needs to be used or not
	if (avg < PASS_GRD){
		curve_grades(avg, grd1, grd2);
	}
	else {
		cout<< "NO curve" << endl;
	}
	//output grades
	cout<< "grd1=" << grd1 << " grd2=" << grd2 << endl;
	
	return 0;
}
//curve grades function
float curve_grades(float& avg, float& grd1, float& grd2)
{
	avg = (grd1 + grd2) / 2;
	int curve = PASS_GRD - avg;
	grd1 = grd1 + curve;
	grd2 = grd2 + curve;
	return 0;
}
	//get grades function
float get_grades(float& grd1, float& grd2)
{
	cout << "Enter first grade: ";
	cin  >> grd1;
	
	cout << "Enter second grade: ";
	cin  >> grd2;
	
	return (grd1 + grd2) / 2;
}