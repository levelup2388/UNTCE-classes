#include "njb0130HW4func.cpp.cpp"
#include "njb0130HW4.h"
 int main(){
	 
	
	titleBlock();
	
	int ROWS = 3;
	srand(time(NULL));
	int **gameboard;
	gameboard = (int**)malloc(sizeof(int)*(ROWS * COLS));
	
	
	for (int i=0;i<3;i++){
		gameboard[i] = new int [COLS];
	}
	
	int army = rand()%11+15;
	
	cout<< "Let's Begin! Anthony's army is " << army << " strong!\n";
	cout
	<<"      A  B  C  D  E  F  G  H  I  J\n"
	<<"   +-------------------------------+\n"
	<<" 0 | -- -- -- -- -- -- -- -- -- -- |\n"
	<<" 1 | -- -- -- -- -- -- -- -- -- -- |\n"
	<<" 2 | -- -- -- -- -- -- -- -- -- -- |\n"
	<<"   +-------------------------------+\n"
	;
	
	
	gamesetup(gameboard);
	gameplay(gameboard,army);
	
	
	for(int i=0;i<3;i++){
		delete[] gameboard[i];
	}
	
	cout<<"done\n";
	delete[] gameboard;
	cout<<"done.\n";
	free( *gameboard);
	cout<<"done...\n";
	free( gameboard);
	cout<<"done....\n";
	return 0;
 }