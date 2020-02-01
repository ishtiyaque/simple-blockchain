#include "utils.h"
#include "blockchain.h"
#include "sync_queue.h"

unsigned int num_client;

unsigned int my_id;
double *init_balance;

unsigned int **timetable;


int *client_sockets;

Blockchain chain;

sync_queue<Block *> block_queue;

int main(int argc, char *argv[]) {
	char command[6];
	unsigned int client_id;
	double amount;
	Block *block;
		
	if(argc < 2) {
		printf("Missing Client id. Exiting...\n");
		exit(1);
	}
	my_id = atoi(argv[1]);
	printf("Started Client %d\n",my_id);
	init("../config.txt");
	//print_time_table();
	
	
	while(1) {
		scanf("%s",command);
		if(!strcmp(command,"TRAN")) {
			scanf("%d%lf",&client_id, &amount);
			if((chain.get_balance(my_id) + init_balance[my_id]) >= amount) {
				block = new Block(my_id, client_id, amount, ++timetable[my_id][my_id]);
				chain.append(block);
				printf("Transfer SUCCESSFULL\n");
			}else {
				printf("Insufficient Balance! Transfer FAILED\n");
			}
			
		} else if (!strcmp(command,"BAL")) {
			scanf("%d",&client_id);
			printf("Balance of Client %d is: $%lf\n",client_id, chain.get_balance(client_id) + init_balance[client_id]);
		} else if(!strcmp(command,"MSG")) {
		} else if(!strcmp(command,"TIME")) {
			print_time_table();
		} else if(!strcmp(command,"CHAIN")) {
			chain.print();
		} else {
			printf("Invalid command\n");
		}
	}

	return 0;
}
