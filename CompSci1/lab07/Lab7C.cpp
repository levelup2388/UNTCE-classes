/*Nicholas Bright (nicholasbright@my.unt.edu)
10/12/20
shrestha
description:use a functions to determine whether a string is larger than the other outisde the main function
*/
#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include <stdio.h> 
using namespace std;
//statement to check is string is or isnt larger
bool isLarger(string str1, string str2)
{
	//variable declaration
	bool larger;
	int str1val=0;
	int str2val=0;
	//determines size of str1 and 2
	for(int i =0;i<str1.size();i++){
		str1val +=str1.at(i);
	}
	for(int j =0;j<str2.size();j++){
		str2val +=str2.at(j);
	}
	
	//if else comparing size
	if (str1val>str2val){
		larger=true;
	}
	else{
		larger=false;
	}
	
	return larger;
}
int main()
{
	//variable declaration
	string str1, str2;
	bool larger;
	//gathers strings and relates larger to is larger function
	cout<< "Enter 2 string:";
	cin >> str1; cin >> str2;
	larger=isLarger(str1, str2);
	//outputs if string 1 is larger or not
	if (larger)
	{
		cout<< "str1 has larger ASCII sum." << endl;
	}
	else
	{
		cout<< "str1 does not have larger ASCII sum." << endl;
	}
	
	return 0;
}