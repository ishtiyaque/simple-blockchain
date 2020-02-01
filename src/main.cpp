#include "utils.h"
#include "blockchain.h"

unsigned int num_client;

unsigned int my_id;
double *init_balance;

unsigned int **timetable;

int *client_sockets;

Blockchain chain;

int main(int argc, char *argv[]) {
	char command[5];
		
	if(argc < 2) {
		printf("Missing Client id. Exiting...\n");
		exit(1);
	}
	my_id = atoi(argv[1]);
	printf("Started Client %d\n",my_id);
	init("../config.txt");
	print_time_table();
	
	
	while(1) {
		scanf("%s",command);
		if(!strcmp(command,"TRAN")) {
			
		} else if(!strcmp(command,"MSG")) {
		} else {
			printf("Invalid command");
		}
	}

	return 0;
}
