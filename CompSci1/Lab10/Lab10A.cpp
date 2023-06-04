/*Nicholas Bright (nicholasbright@my.unt.edu)
10/12/20
shrestha
description:use structures to store the variables of the car
*/
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;
struct carStruct{
	string model;//cars model (ex: corolla, Mustand,etc)
	float tank_size;//size of gaas tank in gallons
	float mpg;    //miles per gallon of car
};
bool fillUpRequired(float, float, int);

int main(){
	carStruct car;
	/*string model;//cars model (ex: corolla, Mustand,etc)
	float tank_size;//size of gaas tank in gallons
	float mpg;    //miles per gallon of car*/
	int kilometers;//total distance of trip in Km
	
	cout << "Enter the car model: ";
	cin >> car.model;
	
	cout << "Enter the tank size of the " << car.model << " in gallons: ";
	cin >> car.tank_size;
	
	cout << "Enter the miles per gallon of the " << car.model << ": ";
	cin >> car.mpg;
	
	cout << "Enter the total kilometers of the planned trip: ";
	cin  >> kilometers;
	
	if ( fillUpRequired(car.tank_size, car.mpg, kilometers)){
		cout << "You will need to fill up your " << car.model;
		cout << " before you reach your destination." <<endl;
	}
	else{
		cout << "Your " << car.model << " can travel to your destination on one tank of gas.\n";
	}
	
	return 0;
}

bool fillUpRequired(float tank_size, float mpg, int kilometers){
	float capacityInMiles = tank_size * mpg;
	float tripMiles = kilometers * 0.621371;
	
	return (tripMiles > capacityInMiles);
}