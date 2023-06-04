#include <iostream>
#include <ctime>
#include <string>
using namespace std;

int main()
{
	enum Service {GREETING=1, WEATHER, GAME, EXIT};
	
	//time integration
	time_t rawtime;
	string time_str;
	rawtime = time(&rawtime);
	time_str = ctime(&rawtime);
	int hour = stoi(time_str.substr(11,2));
	cout << time_str;
	cout<<endl<<hour;
	
	//variable declaration
	int choice;
	string Name;
	Service my_service;
	bool end;
	end=false;
	int weather;
	int rain;
	srand(time(0));
	int gameOpt;
	
	//title block
	cout<<"+---------------------------------------------------+\n";
	cout<<"|  	Computer Science and Engineering	    |\n";
	cout<<"|	CSCE 1030 - Computer Science I	       	    |\n";
	cout<<"| Nicholas Bright njb0130 nicholasbright@my.unt.edu |\n";
	cout<<"+---------------------------------------------------+\n\n";
	cout<< "Please enter your full name:";
	cin>>Name;
	
	//begining of code
	while(end==false){
		cout<<"Peronal Concierge App: Choose a Service:\n\n";  //service list
		cout<<"1. Display Personal Greeting\n";
		cout<<"2. Display Today’s Weather Forecast\n";
		cout<<"3. Play a Guessing Game\n";
		cout<<"4. Exit\n";
		
		cin>>choice;
		Service my_service = static_cast<Service>(choice);
			switch(my_service){
				case 1:
					if((hour>24)&&(hour<12){
						cout<<"Good Morning"<<name<<endl;
					}
					else if((hour>=12)&&(hour<6){
						cout<<"Good Afternoon"<<name<<endl;
					}
					else {
						cout<<"Good evening"<<name<<endl;
					}
					end=true;
					break;
				case 2:
					weather = (rand() %96) +10;
					rain = (rand() %2);
					if (rain==0){
						cout<<"It is rainy and "<<weather<<" degrees Farrenheit<<endl;
					}
					else if (rain==1){
						cout<<"It is sunny and "<<weather<<" degrees Farrenheit<<endl;
					}
					end=true;
					break;
				case 3:
					gameOpt = (rand() %10) +1;
					cout<<"Please guess a number between 1 and 10 number:";
					cin>>guess;
					cout<<endl;
						if(guess==gameOpt){
							cout<<"Congrats you guessed the correct number, on your first try\n";
						}
						else{
							cout<<"You guessed incorect. HINT-";
								if(gameOpt>5){
									cout<<"The number is greater than 5\n";
								}
								else{
									cout<<"The number is less than or equal 5\n";
								}
						cout<<"Please guess again:";
						cin>>guess;
						cout<<endl;
						if(guess==gameOpt){
							cout<<"Congrats you guessed the correct number, on your second try\n";
						}
						else{
							cout<<"You guessed incorect. HINT-";
								if(gameOpt<3){
									cout<<"The number is less than 3\n";
								}
								if((gameOpt>=3)&&(gameOpt<6){
									cout<<"The number is greater than or equal to 3 and less than 6\n";
								}
								if((gameOpt>=6)&&(gameOpt<8)){
									cout<<"The number is greater than or equal to 6 and less than 8\n";
								}
								else{
									cout<<"The number is greater than or equal to 8\n";
								}
						}
					end=true;
					break;
				case 4:
					cout<<"Thank you , you are now exiting the program.GoodBye!";
					end=true;
					break;
				default:
					break;
			}
	}
	return 0;
}

