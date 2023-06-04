/*Nicholas Bright (nicholasbright@my.unt.edu)
1/23/21
keathly
description:gets employes names and customer name and acoount balnce and output transactction list
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
using namespace std;

struct employees{//structure stores employee informataion
	string name[50];
	int num;
};

struct customer{//stores customer information
	string name[50];
	float bal[50];
	int num;
};

int main(){
	//relates id to structure
	employees eID;
	customer cID;
	//variable declaration
	int empCount = 0;
	int custCount = 0;
	int idnum;
	float amountTrans;
	char type;
	char c;
	
	cout << "123456789012345678901234567890123456789012345678901234567890\n";//allignment line
	//start of loop grabs first character and check what kind of information is on line
	while(cin >> c){
		if(c == 'e'){//sorts employee data given
			cin >> eID.num;
			cin >> eID.name[eID.num];
			empCount++;
		}
		else if(c == 'c'){//sorts customer data given
			cin >> cID.num;
			cin >> cID.name[cID.num];
			cin >> cID.bal[cID.num];
			custCount++;
		}
		else if(c == 't'){//grabs transaction data and outputs transaction data
			cin >> cID.num >> eID.num >> type >> amountTrans;
			cout << setw(15) << cID.name[cID.num] << setw(16) << eID.name[eID.num] << " ";
			if(type == 'w'){//for withdraw
				cout << "-$" << setw(7) << amountTrans << " $";
				cID.bal[cID.num] -= amountTrans;
			}
			else if(type == 'd'){//for deposit
				cout << "+$" << setw(7) << amountTrans << " $";
				cID.bal[cID.num] += amountTrans;
			}
			else{}
			cout << setprecision(2) << fixed;
			cout << setw(9) << cID.bal[cID.num];
			cout << endl;
		}
		else{}
	}
	
	return 0;
}