#include "major2.h"

int batchMode(char *file)
{

        pid_t pid;

        if (access(file, R_OK) == 0 && access(file, X_OK) == 0) //if file is readable and executable
        {
                printf("Starting bash:\n");

                pid = fork();

                if (pid == 0) //if child
                {
                        execlp("bash", "bash", "-v", file, NULL);
                        fprintf(stderr, "execlp failed\n");
                        exit(0);
                }

                else //if parent
                {
                        wait( (int *)0 ); //wait on child
                }

                //execlp("bash", "bash", "-v", file, NULL);
        }

        else
        {
                fprintf(stderr, "The batch file does not exist or cannot be opened\n");
                return 1;
        }

        printf("batchMode.c: done\n");
        return 0;
}
