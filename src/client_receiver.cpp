#include "client_receiver.h"
#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) ((a) > (b)) ? (a) : (b)

void *handle_client(void *client_id) {
	int socket = client_sockets[*((int*)client_id)];
	int n, log_size;
	Block *block;
	unsigned int **tt = new unsigned int*[num_client + 1];
	for(int i = 0; i <= num_client; i++) {
		tt[i] = new unsigned int[num_client + 1];
	}

	//printf("Thread created with value %d\n",*socket);
	while(1) {
		n = read(socket, &log_size, sizeof(int));
		if(n < 0) {
			printf("read error. Exiting....\n");
			exit(1);
		}
		printf("Received message from %d\nlog size: %d\n", *(int *)client_id, log_size);
		for(int i = 0; i < log_size; i++) {
			block = new Block();
			read(socket, block, sizeof(Block));
			block->print();
			block_queue.push(block);
		}

			
		printf("Finished reading blocks\n");
		for(int i = 1; i <= num_client; i++) {
			for(int j = 1; j <= num_client; j++) {
				read(socket, &tt[i][j], sizeof(unsigned int));
			}
		}

		for(int i = 1; i <= num_client;i++) {
			for(int j = 1; j <= num_client; j++) {
				printf("%d\t",tt[i][j]);
				timetable[i][j] = MAX(timetable[i][j], tt[i][j]);
			}
			printf("\n");
		}

		fflush(stdout);
	}
}