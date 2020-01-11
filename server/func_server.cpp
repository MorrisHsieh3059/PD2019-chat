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

	// when new uer comes in, notify all clients w/ new userCnt
	printf("%d users\n", *threadCntPtr);
    for (int idx = 0; idx < *threadCntPtr; idx++)
	{
		char notification[15];
		sprintf(notification, "%s%d>%s", USER_ADD_NOTE, *threadCntPtr, NAME[clientSockfd]);
		send(uidPtr[idx], notification, strlen(notification) + 1, 0);
	}

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

		char userName[MAXSTR];
		strcpy(userName, NAME[clientSockfd]);

        // for every client input line
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
					char msg[MAXSTR];
                    cout << "---> try to send to client<" << uidPtr[idx] << ">, w/ status <";
	                if (uidPtr[idx] == clientSockfd) // for sender
					{
						sprintf(msg, "%s: %s%s%d", userName, res, SENDER, *threadCntPtr);
		                // strcat(res, msg);
					}
			        else                             // for sendee
					{
						sprintf(msg, "%s: %s%s%d", userName, res, SENDEE, *threadCntPtr);
						// strcat(res, msg);
					}

					cout << send(uidPtr[idx], msg, strlen(msg) + 1, 0) << ">\n";
					line++;
					printf("Get<%d>: <%s>\n", line, inputBuffer);
				}
            }
        }
        revCnt++;
    }

	// close client socket
	close(clientSockfd);
    cout << "Client: " << clientSockfd << " DISCONNECT! with existing users: " <<
		                  *threadCntPtr - 1<< "\n";

    // update alive people
    for (int i = 0; i < *threadCntPtr; i++)
        if (uidPtr[i] == clientSockfd)
        {
            uidPtr[i] = -1;
            break;
        }

    sort(uidPtr, uidPtr + MAXUSR, greater<int>()); // from high to low (-1 at btm)
    *threadCntPtr -= 1;

	// one user left, send new userCnt to all
    for (int idx = 0; idx < *threadCntPtr; idx++)
	{
		char notification[15];
		sprintf(notification, "%s%d>%s", USER_DEL_NOTE, *threadCntPtr, NAME[clientSockfd]);
		send(uidPtr[idx], notification, strlen(notification) + 1, 0);
	}

    return nullptr;
}
