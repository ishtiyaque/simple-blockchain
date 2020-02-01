#ifndef GLOBAL_H
#define GLOBAL_H

#include "blockchain.h"


extern unsigned int my_id;
extern unsigned int num_client;

extern unsigned int **timetable;

extern double *init_balance;

extern Blockchain chain;

extern int *client_sockets;

#endif
