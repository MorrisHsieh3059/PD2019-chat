# include <stdio.h>
# include <iostream>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include "func_client.h"
using namespace std;

// waiting for othres' message
void* othersMessage(void* argsVoid)
{
	// parse args
	Argument* args = (Argument*) argsVoid;
	int clientSockfd = args->clientSockfd;
	struct sockaddr_in serverInfo = args->serverInfo;

	while (true)
	{
		char receiveMessage[MAXSTR];
		bool check = *((Argument*) argsVoid)->connectPtr;
		if (check == false)
			break;

		recv(clientSockfd, receiveMessage, sizeof(receiveMessage), 0);
		printf("%s\n", receiveMessage);

		if (strcmp(receiveMessage, ULE_MESSAGE) == 0)
		{
			// ULE exceed
			*( ((Argument*) argsVoid )->connectPtr ) = false;
			break;
		}
	}

	return nullptr;
}

// send my message
void* myMessage(void* argsVoid)
{
	// parse args
	Argument* args = (Argument*) argsVoid;
	int clientSockfd = args->clientSockfd;
	struct sockaddr_in serverInfo = args->serverInfo;

	// line
	char myWord[MAXSTR];
	while (cin.getline(myWord, MAXSTR))
	{
		// Send a message to server
		// char receiveMessage[MAXSTR];
		send(clientSockfd, myWord, sizeof(myWord), 0);

		// receive message from server
		// recv(clientSockfd, receiveMessage, sizeof(receiveMessage), 0);
		// printf("%s\n", receiveMessage);

		if (strcmp(myWord, "exit") == 0)
		{
			// want to quit
			*( ((Argument*) argsVoid )->connectPtr ) = false;
			break;
		}
	}

	return nullptr;
}
