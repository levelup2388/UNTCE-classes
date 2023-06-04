#include <ctype.h>
#include <sys/types.h> 
#include <sys/socket.h> 
#include <string.h> 
#include <sys/un.h>
#include <sys/time.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

#define SOCKETNAME  "bitserv"

#define OP 1
#define BIT 2

void printbits(int bits) {
	printf("Bits: ");
	for(int i=31; i>=0; i--) {
		printf("%d",(bits&(1<<i)?1:0));
	}
	printf("\n");
}


int
main(void)
{
	int running = 1;
	int state = OP;
	
	char operation;
	int bit;
	
	int s;          /* This end of connection*/
	int len;        /* length of sockaddr */
	int nread;      /* return from read() */
	int nready;     /* # fd's ready. */
	int maxfd;      /* fd's 0 to maxfd-1 checked. */ 
	char buffer[1024];
	fd_set fds;     /* set of file descriptors to check. */
	struct sockaddr_un name;


	if( (s = socket(AF_UNIX, SOCK_STREAM, 0) ) < 0)
	{
		perror("socket");
		exit(1);
	}

	/*Create the address of the server.*/

	memset(&name, 0, sizeof(struct sockaddr_un));

	name.sun_family = AF_UNIX;
	strcpy(name.sun_path, SOCKETNAME);
	len = sizeof(name.sun_family) + strlen(name.sun_path);


	/*Connect to the server.*/

	if (connect(s, (struct sockaddr *) &name, len) < 0)
	{
		perror("connect");
		exit(1);
	}

	maxfd = s + 1;
	while(running)
	{
		// Prompt depending on our state
		switch (state) {
			case OP:
				printf("Valid Operations\n");
				printf("eXit\n");
				printf("Set\n");
				printf("Toggle\n");
				printf("Clear\n");
				
				printf("Operation: ");
				fflush(stdout);
				break;
			
			case BIT:
				printf("Bit: ");				
				fflush(stdout);
		}

		/* Set up polling. */
		FD_ZERO(&fds);
		FD_SET(s,&fds);
		FD_SET(0,&fds);

		/* Wait for some input. */
		nready = select(maxfd, &fds, (fd_set *) 0, (fd_set *) 0,
				(struct timeval *) 0);

		/* If either device has some input,
		   read it and copy it to the other. */

		if( FD_ISSET(s, &fds))
		{
			nread = recv(s, buffer, sizeof(buffer), 0);
			/* If error or eof, terminate. */
			if(nread < 1)
			{
				close(s);
				exit(0);
			}
			int* bitdata = (int*)buffer;
		    int bits = ntohl(*bitdata);
			printbits(bits);

			write(1, buffer, nread);
		}

		if( FD_ISSET(0, &fds))
		{
			switch (state) {
				case OP:			
					if(scanf(" %c", &operation)==EOF){
						running = 0;
					}
					else {
						operation = toupper(operation);
						if (operation=='X') {
							running = 0;
						}
						else {
							state = BIT;
						}
					}
					break;
					
				case BIT:
					if(scanf("%d", &bit)==EOF) {
						running = 0;
					}
					else {
						// Format and send data
						printf("op=%c bit=%d\n",OP,bit);
						
						// Rearange for network byte ordering
						buffer[0]=operation;
						int* data = (int*)(buffer+1);
						(*data) = htonl(bit);
						send( s, buffer, 5, 0); 
						state = OP;
					}
					break;
			}
		}
	} 
	close(s);
	exit(0);
}

