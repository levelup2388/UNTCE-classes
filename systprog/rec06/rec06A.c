#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

	pid_t pid;
	pid = fork();

	if( pid == 0 ){
		// child
		exit(1);
	}
	else if( pid>0){
		// parent
		sleep(5);
		system("ps -e -o pid,ppid,stat,user,cmd | grep $USER");
	}
	else{
		perror("fork error");
		exit(1);
	}
	
	return 0;
}