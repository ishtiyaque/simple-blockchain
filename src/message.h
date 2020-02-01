#ifndef REQUEST_H
#define REQUEST_H

#include "block.h"


struct client_message {
	size_t log_size;
	Block *log;
	client_message(size_t s);
	~client_message();
	
};


#endif
