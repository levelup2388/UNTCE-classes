#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

	char *name;
	pid_t pid=fork();
	
	if( pid == 0 ){
		// child
		printf("child: %d started\n",getpid() );
		printf("child:  parent  =  %d\n" , getppid());
		printf("child: ...");
		sleep(20);
	}
	else if( pid>0){
		// parent
		 printf("parent: %d started\n",getpid());
		 printf("parent: parent = %d\n",getppid());
	}
	else{
		perror("fork error");
		exit(1);
	}
	
	name = (pid==0) ? "child" : "parent";
	printf("%s: terminating...\n",name);
	
	return 0;
}