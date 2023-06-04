/*Nicholas Bright (nicholasbright@my.unt.edu)
9/21/20
shrestha
description-generate 2 numbers one between 1 and 10 and the other between
11 and 20. and add those numbers and all the numbers between.
*/
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{	//variable declare
	int num1;
	int ogNum1;//original number 1
	int num2;
	int sum;
	int final;
	//rand generate
	srand(time(0));
	num1 = (rand () % 11 +1);
	num2 = (rand () % 10 +11);
	final=num2;
	ogNum1=num1;
	//while program
	while(num1<num2){
	final=final+num1;
	num1=num1+1;
	}
	//output
	cout<<"Your first two numbers are:"<<ogNum1<<", "<<num2<<endl;
	cout<<"The sum of the numbers and those between is:"<<final<<endl;





	return 0;
}
