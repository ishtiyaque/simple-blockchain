#include "dispatcher.h"

void *dispatch(void *ignore) {
	client_message *msg;
	int socket;
	int sz;
		
	while(1) {		
		msg = log_queue.remove();
		socket = client_sockets[msg->rcvr];
		sz = msg->log.size();
		write(socket,(char *)&sz ,sizeof(int));
		for(int i = 0; i < sz; i++) {
			write(socket, (char *)(msg->log[i]), sizeof(Block));
		}
		delete msg;
		
	}

}
