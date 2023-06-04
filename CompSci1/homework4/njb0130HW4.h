#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctype.h>
#include <stdlib.h>
#include <iomanip>
#include <ctime>
#include <stdio.h>
using namespace std;
void gameplay(int **gameboard,int army);
void gamesetup(int **gameboard);
char colCharFunct(int guessCol);
void boardDisplay(int** gameboard,int guessrow, int guessCol);
void lostboardDisplay(int** gameboard,int guessrow, int guessCol);