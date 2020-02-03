#include "dispatcher.h"
#include "globals.h"

void *dispatch(void *ignore) {
	client_message *msg;
	int socket;
	int sz;
		
	while(1) {		
		msg = log_queue.remove();
		printf("Sending message to Client %d...\n",msg->rcvr);
		my_sleep();
		socket = client_sockets[msg->rcvr];
		sz = msg->log.size();
		write(socket,(char *)&sz ,sizeof(int));
		for(int i = 0; i < sz; i++) {
			write(socket, (char *)(msg->log[i]), sizeof(Block));
		}
		for(int i = 1; i <= num_client; i++) {
			for(int j = 1; j <= num_client; j++) {
				write(socket, (char *)&timetable[i][j], sizeof(unsigned int));
			}
		}
		delete msg;
		
	}

}
