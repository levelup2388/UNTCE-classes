/*Nicholas Bright (nicholasbright@my.unt.edu)
10/12/20
shrestha
description:use function to play a guessing game
*/
#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include <stdio.h> 
using namespace std;


	//function for random number
	int getRandom(){
			srand(time(NULL));
			return (rand() % 100 + 1);
	}
	//compares random number and outputs wheater it is equal less than or equal to
	void compare(int guess)
	{
		getRandom();
		if(guess == getRandom()){
			cout << "The random number was " << getRandom() << endl;
			cout << "Your guess was equal to the random number!";
		}
		else if(guess < getRandom()){
			cout << "The random number was " << getRandom() << endl;
			cout << "Your guess was less than the random number!";
		}
		else{
			cout << "The random number was " << getRandom() << endl;
			cout << "Your guess was greater than the random number!";
		}
	}
	//main funtion gathers guess and then carrys in compare funtion to check if guess is equal
	int main(){
		int guess;
		cout << "Please enter a guess between 1 and 100 inclusive:";
		cin >> guess;
		compare(guess);
		cout<<endl;
	return 0;
	}
	
	
	

