/*Nicholas Bright (nicholasbright@my.unt.edu
9/14/20
shrestha
description:the user plays a color guessing game with the computer
*/
#include<iostream>
using namespace std;

int main()
{
	enum Colors {RED=0, ORANGE, YELLOW, GREEN, BLUE, PURPLE};
	srand(time(NULL));
	Colors my_color=static_cast<Colors>(rand() % 6);
	int guess;

	//guess input
	cout << "Can you guess my favorite color?" << endl;
	cout << "Enter 0=RED, 1=ORANGE, 2=YELLOW, 3=GREEN, 4=BLUE, 5=PURPLE: ";
	cin  >> guess;
	//if else rigt or wrong
	if ( my_color == guess){
		cout << "Correct! My color is ";
	}
	else{
		cout << "Sorry, my color is ";
	}
	//color input
	switch (my_color){
		case RED:
			cout << "red";
			break;
		case ORANGE:
			cout << "orange";
			break;
		case YELLOW:
			cout << "yellow";
			break;
		case GREEN:
			cout << "green";
			break;
		case BLUE:
			cout << "blue";
			break;
		default://PURPLE
			cout << "purple";
			break;
	}

	cout << "." << endl;

	return 0;
}
