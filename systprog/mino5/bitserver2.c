#include <stdio.h>
#include <ctype.h>

#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>   /* inet(3) functions */
#include <netinet/in.h>

#include "bits2.h"



int get_operation(int* op, unsigned short* bit, unsigned short* value,
				int sockfd, struct sockaddr *pcliaddr, socklen_t clilen
);

short execute_operation(int operation, unsigned short bit, unsigned short value);

void display(unsigned short value,
			int sockfd, struct sockaddr *pcliaddr, socklen_t clilen);


int main(int argc, char *argv[]) {
	/* Data */
	int op;
	unsigned short bit;
	unsigned short value = 0;
	
	/* Network */
	int sockfd;
	struct sockaddr_in servaddr,cliaddr;
	
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(12000);
	
	bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	
	/* Main Loop */
	while(get_operation(&op, &bit, &value,
						sockfd, (struct sockaddr *) &cliaddr, sizeof(cliaddr))) {
		value=execute_operation(op, bit, value);
		display(value, sockfd, (struct sockaddr *) &cliaddr, sizeof(cliaddr));
	}
}

int get_operation(int* op, unsigned short* bit, unsigned short* value,
				int sockfd, struct sockaddr *pcliaddr, socklen_t clilen) {
					
	int n;
	socklen_t len;
	unsigned char data[MAXDATA];

	len = clilen;
	n = recvfrom(sockfd, data, MAXDATA, 0, pcliaddr, &len);

	struct {
		uint32_t op;
		uint16_t bit;
		// buffer of 2 bytes
		uint16_t value;
	} data2;

	uint32_t templ;
	memcpy(&templ, data, sizeof(templ));
	*op = ntohl(templ);
	
	uint16_t temps;
	memcpy(&temps, data+4, sizeof(temps));
	*bit = ntohs(temps);
	
	uint16_t temps2;
	memcpy(&temps2, data+6, sizeof(temps2));
	*value = ntohs(temps2);

	printf("Received Data:");
	printf(" %08x", *op);
	printf(" %04x", *bit);
	printf(" %04x", *value);

	return 1;
}

short execute_operation(int operation, unsigned short bit, unsigned short value) {
	switch (operation) {
		case BIT_SET:
			value |= 1<<bit;
			break;
		
		case BIT_TOGGLE:
			value ^= 1<<bit;
			break;
		
		case BIT_CLEAR:
			value &= ~(1<<bit);
			break;
	}
	return value;
}

void display(unsigned short value,
			 int sockfd, struct sockaddr *pcliaddr, socklen_t clilen) {

	socklen_t len = clilen;
	unsigned char data[sizeof(uint16_t)];
	
	uint16_t rv = htons(value);
	memcpy(data, &rv, sizeof(uint16_t));

	printf("\nSend Data = %04x\n\n",value);
	sendto(sockfd, data, sizeof(uint16_t), 0, pcliaddr, clilen);

}