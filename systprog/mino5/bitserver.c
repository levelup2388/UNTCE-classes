/* This program sets up a socket to allow two clients to talk to each other */
#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h> 
#include <sys/un.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <netinet/in.h>

#define SOCKETNAME  "bitserv"

int
main(void)
{
	char operation;
	int bit;
	short bits = 0;
	
	char buffer[1024];		          /* Buffer for messages to others. */
	char msg[1024];
	int s;                          /* Listen socket */
	int ns;                         /* Socket for first connection. */
	int ns2;                        /* Socket for second connection. */
	int len;                        /* len of sockaddr */   
	int maxfd;                      /* descriptors up to maxfd-1 polled*/
	int nread;                      /* # chars on read()*/
	int nready;                     /* # descriptors ready. */
	struct sockaddr_un name;
	fd_set fds;                     /* Set of file descriptors to poll*/

	/* Remove any previous socket.*/
	unlink(SOCKETNAME);

	/* Create the socket. */

	if ((s = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)
	{
		perror("socket");
		exit(EXIT_FAILURE);
	 }

	/* Create the address of the server.*/

	memset(&name, 0, sizeof(struct sockaddr_un));

	name.sun_family = AF_UNIX;
	strcpy(name.sun_path, SOCKETNAME);
	len = sizeof(name.sun_family) + strlen(name.sun_path);

	/* Bind the socket to the address.*/

	if (bind(s, (struct sockaddr *) &name, len) < 0)
	{
		perror("bind");
		exit(EXIT_FAILURE);
	}
	
	/* Listen for connections. */
	if (listen(s, 5) < 0)
	{
		perror( "listen");
		exit(1);
	}


	/* Accept a connection.*/
	if ((ns = accept(s, (struct sockaddr *) &name, &len)) < 0)
	{
		perror("accept");
		exit(1);
	}

	
	maxfd = ns + 1;
	while (1)
	{
		/* Set up polling using select. */
		FD_ZERO(&fds);
		FD_SET(ns,&fds);

		/* Wait for some input. */
		nready = select(maxfd, &fds, (fd_set *) 0, (fd_set *) 0,
				(struct timeval *) 0);
		/* If either descriptor has some input,
		   read it and copy it to the other. */

		if( FD_ISSET(ns, &fds))
		{
			nread = recv(ns, buffer, sizeof(buffer), 0);
			/* If error or eof, terminate. */
			if(nread < 1)
			{
				close(ns);
				exit(0);
			}
			
			operation = buffer[0];
			int* data = (int*)(buffer+1);
			int bit = ntohl(*data);

			printf("op=%c bit=%d\n",operation,bit);

			switch(operation) {
			case 'S':
				bits |= 1<<bit;
				printf("Bits = %X\n\n",bits);
				break;
					
			case 'T':
				bits ^= 1<<bit;
				printf("Bits = %X\n\n",bits);
				break;
				
			case 'C':
				bits &= ~(1<<bit);
				printf("Bits = %X\n\n",bits);
				break;
			}

			data = (int*) msg;
			(*data) = htonl(bits);	
			send( ns, msg, 4, 0);
		}
	} 
}

