#ifndef BLOCK_H
#define BLOCK_H

#include<stdio.h>

typedef unsigned int Clientid;

class Block {
	Clientid sndr;
	Clientid rcvr;
	double amount;
	unsigned int timestamp; 
	
public:
	Block *prev, *next;
	Block(){}
	Block(Clientid s, Clientid r, double a, unsigned int t);
	Clientid get_sndr(){return sndr;}
	Clientid get_rcvr(){return rcvr;}
	double get_amount(){return amount;}
	unsigned int get_timestamp(){return timestamp;}
	void print();

};


#endif
