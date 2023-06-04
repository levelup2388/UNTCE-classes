/*Nicholas Bright (nicholasbright@my.unt.edu)
10/12/20
shrestha
description:given prices update the prices if the random number is 1 or not
*/
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

const int SIZE = 6;//size variable
//function declaration
void print_prices(const float prices[], int size);
void update_prices(float prices[],bool raise_price[],int SIZE);

int main(){
	//vriable declaration
	bool raise_price[SIZE];
	float prices[SIZE] = {4.25, 0.99, 3.29, 1.80, 2.19, 6.59};
	//degit precision
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	cout << "Original: ";
	//inputs print prices function
	print_prices(prices, SIZE);
	//randomizer
	srand(time(NULL));
	//relates aray to random 
	for (int i = 0;i < SIZE; i++){
		raise_price[i] = rand() % 2;
	}
	//update function
	update_prices(prices,raise_price,SIZE);
	
	cout<< "Updated : ";
	//prints final function
	print_prices(prices, SIZE);
	
	return 0;
}
//print function 
void print_prices(const float prices[], int size){
	for (int i = 0; i < size; i++){
		cout << "$" << prices[i] << " ";
	}
	cout << endl;
	
	return;
}
//update function
void update_prices(float prices[],bool raise_price[],int SIZE){
	for (int i = 0;i < SIZE; i++){
		if (raise_price[i]==true){
			prices[i]= prices[i]*1.10;
		}
		else{
			prices[i]= prices[i];
		}
	}
	return;
}