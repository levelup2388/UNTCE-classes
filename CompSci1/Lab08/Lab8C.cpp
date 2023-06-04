/*Nicholas Bright (nicholasbright@my.unt.edu)
10/12/20
shrestha
description:using functions print 3 maticies with the 3 being matrix1 + matrix2
*/
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

const int COLS = 5;//colums declared
//print matrix function
void printMatrix(const int matrix[][COLS], int size, int number){
		cout << "MATRIX" << number << ":" << endl;
		for(int i = 0; i<size; i++){
			cout << "row " << i + 1 << ": ";
			for(int j = 0; j<COLS; j++){
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return;
}
//addmatrix function
void addMatrix(const int matrix1[][COLS], const int matrix2[][COLS], int matrix3[][COLS], int size){
		for(int i = 0; i<size; i++){	
			for(int j = 0; j<COLS; j++){
				matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
			}
		}
		return ;
}
int main(){
	//variable declaration
	const int ROWS = 3;
	int matrix1[ROWS][COLS];
	int matrix2[ROWS][COLS];
	int matrix3[ROWS][COLS];
	//delcarare array with randomizer
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLS; j++){
			matrix1[i][j] = (rand() % 11) + 10;
			matrix2[i][j] = (rand() % 16) + 25;
		}
	}
	//prints matrixes and adds 1 and 2 for matrix 3
	printMatrix(matrix1, ROWS, 1);
	printMatrix(matrix2, ROWS, 2);
	addMatrix(matrix1, matrix2, matrix3, ROWS);
	printMatrix(matrix3, ROWS, 3);
	return 0;
}
