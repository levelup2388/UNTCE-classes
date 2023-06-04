//Nicholas Bright nicholasbright@my.unt.edu
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdbool.h>

int exit(char userIn[512]){
    char exit[4] = "exit";
 
    bool isPresent = false;
    for (int i = 0; userIn[i] != '\0'; i++) {
        isPresent = false;
        for (int j = 0; exit[j] != '\0'; j++) {
            if (userIn[i + j] != exit[j]) {
                isPresent = false;
                break;
            }
            isPresent = true;
        }
        if (isPresent) {
            break;
        }
    }
	if(isPresent){
		kill();
	}

	return 0;
}