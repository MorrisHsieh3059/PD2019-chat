# include <stdio.h>
# include <iostream>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <bits/stdc++.h>
# include "func_server.h"
using namespace std;

// add new user for threading
void* newUser(void* argsVoid)
{
    // parse args
    Argument* args = (Argument*) argsVoid;
    int* uidPtr = args->uidPtr;
    int* threadCntPtr = args->threadCntPtr;
    int serverSockfd = args->serverSockfd;
    int clientSockfd = args->clientSockfd;
    struct sockaddr_in clientInfo = args->clientInfo;

	printf("%d users\n", *threadCntPtr);

    char inputBuffer[256]; // each recv line's buffer
    int revCnt = 0;        // for bug
	int line = 0;
    int bytesReceived = 1;

    // when the client is still alive
    while (true)
    {
        // get the client's input line
        bytesReceived = recv(clientSockfd, inputBuffer, sizeof(inputBuffer), 0);
        inputBuffer[bytesReceived] = '\0';

        // for every client input line
//        if (revCnt % 8 == 0) // bug
//        {
        // if the client want to exit from server
		if (strcmp(inputBuffer, "exit") == 0)
		{
			send(clientSockfd, BYEBYE, strlen(BYEBYE) + 1, 0);
			break;
		}
        else
        {
            // Echo message back to all users
            for (int idx = 0; idx < *threadCntPtr; idx++)
            {
                char res[MAXSTR];
                strcpy(res, inputBuffer);

				// if meaningful message
				if (strlen(res) > 0)
				{
                    cout << "---> try to send to client<" << uidPtr[idx] << ">, w/ status <";
	                if (uidPtr[idx] == clientSockfd) // for sender
		                strcat(res, SENDER);
			        else                             // for sendee
				        strcat(res, SENDEE);

					cout << send(uidPtr[idx], res, strlen(res) + 1, 0) << ">\n";
					line++;
					printf("Get<%d>: <%s>\n", line, inputBuffer);
				}
            }
        }
//        }
        revCnt++;
    }

	// close client socket
	close(clientSockfd);
    cout << "Client: " << clientSockfd << " DISCONNECT!\n";

    // update alive people
    for (int i = 0; i < *threadCntPtr; i++)
        if (uidPtr[i] == clientSockfd)
        {
            uidPtr[i] = -1;
            break;
        }

    sort(uidPtr, uidPtr + MAXUSR, greater<int>()); // from high to low (-1 at btm)
    *threadCntPtr -= 1;

    return nullptr;
}
