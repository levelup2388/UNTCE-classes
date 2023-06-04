#include "major2.h" //include header file

int main(int argc, char *argv[])
{
        //pid_t pid;
        char userIn[512];
        char exit = 'f';

        if (argc == 2) //if a file is specified on the command line
        {
                if (batchMode(argv[1]) == 0)
                        printf("major2.c: batchMode completed\n");
                else
                        return 1;
        }

        else if (argc > 2)
        {
                fprintf(stderr, "usage: ./shell [batchFile] (batchFile optional)\n");
                return 1;
        }

        while(exit == 'f')
        {
                fprintf(stdout, "prompt> \n");
                exit = 't';
        }

        return 1;
}
