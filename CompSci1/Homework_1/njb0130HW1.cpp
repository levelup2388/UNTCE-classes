/*Nicholas Bright (nicholasbright@my.unt.edu)
9/17/20
shrestha
description- find the amount of energy needed to escape the planets
gravitaional pull*/

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
	//variable declaration
	double escapeVelocity;//escape velocity
	double massPlanet;//mass of planet
	double radiusPlanet;//radius of planet
	const double gravConst=6.67e-11;//gravitational constant
	double massObj;//mass of object
	double energyReq;//kinetic energy required to escape planet
	const double milesToMeters =1609.34;//miles to meter
	//title block
	cout<<"+---------------------------------------------------+\n";
	cout<<"|  	Computer Science and Engineering	    |\n";
	cout<<"|	CSCE 1030 - Computer Science I	       	    |\n";
	cout<<"| Nicholas Bright njb0130 nicholasbright@my.unt.edu |\n";
	cout<<"+---------------------------------------------------+\n";
	//entrance statements
	cout<<"Enter radius of the planet (in miles):";
	cin>>radiusPlanet;
	radiusPlanet=radiusPlanet*milesToMeters;//radius of planet in miles converted to meters
	cout<<"\nEnter mass of the planet (in kg):";
	cin>>massPlanet;
	escapeVelocity = sqrt ((2.0 * gravConst * massPlanet)/ radiusPlanet);//escape velocity equation
	cout<<"\nThe escape velocity of the planet is "<<escapeVelocity<<"meters per second.\n";
	cout<<"Enter mass of the object (in kg):";
	cin>>massObj;
	energyReq=(1.0/2.0) * massObj * (pow (escapeVelocity,2.0));//energy required equation
	cout<<"\nThe kinetic energy required by the object to escape the planet is "<<energyReq<<" Joules.\n";





	return 0;
}
