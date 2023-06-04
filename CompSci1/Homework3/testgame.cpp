#include <iostream>
#include <ctime>
#include <string>
#include <stdio.h>

using namespace std;

int main(){
	int guess[5];
	for(int j=0;j<5;j++){
		guess[j]=0;
	}
	int gameOpt = (rand() %20) + 1;
	cout << "Please guess a number between 1 and 20 number, you have 5 chances!\n";
	int guessNum=5;
	for(int i=1;i<=guessNum;i++){
		cout<<"Guess#"<<i<<":";
		cin >> guess[i];
		if((guess[i]<21)&&(guess[i]>0)){
			if(guess[i] == !guess[i]){
				cout<<"You have already guessed this number. Try again:\n";
			}
			else{
				if(guess[i]==gameOpt){
					cout<<"You guess correctly on try #"<<i<<"congrats"<<endl;
					i=guessNum+1;
				}
				else{
					if(guess[i]<gameOpt){
						cout<<"You guessed too low. Try again:"<<endl;
					}
					else{
						cout<<"You guessed too high. Try again:"<<endl;
					}
				}
			}
		}
		else{
			cout<<"Invalid input. Try again:"<<endl;
		}
		/*
		if((guess[i]<=20)&&(guess[i]>=1)){
			if((i<(guessNum-1))&&(guess[i] != gameOpt)){
				if(guess[i] < gameOpt){
					cout << "Your guess is lower than the number. Try again:";
				}
				else {
					cout << "Your guess is higher than the number. Try again:";
				}
				if((i<(guessNum-1))&&(guess[i] != gameOpt)){
					//cin >> guess[i+1];
				}
				else{
					i=guessNum;
				}
			}
			else if(guess[i] == gameOpt){
				cout << "Congrats you guessed the correct number!\n";
				i=guessNum;
			}
			else{
				cout<< "You did not guess the number.";
			}
		}
		else{
			cout<<"Invalid guess. Try again:";
			//cin >> guess[i+1];
		}
	}*/
	//cout<<endl<<"Guess#"<<i<<":"
	//cin >> guess[i+1];
	//cout<<endl;
	}
	return 0;
}