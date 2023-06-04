#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>   /* inet(3) functions */

#include "bits2.h"

int get_operation(int* op, unsigned short* bit);

short execute_operation(int operation, unsigned short bit, unsigned short value, 
	int sockfd, const struct sockaddr *pservaddr, socklen_t servlen);

void display(unsigned short value);

int main(int argc, char *argv[]) {
	
	/* Data */
	int op;
	unsigned short bit;
	unsigned short value = 0;
	
	/* Network */
	int sockfd;
	struct sockaddr_in servaddr;
	
	if (argc != 2)
		{
			printf("usage : %s <IP Address>\n", argv[0]);
			exit(1);
		}
	
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(12000);
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
	
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	
	/* Main Loop */
	while(get_operation(&op, &bit)) {
		value=execute_operation(op, bit, value, sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
		display(value);
	}
}

int get_operation(int* op, unsigned short* bit) {
	
	int rv = 1;
	char operation;

	printf("Valid Operations\n");
	printf("eXit\n");
	printf("Set\n");
	printf("Toggle\n");
	printf("Clear\n");
	
	printf("Operation: ");
	
	scanf(" %c", &operation);
	operation = toupper(operation);
	
	if(operation=='X') {
		rv=0;
	} else {
		
		printf("Bit: ");
		scanf("%hu", bit);
		
		switch(operation) {
			case 'S':
				(*op) = BIT_SET;
				break;
			
			case 'T':
				(*op) = BIT_TOGGLE;
				break;
			
			case 'C':
				(*op) = BIT_CLEAR;
				break;
		}
	}
	return rv;
}

short execute_operation(int operation, unsigned short bit, unsigned short value, 
						int sockfd, const struct sockaddr *pservaddr, socklen_t servlen) {
	unsigned char data[MAXDATA];
	unsigned char response[sizeof(uint16_t)];
	
	uint32_t templ = htonl(operation);
	memcpy(data, &templ, sizeof(templ));
	uint16_t temps = htons(bit);
	memcpy(data+4, &temps, sizeof(temps));
	uint16_t temps2 = htons(value);
	memcpy(data+6, &temps2, sizeof(temps2));
	
	printf("Send Data:");
	printf(" %08x", *(unsigned int*)data);
	printf(" %04x", *(unsigned short*)(data+4));
	printf(" %04x", *(unsigned short*)(data+6));
	
	sendto(sockfd, data, MAXDATA, 0, pservaddr, servlen);
	
	int n = recvfrom(sockfd, response, REC_LEN, 0, NULL, NULL);

	memcpy(&value, response, sizeof(uint16_t));


	unsigned short rv = ntohs(value);
	printf("\nReceived Data:");
	printf(" %04x", rv);

	return rv;
}

void display(unsigned short value) {
	unsigned int data = value;
	printf("\nBits = %#06x\n\n",data);
}