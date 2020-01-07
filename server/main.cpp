# include <stdio.h>
# include <iostream>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include "func_server.h"
using namespace std;

int main(int argc , char *argv[])
{
    // construct the socket
    int serverSockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSockfd == -1)
        printf("Fail to create a socket.");

    // initialize the server socket
    struct sockaddr_in serverInfo;
    bzero(&serverInfo, sizeof(serverInfo));

    // set the socket info
    serverInfo.sin_family = PF_INET;
    serverInfo.sin_addr.s_addr = INADDR_ANY;
    // serverInfo.sin_port = htons(2400); // net0
    serverInfo.sin_port = htons(8700); // local
    bind(serverSockfd, (struct sockaddr*)& serverInfo, sizeof(serverInfo));
    listen(serverSockfd, MAXUSR);

    // thread
    pthread_t thread[MAXUSR];
    int uid[MAXUSR];          // records aliving users (clientSockfd)
    for (int id = 0; id < MAXUSR; id++)
        uid[id] = -1;
    int threadCnt = 0;

    // keep server alive
    while (true)
    {
        // find new client
        struct sockaddr_in clientInfo;
        socklen_t addrlen = sizeof(clientInfo);
        int clientSockfd = accept(serverSockfd, (struct sockaddr*)& clientInfo, &addrlen);

        // set pthread Argument
        Argument args;
        args.uidPtr = uid;
        args.threadCntPtr = &threadCnt;
        args.serverSockfd = serverSockfd;
        args.clientSockfd = clientSockfd;
        args.clientInfo = clientInfo;

        // create thread
        if (threadCnt < MAXUSR)
        {
            uid[threadCnt] = args.clientSockfd;
            pthread_create(&thread[threadCnt], NULL, newUser, (void*)& args);
            threadCnt++; // assign to a thread and prepare for next client
        }
        else // ULE Exceed
        {
            send(args.clientSockfd, ULE_MESSAGE, strlen(ULE_MESSAGE) + 1, 0);
        }
    }

    return 0;
}
