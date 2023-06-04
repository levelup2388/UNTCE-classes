/*Nicholas Bright (nicholasbright@my.unt.edu)
9/21/20
shrestha
description-input 2 numbers and using enum ask for input of operation multipy divide or add
*/
#include<iostream>
using namespace std;

int main()
{
	enum Operation {Multiply='M', Add='A', Difference='D'};//the operations
	int result; //result of operation
	int num1, num2;//integers to perform operations on
	Operation my_operation;
	char choice;
	bool end;
	end=false;
	cout<<"Enter two integers:"; cin>>num1>>num2;
	do
	{
		cout<<"Enter letter for operation Multiply=M, Add=A , Diffference=D :";
		cin>> choice;
		Operation my_operation = static_cast<Operation>(choice);
		switch(my_operation)
		{
			case 'm':
			case 'M':
				result=num1 * num2;
				end=true;
				cout<<"The result of the operation is "<<result<< endl;
				break;
			case 'a':
			case 'A':
				result=num1 + num2;
				end=true;
				cout<<"The result of the operation is "<<result<< endl;
				break;
			case 'd':
			case 'D':
				result=num1 - num2;
				end=true;
				cout<<"The result of the operation is "<<result<< endl;
				break;
			default:
				cout<<"Please enter a valid option"<<endl;
				break;
			}
		}while(end==false);



	return 0;
}
