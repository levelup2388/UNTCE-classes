//Nicholas Bright (nicholasbright@my.unt.edu)
#include <stdio.h>


int main(){
	int mark = 0;									//initalize variables
	int size;
	int word = 0;
	char sent[100];
	char c;
	
	printf("input sentence: ");						// gathers sentence and reallocates size of c string
	scanf("%[^\n]", sent);
	for (size = 0; sent[size] != '\0'; ++size);		//gain size of sentence
	
	for(int i=0; i<size; i++){						//checks spaces and start of sentence to make uppercase and count words
		if(sent[i]== ' '){
			mark = 0;
		}
		else if((mark== 0) && (sent[i]!= ' ')){				//makes uppercase if needed
			if(sent[i]> 96){
				sent[i] =  sent[i] -32;//toupoper
			}
			word++;
			mark = 1;
		}
		else{}
	}
	
	printf("%s\n%i words\n", sent, word);//output


	return 0;
}