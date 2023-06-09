/***************************************************************************/
/*                                                                         */
/* Server program which wait for the client to connect and reads the data  */
/*     using non-blocking socket.                                          */
/* The reading of non-blocking sockets is done in a loop until data        */
/*     arrives to the sockfd.                                              */
/*                                                                         */
/***************************************************************************/


#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <sys/wait.h> 
#include <fcntl.h> /* Added for the nonblocking socket */
#include <unistd.h>
#include <arpa/inet.h>


#define MYPORT 3456    /* the port users will be connecting to */
#define BACKLOG 10     /* how many pending connections queue will hold */

int main()
{
	int 		sockfd, new_fd;  /* listen on sock_fd, new connection on new_fd */
	struct 	sockaddr_in 	my_addr;    /* my address information */
	struct 	sockaddr_in 	their_addr; /* connector's address information */
	int 		sin_size;
	char		string_read[255];
	int 		n,i;
	int			last_fd;	/* Thelast sockfd that is connected	*/

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) 
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}
	
	last_fd = sockfd;

	my_addr.sin_family = AF_INET;         /* host byte order */
	my_addr.sin_port = htons(MYPORT);     /* short, network byte order */
	my_addr.sin_addr.s_addr = INADDR_ANY; /* auto-fill with my IP */
	bzero(&(my_addr.sin_zero), 8);        /* zero the rest of the struct */

	if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1) 
	{
		perror("bind");
		exit(1);
	}

	if (listen(sockfd, BACKLOG) == -1) 
	{
		perror("listen");
		exit(1);
	}

	printf("Waiting on first connection...\n");

	sin_size = sizeof(struct sockaddr_in);
	if ((new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size)) == -1) 
	{
		perror("accept");
	}

	last_fd = new_fd;

	printf("PRE-LOOP: sockfd=%d last_fd=%d new_fd=%d\n", sockfd, last_fd, new_fd);

	fcntl(last_fd, F_SETFL, O_NONBLOCK); /* Change the socket into non-blocking state	*/
	fcntl(new_fd, F_SETFL, O_NONBLOCK); /* Change the socket into non-blocking state	*/

	while (1)
	{
		sleep(1);
		printf("LOOP: sockfd=%d last_fd=%d new_fd=%d\n", sockfd, last_fd, new_fd);
		for (i=sockfd;i<=last_fd;i++)
		{
			printf("Round number %d\n",i);

			if (i == sockfd)
			{
				printf("Waiting on next connection...\n");

		 		sin_size = sizeof(struct sockaddr_in);

				if ((new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size)) == -1) 
				{
					perror("accept");
				}

				printf("ACCEPT: new_fd=%d from %s\n", new_fd, (char *)inet_ntoa(their_addr.sin_addr)); 
				fcntl(new_fd, F_SETFL, O_NONBLOCK);
				last_fd = new_fd;
			}
			else
			{
				printf("RECV: sockfd=%d last_fd=%d new_fd=%d i=%d\n", sockfd, last_fd, new_fd, i);
				n=recv(new_fd,string_read,sizeof(string_read),0);

				if (n < 1)
				{ 
					perror("recv - non blocking \n");
					printf("Round %d, and the data read size is: n=%d \n",i,n);
				}
				else
				{
					string_read[n] = '\0';
					printf("The string is: %s \n",string_read);

					if (send(new_fd, "Hello, world!\n", 14, 0) == -1)
					{
						perror("send");
					}
				}
			}
		}
	}
}

