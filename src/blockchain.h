#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include<stdio.h>
#include <pthread.h>
#include <vector>
#include "block.h"
using namespace std;

class Blockchain {
	Block *head, *tail;
	pthread_mutex_t lock;
public:
	Blockchain();
	bool append(Block * blk);
	double get_balance(Clientid id);
	bool make_transaction(Clientid sndr, Clientid rcvr, double amount);
	void print();
	vector<Block *> get_log(Clientid id);
	~Blockchain();
	
};

#endif
