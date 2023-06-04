#include<iostream>
using namespace std;

int main()
{


	//variable declaration
	int my_int;
	float my_float;
	double my_dbl;
	char my_char;


	//assignment procces
	my_int=-30;
	my_float=-0.75;
	my_dbl=3.778;//double is more precise than float
	my_char='#';//any character but just one

	//initialization of variables
	int my_int2=35;//my_int2 initialized to 35
	char my_char2='9';

	int my_int3;
	char my_char3;

	cout<<"enter a integer:";cin>>my_int3;
	cout<<"Enter a character:"; cin>>my_char3;

	cout<<"Integer:"<<my_int3<<"\tCharacter:"<<my_char3<< endl;


	int my_int4=my_int*2 + my_int2 - my_int3*12;

	my_int=12;//variable update, only latest value assigned

	cout<<"my_int:"<<my_int<<endl;

	my_int=my_int+10;//my_int becomes 22
	my_int=my_int*3; //my_int becomes 66
	my_int=my_int-3;//my_int becomes 63


	my_int+=5;//same as my_int=my_int+5

	int x;

	//int xx;  //redeclaration of varables not allowed

	//you can only use value that match data type

	int _123test;//do not start with number
	//int cout//do not use reserved c++ code


	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);//controls how many decimals seen


	return 0;
}
