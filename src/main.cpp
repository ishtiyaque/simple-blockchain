#include "utils.h"
#include "blockchain.h"
#include "sync_queue.h"
#include "message.h"
#include "dispatcher.h"
#include "client_receiver.h"
#include "block_handler.h"
#include <vector>
#include<pthread.h>

unsigned int num_client;

unsigned int my_id;
double *init_balance;

unsigned int *client_list;
unsigned int **timetable;


int *client_sockets;

Blockchain chain;

sync_queue<Block *> block_queue;
sync_queue<client_message *> log_queue;

pthread_t dispatcher;
pthread_t block_handler;
pthread_t *client_handler;


int main(int argc, char *argv[]) {
	char command[6];
	unsigned int client_id;
	double amount;
	Block *block;
	
	client_message *msg;
		
	if(argc < 2) {
		printf("Missing Client id. Exiting...\n");
		exit(1);
	}
	my_id = atoi(argv[1]);
	printf("Started Client %d\n",my_id);
	init("../config.txt");
	
	pthread_create(&dispatcher, 0, dispatch, 0);
	pthread_create(&block_handler, 0, handle_block, 0);

	
	client_handler = new pthread_t[num_client - 1];
	for(int i=0, j=1; j <= num_client;j++) {
		if(j != my_id) {
			pthread_create(client_handler + i, 0, handle_client, &client_list[j]);
			i++;
		}
	}
	
	
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
			scanf("%d",&client_id);
			vector<Block *> log = chain.get_log(client_id);			
			msg = new client_message(client_id, log);
			log_queue.push(msg);
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
