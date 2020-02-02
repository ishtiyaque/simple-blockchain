#include "client_receiver.h"
#include<stdio.h>
#include<stdlib.h>

void *handle_client(void *client_id) {
	int socket = client_sockets[*((int*)client_id)];
	int n, log_size;
	Block *block;
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
		fflush(stdout);
	}
}