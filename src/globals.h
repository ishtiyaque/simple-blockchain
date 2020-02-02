#ifndef GLOBAL_H
#define GLOBAL_H

#include "block.h"
#include "blockchain.h"
#include "sync_queue.h"
#include "message.h"

using namespace std;


extern unsigned int my_id;
extern unsigned int num_client;

extern unsigned int *client_list;

extern unsigned int **timetable;

extern double *init_balance;

extern Blockchain chain;

extern sync_queue<Block *> block_queue;
extern sync_queue<client_message *> log_queue;

extern int *client_sockets;

#endif
