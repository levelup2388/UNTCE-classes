//Nicholas Bright nicholasbright@my.unt.edu
#include <stdio.h> 
#include <string.h> 
#include <pthread.h> 
#define SIZE 50 

char sentence[2000]; 
int  ind = 0;  
pthread_mutex_t lock;

char convertUppercase(char lower) { 
	//Converts lowercase un uppercase 
	if ((lower > 96) && (lower < 123) ) { 
		return (lower - 32); 
	} 
	else { 
		return lower; 
	} 
} 

void printChar() { 
	//prints the converted sentence 
	printf("The new sentence is [%d]: \t%c\n", ind, sentence[ind]); 
	ind++; 
} 

void *convertMessage(void *ptr) { 
	// Function that each threads initiates its execution 
	pthread_mutex_lock(&lock);
	if (ind % 2) { 
		sentence[ind] = convertUppercase(sentence[ind]); 
	} 
	printChar(); 
	pthread_mutex_unlock(&lock);
	return 0; 
} 
int main() { 
	int i; 
	char buffer[SIZE]; 
	char *p; 
	pthread_t ts[SIZE]; // define up to 50 threads 

	printf("Please enter a phrase (less than 50 characters): ");  
	if (fgets(buffer, sizeof(buffer), stdin) != NULL) { 
		if ((p = strchr(buffer, '\n')) != NULL) { 
			*p = '\0'; 
		} 
	} 

	strcpy(sentence, buffer); // copy string to char array  
	printf("The original sentence is: \t %s\n", sentence); 
	if((pthread_mutex_init(&lock,NULL))!=0){
		printf("Mutex init failed \n");
	}
	// create one thread for each character on the input word 
	for (i = 0; i < strlen(buffer) + 1; ++i) { 
		pthread_create(&ts[i], NULL, convertMessage, NULL); 
	} 
	// we wait until all threads finish execution 
	for (i = 0; i < strlen(buffer); i++) { 
		pthread_join(ts[i], NULL); 
	} 
	printf("\n"); 
	if((pthread_mutex_destroy(&lock))!=0){
		printf("Mutex destory error\n");
	}
	return 0; 
} //when all else fails read the instructions