#ifndef UTILS_H
#define UTILS_H

#define SLEEP_TIME 3

#define PROTOCOL SOCK_STREAM

#include <stdio.h>
//#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include<unistd.h>
#include<strings.h>
#include<string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include<vector>
#include<queue>
#include <pthread.h>
#include<time.h>
#include "globals.h"

using namespace std;



void init(const char *filename);
void my_sleep();
#endif
