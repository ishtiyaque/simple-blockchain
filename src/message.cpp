#include "message.h"

client_message::client_message(Clientid r, vector<Block *>l){
	rcvr = r;
	log = l; 
}
