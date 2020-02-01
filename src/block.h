#ifndef BLOCK_H
#define BLOCK_H

typedef unsigned int Clientid;

class Block {
	Clientid sndr;
	Clientid rcvr;
	double amount;
	unsigned int timestamp; 
	
public:
	Block *prev, *next;
	Block(Clientid s, Clientid r, double a, unsigned int t);
	Clientid get_sndr(){return sndr;}
	Clientid get_rcvr(){return rcvr;}
	double get_amount(){return amount;}
	unsigned int get_timestamp(){return timestamp;}

};


#endif