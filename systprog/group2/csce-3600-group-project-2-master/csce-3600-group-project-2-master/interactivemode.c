#include "major2.h"
int main(){
	pid_t p_id;//variable decleration 
	char input[100];
	int arrSize=1;
	int exit =1;
	char prompt[10]=">";
	
		
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
				fprintf(stderr,"Command not found\n");
			}
		}
		else{
			wait(NULL);//if parrent wait for child
		}
		getchar();//skip newline from code
	}
	return 0;
}
