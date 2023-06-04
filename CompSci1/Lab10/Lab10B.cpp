/*Nicholas Bright (nicholasbright@my.unt.edu)
10/12/20
shrestha
description:use pointers to store values and calucate cos of soup with inflation
*/
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(){
	int qty = 2;
	int *qtyPtr = &qty;
	float *pricePtr = new float;
	
	cout << "qty=" << qty << " *qtrPtr=" << *qtyPtr << endl;
	cout << "&qty=" << &qty << " qtrPtr=" << qtyPtr << endl;
	
	*qtyPtr = qty + 3 ;
	cout << "qty=" << qty << " *qtrPtr=" << *qtyPtr << endl;
	
	cout << "Enter the price for a can of soup: ";
	cin  >> *pricePtr;
	
	cout << "*pricePtr=" << *pricePtr << endl;
	
	*pricePtr *= 1.05;
	cout << "At $" << *pricePtr << " each for inflation, 5 cans of soup cost $" << *qtyPtr**pricePtr << endl;
	
	delete pricePtr;
	delete qtyPtr;
	
	

	return 0;
}