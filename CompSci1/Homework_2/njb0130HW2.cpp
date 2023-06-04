#include <iostream>
#include <ctime>
#include <string>
using namespace std;

int main()
{
	enum Service {GREETING =1, WEATHER, GAME, EXIT};

	//time integration
	time_t rawtime;
	string time_str;
	rawtime = time(&rawtime);
	time_str = ctime(&rawtime);
	int hour = stoi(time_str.substr(11,2));

	//variable declaration
	int choice;
	string Name;
	bool end;
	bool exit;
	end = false;
	exit = false;
	int weather;
	int rain;
	srand(time(0));
	int gameOpt;
	int guess;

	//title block
	cout << "+---------------------------------------------------+\n";
	cout << "|  	Computer Science and Engineering	    |\n";
	cout << "|	CSCE 1030 - Computer Science I	       	    |\n";
	cout << "| Nicholas Bright njb0130 nicholasbright@my.unt.edu |\n";
	cout << "+---------------------------------------------------+\n";
	cout << "Please enter your full name:";
	getline(cin,Name);
	cout << endl;

	cout << "+------------------MENU------------------+\n";
	cout << "|Peronal Concierge App: Choose a Service:|\n";  //service list
	cout << "|1. Display Personal Greeting            |\n";
	cout << "|2. Display Today’s Weather Forecast     |\n";
	cout << "|3. Play a Guessing Game                 |\n";
	cout << "|4. Exit                                 |\n";
	cout << "+----------------------------------------+\n";

	//begining of loop
	do{
		cout << "choose a service-" ; cin >> choice;
		Service my_service = static_cast<Service>(choice);

			do{
			switch(my_service){
				case 1://personal greeting
					cout << time_str;
					if((hour > 24) && (hour < 12)){
						cout << "Good Morning " << Name << "." << endl;
					}
					else if((hour >= 12) && (hour < 6)){
						cout << "Good Afternoon " << Name << "." << endl;
					}
					else {
						cout << "Good evening " << Name << "." << endl;
					}
					end = true;
					break;
				case 2://weather forecast
					cout << time_str;
					weather = (rand() %96) +10;
					rain = (rand() %2);
					if (rain == 0){
						cout << "It is rainy and " << weather << " degrees Farrenheit" << endl;
					}
					else if (rain==1){
						cout << "It is sunny and " << weather << " degrees Farrenheit" << endl;
					}
					end = true;
					break;
				case 3://guessing game
					cout << time_str << endl;
					gameOpt = 5;//(rand() %10) +1;
					cout << "Please guess a number between 1 and 10 number, you have 3 chances!\n";
					cout << "Guess #1: " ; cin >> guess;
					cout << endl;
						if(guess == gameOpt){
							cout << "Congrats you guessed the correct number, on your first try!\n";
						}
						else{
							cout << "Your guess is too ";
							if(gameOpt < guess){
								cout << "high! Guess a lower number.\n";
								cout << "Guess #2: "; cin >> guess;
								if(guess == gameOpt){
									cout << "Congrats you guessed the correct number, on your second try!\n";
								}
								else{
									cout << "Your guess is too ";
									if(gameOpt < guess){
										cout << "high! Guess a lower number.\n";
										cout << "Guess #3: "; cin >> guess;
										if(guess == gameOpt){
											cout << "You guessed correct the number was " << gameOpt << ".\n";
										}
										else{
											cout << "You guessed incorrect, the number was " << gameOpt << ".\n";
										}
									}
									else{
										cout << "low! Guess a higher number.\n";
										cout << "Guess #3: "; cin >> guess;
										if(guess == gameOpt){
											cout << "You guessed correct the number was " << gameOpt << ".\n";
										}
										else{
											cout << "You guessed incorrect, the number was " << gameOpt << ".\n";
										}
									}
								}
							}
							else{
								cout << "low! Guess a higher number.\n";
								cout << "Guess #2: ";cin>>guess;
								if(guess == gameOpt){
									cout << "Congrats you guessed the correct number, on your second try!\n";
								}
								else{
									cout << "Your guess is too ";
									if(gameOpt < guess){
										cout << "high! Guess a lower number.\n";
										cout << "Guess #3: "; cin >> guess;
										if(guess == gameOpt){
											cout << "You guessed correct the number was " << gameOpt << ".\n";
										}
										else{
											cout << "You guessed incorrect, the number was " << gameOpt << ".\n";
										}
									}
									else{
										cout << "low! Guess a higher number.\n";
										cout << "Guess #3: "; cin >> guess;
										if(guess == gameOpt){
											cout << "You guessed correct the number was " << gameOpt << ".\n";
										}
										else{
											cout << "You guessed incorrect, the number was " << gameOpt << ".\n";
										}
									}
								}
							}
						}
					end = true;
					break;
				case 4://exit
					cout << time_str << endl;
					cout << "Thank you , you are now exiting the program.GoodBye!\n";
					end = true;
					exit = true;
					break;
				default:
					cout << "Invalid option." << endl;
					break;
				}
			}while(end == false);
				cout << "+------------------MENU------------------+\n";
				cout << "|Peronal Concierge App: Choose a Service:|\n";  //service list
				cout << "|1. Display Personal Greeting            |\n";
				cout << "|2. Display Today’s Weather Forecast     |\n";
				cout << "|3. Play a Guessing Game                 |\n";
				cout << "|4. Exit                                 |\n";
				cout << "+----------------------------------------+\n";
	}while(exit == false);
	cout << endl;
	return 0;
}

