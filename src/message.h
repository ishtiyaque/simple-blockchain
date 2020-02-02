#ifndef REQUEST_H
#define REQUEST_H

#include "block.h"
#include<vector>
using namespace std;

struct client_message {
	Clientid rcvr;
	vector<Block *> log;
	client_message(Clientid r, vector<Block *>l);
	
};


#endif
