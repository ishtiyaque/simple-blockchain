#include "message.h"

client_message::client_message(size_t s){
	log_size = s;
	log = new Block[log_size]; 
}

client_message::~client_message() {
	delete log[];
}