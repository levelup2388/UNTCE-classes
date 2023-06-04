/*Nicholas Bright (nicholasbright@my.unt.edu)
10/5/20
shrestha
description-given a string the program checks if its a palindrome or not
*/
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int main(){
	
	//declare variables
	string my_str;
	char reverse[21];
	int i, rev;
	string rev_str;
	//enters string
	cout << "Enter a string up to 20 characters long: ";
	cin >> my_str;
	//reverse string
	rev = my_str.length() -1;
	for(i=0; i<rev+1;i++){
		reverse[i]= my_str.at(rev-i);
		rev_str = rev_str + reverse[i];
	}
	reverse[rev + 1] = '\0';
	//checks if string is palindrome
	if(strcmp(my_str.c_str() , reverse)==0){
		cout << my_str << " is a palindrome" << endl;
	}
	else{
		cout << my_str << " and " << reverse << " are not the same" << endl;
	}
	
	
	
	
	
	
	return 0;
}