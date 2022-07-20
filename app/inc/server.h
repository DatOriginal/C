#ifndef _SERVER_H_
#define _SERVER_H_

#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>	
#include <pthread.h>

#define PORT 35674
#define SA struct sockaddr

void *func_server();


#endif