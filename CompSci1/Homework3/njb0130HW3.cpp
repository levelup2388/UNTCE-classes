/*Nicholas Bright(nicholasbright@my.unt.edu)

*/
#include <iostream>
#include <ctime>
#include <string>
#include <stdio.h>

using namespace std;

const int MAX_LENGTH=15;

//declaring functions
string  fixName(string name);
int getCurrentHours_OR_Month(bool choiceTime);
void dispWeather();
void dispGreeting(string str);
void playGame();
void setTemp(int matrix[][MAX_LENGTH],int monthInt){
		srand(time(0));//random time
		int days;
		cout << "Compare with how many days? Choose a number less than 15:";
		cin >> days;
		//check if days to high or low
		while((days < 1)||(days > 15)){
			if(days > 15){
				cout << "You entered a number to high. Try again:";
				cin  >> days;
			}
			if(days < 1){
				cout << "You entered a number to low. Try again:";
				cin  >> days;
			}
		}
		//makes number for matrix 
		for(int i = 0; i < 12; i++){
			for(int j = 0;j < days;j++){
				switch(i){
					case 1:
						matrix[i][j] = (rand() % 19 + 37);
						break;
					case 2:
						matrix[i][j] = (rand() % 20 + 41);
						break;
					case 3:
						matrix[i][j] = (rand() % 20 + 49);
						break;
					case 4:
						matrix[i][j] = (rand() % 20 + 56);
						break;
					case 5:
						matrix[i][j] = (rand() % 19 + 65);
						break;
					case 6:
						matrix[i][j] = (rand() % 19 + 73);
						break;
					case 7:
						matrix[i][j] = (rand() % 19 + 77);
						break;
					case 8:
						matrix[i][j] = (rand() % 19 + 77);
						break;
					case 9:
						matrix[i][j] = (rand() % 20 + 69);
						break;
					case 10:
						matrix[i][j] = (rand() % 21 + 58);
						break;
					case 11:
						matrix[i][j] = (rand() % 20 + 47);
						break;
					default:
						matrix[i][j] = (rand() % 19 + 39);
						break;
					
				}
			}
		}
return ;
}	
string  fixName(string name){
	int check = 0;
	int i = 0;
	//checks name and makes first name upper case and rest lower
	while((name[i])&&(i < name.length())){  
        if(check == 0){
            name[i] = toupper(name[i]);    
            check = 1;
        }else if(isspace(name[i])){
            check = 0;
		}
		else{
			name[i] = tolower(name[i]);
		}
        i++;
    }
	return name;
}
int getCurrentHours_OR_Month(bool choiceTime){
	//time integration	
	time_t rawtime;
	string time_str;
	rawtime = time(&rawtime);
	time_str = ctime(&rawtime);
	string monthNam = "0";
	int HrsMnthInt = 0;
	//chooses hour or month
	if(choiceTime == true){
		HrsMnthInt = stoi(time_str.substr(11,2));
	}
	else {
		//relates moth to number
		if(isspace(time_str.at(4))){
			monthNam = time_str.substr(5,3);
		}
		else{
			monthNam = time_str.substr(4,3);
		}
		if(monthNam == "Jan"){HrsMnthInt=1;}
		else if(monthNam == "Feb"){HrsMnthInt=2;}
		else if(monthNam == "Mar"){HrsMnthInt=3;}
		else if(monthNam == "Apr"){HrsMnthInt=4;}
		else if(monthNam == "May"){HrsMnthInt=5;}
		else if(monthNam == "Jun"){HrsMnthInt=6;}
		else if(monthNam == "Jul"){HrsMnthInt=7;}
		else if(monthNam == "Aug"){HrsMnthInt=8;}
		else if(monthNam == "Sep"){HrsMnthInt=9;}
		else if(monthNam == "Oct"){HrsMnthInt=10;}
		else if(monthNam == "Nov"){HrsMnthInt=11;}
		else {HrsMnthInt=12;}
	}
	return HrsMnthInt;
}
void dispWeather(){
	//time integration
	time_t rawtime;
	string time_str;
	rawtime = time(&rawtime);
	time_str = ctime(&rawtime);
	//variable declaration
	bool choiceTime;
	choiceTime=false;
	int dayTemp;
	float sum = 0.0;
	float avgTemp;
	int monthInt = getCurrentHours_OR_Month(choiceTime);
	int matrix[12][MAX_LENGTH];
	float days=0;
	cout << "Enter todays temperature:";
	cin  >> dayTemp;
	//relates temp to month
	setTemp(matrix,monthInt);
	cout<<time_str;
	for(int j=0;j<MAX_LENGTH;j++){
		if((matrix[1][j]>0)&&(matrix[1][j]<100)){
			days++;
		}
		else{
			j=MAX_LENGTH;
		}
	}//finds sum
	for(int i=0;i<days;i++){
		sum = sum + matrix[monthInt][i];
	}
	//finds average and outputs correctly
	avgTemp=sum/days;
	cout<<"Random "<<days<<" days average is:"<<avgTemp<<endl;
	if(dayTemp>avgTemp+5){
		cout<< "It is hotter than usual\n";
	}
	else if (dayTemp<avgTemp-5){
		cout << "Its colder than usual\n";
	}
	else{
		cout << "The temperature is normal\n";
	}
	return;
}
void dispGreeting(string str){
	bool choiceHrsMnth;
	int hour=getCurrentHours_OR_Month(choiceHrsMnth=false);
	string Name=fixName(str);
	//uses name and outputs correctly
	if((hour > 24) && (hour < 12)){
		cout << "Good Morning " << Name << "." << endl;
	}
	else if((hour >= 12) && (hour < 6)){
		cout << "Good Afternoon " << Name << "." << endl;
	}
	else {
		cout << "Good evening " << Name << "." << endl;
	}
	return;
}
void playGame(){
	int guess[5];
	for(int j=0;j<5;j++){
		guess[j]=0;
	}
	int gameOpt = (rand() %20) + 1;
	cout << "Please guess a number between 1 and 20 number, you have 5 chances!\n";
	cout << "Guess #1: " ; cin >> guess[0];
	int guessNum=5;
	//checks if eachj guess is equal to solution
	for(int i=0;i<guessNum;i++){
		if((guess[i]<=20)&&(guess[i]>=1)){
			if((i<(guessNum-1))&&(guess[i] != gameOpt)){
				if(guess[i] < gameOpt){
					cout << "Your guess is lower than the number. Try again:";
				}
				else {
					cout << "Your guess is higher than the number. Try again:";
				}
				if((i<(guessNum-1))&&(guess[i] != gameOpt)){
					cin >> guess[i+1];
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
			cin >> guess[i+1];
		}
	}
	cout<<endl;
}
int main()
{
	//time integration	
	time_t rawtime;
	string time_str;
	rawtime = time(&rawtime);
	time_str = ctime(&rawtime);
	//variable declaration
	enum Service {GREETING =1, WEATHER, GAME, EXIT};
	bool choiceTime;
	int opt;
	string Name;
	bool end;
	bool exit;
	end = false;
	exit = false;
	bool choiceHrsMnth;
	int weather;
	int rain;
	srand(time(NULL));
	int gameOpt;
	int guess;
	int choice;

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
					cout<<time_str;
					dispGreeting(Name);
					cout<<endl;
					end = true;
					break;
				case 2://weather forecast
					dispWeather();
					cout<<endl;
					end = true;
					break;
				case 3://guessing game
					playGame();
					end = true;
					break;
				case 4://exit
					cout << time_str;
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
	//*/
	return 0;
}
