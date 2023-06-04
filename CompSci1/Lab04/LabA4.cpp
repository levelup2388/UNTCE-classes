/*Nicholas Bright (nicholasbright@my.unt.edu)
9/14/20
Shrestha
description:user inputs number of cookies they want and the program tells the
user the final cost with the discount.
*/
#include<iostream>
using namespace std;

int main()
{
	//variable declaration
	int num_cookies;
	int num_dozen;
	float total_cost;
	const float STANDARD_PRICE = 0.89;

	//enter cookies
	cout<<"Enter the number of cookies you would like: ";
	cin>> num_cookies;

	num_dozen= num_cookies / 12;//dozen calculation

	//if statements
	if ((num_dozen >= 1) && (num_dozen < 5)){
		total_cost = (0.9 * (num_cookies * 0.89));
	}
	else if (num_dozen >= 5){
		total_cost = (0.75 * (num_cookies * 0.89));
	}
	else {
		cout<<"The number you entered does not recive a discount\n";
	}
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout<<"Your total cost equals "<< total_cost<<".\n";



	return 0;
}
