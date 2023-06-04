/*
 * minor3.c - using producer-consumer paradigm.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NITEMS 10		// number of items in shared buffer

// shared variables
char shared_buffer_a[NITEMS];	// a buffer
char shared_buffer_b[NITEMS];	// b buffer
int shared_count;		// item count

pthread_mutex_t mutex;		// pthread mutex
unsigned int prod_index = 0; 	// producer index into shared buffer
unsigned int cons_index = 0; 	// consumer index into shard buffer

// function prototypes
void * producer(void *arg);
void * consumer(void *arg);

int main() 
{ 
	pthread_t prod_tid, cons_tid1, cons_tid2; 

	// initialize pthread variables
	pthread_mutex_init(&mutex, NULL);
	
	// start producer thread
	pthread_create(&prod_tid, NULL, producer, NULL);

	// start consumer threads
	pthread_create(&cons_tid1, NULL, consumer, NULL);
	pthread_create(&cons_tid2, NULL, consumer, NULL);
	
	// wait for threads to finish
	pthread_join(prod_tid, NULL);
	pthread_join(cons_tid1, NULL);
	pthread_join(cons_tid2, NULL);
			
	// clean up
	pthread_mutex_destroy(&mutex);
	
	return 0;
}

// producer thread executes this function
void * producer(void *arg)
{
	char a,b;

	printf("Enter digits for producer to read and consumer to compare and print, use Ctrl-C to exit.\n\n");

	// this loop has the producer read in from stdin and place on the shared buffer
	while (1)
	{
		// read input key
		scanf("%c", &a);
		if (a=='\n') continue;	// check for end of line
		scanf("%c", &b);
		if(a<'0' || a>'9' || b<'0' || b>'9')
			continue;

		// this loop is used to poll the shared buffer to see if it is full:
		// -- if full, unlock and loop again to keep polling
		// -- if not full, keep locked and proceed to place character on shared buffer
		while (1)
		{
			// acquire mutex lock
			pthread_mutex_lock(&mutex);

			// if buffer is full, release mutex lock and check again
			if (shared_count == NITEMS)
				pthread_mutex_unlock(&mutex);
			else
				break;
		}

		// convert to integers and store values in shared buffers
		shared_buffer_a[prod_index] = a-'0';
		shared_buffer_b[prod_index] = b-'0';

		// update shared count variable
		shared_count++;

		// update producer index
		if (prod_index == NITEMS - 1)
			prod_index = 0;
		else
			prod_index++;
		
		// release mutex lock
		pthread_mutex_unlock(&mutex); 
	}

	return NULL;
}

// consumer thread executes this function
void * consumer(void *arg)
{
	int a,b;
	int slot;
 	char op;

	long unsigned int id = (long unsigned int)pthread_self();

	// this loop has the consumer gets from the shared buffer and prints to stdout
	while (1)
	{
		// this loop is used to poll the shared buffer to see if it is empty:
		// -- if empty, unlock and loop again to keep polling
		// -- if not empty, keep locked and proceed to get character from shared buffer
		while (1)
		{
			// acquire mutex lock
			pthread_mutex_lock(&mutex);

			// if buffer is empty, release mutex lock and check again
			if (shared_count == 0)
				pthread_mutex_unlock(&mutex);
			else
				break;
		}

		// read values from shared buffer
		slot = cons_index;
		a = shared_buffer_a[cons_index];
		b = shared_buffer_b[cons_index];
		
		// update shared count variable
		shared_count--;

		// update consumer index
		if (cons_index == NITEMS - 1)
			cons_index = 0;
		else
			cons_index++;
	
		// release mutex lock
		pthread_mutex_unlock(&mutex);
		
		// compare values
		if (a<b) {
			op = '<';
		} else if (a>b) {
			op = '>';
		} else {
			op = '=';
		}
		
		printf("%lu-%d:%d%c%d\n", (long unsigned int) id, slot, a, op, b);

	}
	return NULL;
}


