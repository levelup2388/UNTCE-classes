#include "njb0130HW4.h"

const int COLS=10;
void titleBlock(){
	//title block
	cout << "+---------------------------------------------------+\n";
	cout << "|---------Computer Science and Engineering----------|\n";
	cout << "|----------CSCE 1030 - Computer Science I-----------|\n";
	cout << "|-Nicholas Bright njb0130 nicholasbright@my.unt.edu-|\n";
	cout << "+---------------------------------------------------+\n";
	return ;
}
void gameplay(int **gameboard,int army){
	
	bool won=false;
	int guessCol=0;
	int guessrow;
	int armyRow=0;
	int temp=0;
	char colChar;
	while((army>0)||(won==false)){
		armyRow=0;
		for(int i=0;i<3;i++){
			armyRow=armyRow + gameboard[i][guessCol];
		}
		armyRow=armyRow-81;
		while(guessCol==temp){
			if((guessCol>9)&&(army>=0)){
				guessCol=temp;
				cout<< "Congratulations! Anthony the Ant is victorious with an army of "<< army << " remaining!\n";
				guessCol=temp+1;
			}
			colChar=colCharFunct(guessCol);
			cout << "Enter row position in column "<< colChar<<" to strike: ";
			cin  >> guessrow;
			
			if((guessrow>=3)||(guessrow<0)||(gameboard[guessrow][guessCol]==13)){
				cout<< "Invalid row (" << guessrow << ") entered. Try Again.\n";
			}
			else{
				if(gameboard[guessrow][guessCol]==81){
					if(armyRow>0){
					army+=armyRow;
					}
					else{
						armyRow=0;
					}
					cout<<"Queen found! Anthony's army captured " <<armyRow<<" and is now "<<army<<" ants strong!\n";
					gameboard[guessrow][guessCol]=12;
					for(int i=0;i<3;i++){
						if((gameboard[i][guessCol]==13)||(gameboard[i][guessCol]==12)){
						}
						else{
							gameboard[i][guessCol]=11;
						}
					}
					boardDisplay(gameboard,guessrow, guessCol);
					guessCol++;
					
				}
				else{
					army-=gameboard[guessrow][guessCol];
					armyRow-=gameboard[guessrow][guessCol];
					cout<<"Anthony's army lost "<<gameboard[guessrow][guessCol]<<" and now has "<<army<<" ants remaining!\n";
					gameboard[guessrow][guessCol]=13;
					
					boardDisplay(gameboard,guessrow, guessCol);	
					
				}
			}
			if(army<1){
				guessCol=temp;
			}
			if(army<0){
			cout<< "Sorry, but Anthony's army has been defeated!\n";
			lostboardDisplay(gameboard,guessrow, guessCol);
			won=true;
			guessCol=temp+1;
			}
		}
		temp++;
		
		if((guessCol>9)&&(army>=0)){
			won=true;
		}
	}
	return;
}
void gamesetup(int **gameboard){
	for(int i=0;i<COLS;i++){
		gameboard[rand()% 3][i]= 'Q';
		for(int j =0;j<3;j++){
			if(gameboard[j][i] !='Q'){
				gameboard[j][i] =rand()%10+1;
			}
		}
	}
	return;
}
char colCharFunct(int guessCol){
	switch(guessCol){
		case 0:
			return 'A';
			break;
		case 1:
			return 'B';
			break;
		case 2:
			return 'C';
			break;
		case 3:
			return 'D';
			break;
		case 4:
			return 'E';
			break;
		case 5:
			return 'F';
			break;
		case 6:
			return 'G';
			break;
		case 7:
			return 'H';
			break;
		case 8:
			return 'I';
			break;
		default:
			return 'J';
			break;
	}
	return 'A';
}
			
void boardDisplay(int** gameboard,int guessrow, int guessCol){
	cout
	<<"   A  B  C  D  E  F  G  H  I  J\n"
	<<"+-------------------------------+\n";
	for(int i=0;i<3;i++){
		cout<< i << "| ";
		for(int j = 0;j<COLS;j++){
			switch(gameboard[i][j]){
				case 11:
					cout<<"* ";
					break;
				case 12:
					cout<<"A ";
					break;
				case 13:
					cout<<"X ";
					break;
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
				case 6:
				case 7:
				case 8:
				case 9:
				case 10:
				case 81:
					cout<<"--";
					break;
			}
			cout<<" ";
		}
		cout<< " |\n";
	}
	cout<<"+-------------------------------+\n";
	return;
}
void lostboardDisplay(int** gameboard,int guessrow, int guessCol){
	cout
	<<"   A  B  C  D  E  F  G  H  I  J\n"
	<<"+-------------------------------+\n";
	for(int i=0;i<3;i++){
		cout<< i << "| ";
		for(int j = 0;j<COLS;j++){
			switch(gameboard[i][j]){
				case 11:
					cout<<"* ";
					break;
				case 12:
					cout<<"A ";
					break;
				case 13:
					cout<<"X ";
					break;
				case 1:
					cout<<"1 ";
					break;
				case 2:
					cout<<"2 ";
					break;
				case 3:
				cout<<"3 ";
					break;
				case 4:
				cout<<"4 ";
					break;
				case 5:
				cout<<"5 ";
					break;
				case 6:
				cout<<"6 ";
					break;
				case 7:
				cout<<"7 ";
					break;
				case 8:
				cout<<"8 ";
					break;
				case 9:
				cout<<"9 ";
					break;
				case 10:
				cout<<"10 ";
					break;
				case 81:
					cout<<"Q ";
					break;
			}
			cout<<" ";
		}
		cout<< " |\n";
	}
	cout<<"+-------------------------------+\n";
	return;
}