//Nicholas Bright nicholasbright@my.unt.edu
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
int main(){
	pid_t p_id;//variable decleration 
	char input[100];
	int arrSize=1;
	int exit =1;
	
	while(exit==1){//while loop for code to run until quit
		scanf("%[^\n]", input);
		if (strcmp(input, "quit") == 0){//check if user type quit
			exit=0;
			break;
		}
		p_id = fork();//fork process
		if (p_id == 0){//if child process
			char *command;//variables for commands
			char *args[32];	
			char *cmd_token = strtok(input, " ");
			command = cmd_token;
			args[0] = cmd_token;

			while (1){// loop until all components of input are tokenized
				cmd_token = strtok(NULL, " ");// get the next token
				if (cmd_token == NULL){// check if token is null
				break;
				}
				args[arrSize] = cmd_token;// store the token in args
				arrSize++;//increment index/size
			}
			if (execvp(command, args) < 0 ){//run function and check output
				printf("%s: Command not found\n", args[0]);
			}
		}
		else{
			wait(NULL);//if parrent wait for child
		}
		getchar();//skip newline from code
	}
	return 0;
}