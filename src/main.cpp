#include "utils.h"

unsigned int num_client;

unsigned int my_id;

int *client_sockets;

int main(int argc, char *argv[]) {
	char command[5];
		
	if(argc < 2) {
		printf("Missing Client id. Exiting...\n");
		exit(1);
	}
	my_id = atoi(argv[1]);
	printf("Started Client %d\n",my_id);
	init("../config.txt");
		
	while(1);	
	return 0;
}
