#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include<stdio.h>
#include "block.h"


class Blockchain {
	Block *head, *tail;
	bool append(Block * blk);
public:
	Blockchain(){head = tail = 0;}
	double get_balance(Clientid id);
	bool make_transaction(Clientid sndr, Clientid rcvr, double amount);
	
	void print();
	
};

#endif
