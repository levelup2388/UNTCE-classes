/*Nicholas Bright (nicholasbright@my.unt.edu)
9/21/20
shrestha
description-*/
#include<iostream>
#include<string>
using namespace std;

int main()
{	//variable output
	int totalAlpha=0;
	int totalS=0;
	int totalDigit=0;
	int totalSpace=0;
	string usrStr;
	//get message
	cout<<"Type in a message:";
	getline(cin,usrStr);
	//checks message for digit,letter,whitespace, or special character
	for (int i = 0; i<usrStr.size(); i++){
		if(isdigit(usrStr.at(i))){
		totalDigit=totalDigit+1;
		}
		else if(isalpha(usrStr.at(i))){
		totalAlpha=totalAlpha+1;
		}
		else if(isspace(usrStr.at(i))){
		totalSpace=totalSpace+1;
		}
		else{
		totalS=totalS+1;
		}
	}
	//output statements
	//digit
	if(totalDigit>1)
		cout << "You have " << totalDigit << " digits in your message." << endl;

	else if(totalDigit==1)
		cout << "You have 1 digit in your message." << endl;

	else
		cout << "You have no digits"<<endl;

	//letters
	if(totalAlpha>1)
                cout << "You have " << totalAlpha << " letters in your message." << endl;

        else if(totalAlpha==1)
                cout << "You have 1 letter in your message." << endl;

        else
                cout << "You have no letters"<<endl;

	//whitespace
	if(totalSpace>1)
                cout << "You have " << totalSpace << " white spaces in your message." << endl;

        else if(totalSpace==1)
                cout << "You have 1 white space in your message." << endl;

        else
                cout << "You have no white spaces"<<endl;

	//special character
	if(totalS>1)
                cout << "You have " << totalS << " special characters in your message." << endl;

        else if(totalS==1)
                cout << "You have 1 special character in your message." << endl;

        else
                cout << "You have no special characters"<<endl;




	return 0;
}
