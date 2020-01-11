# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <iostream>
# include "func_client.h"
using namespace std;

int main()
{
	printf("Part I: set socket\n");
    // socket declaration
    int clientSockfd = 0;
    clientSockfd = socket(AF_INET, SOCK_STREAM , 0);

    if (clientSockfd == -1)
        printf("\tFail to create a socket.");

    // socket initialization
    printf("\tinitializing connecting to server!\n");
	struct sockaddr_in serverInfo;
    bzero(&serverInfo, sizeof(serverInfo)); // initialize
    serverInfo.sin_family = PF_INET;  // ipv4

	// socket IP and port
    printf("\tsetting IP and port!\n");
	/* local 
	serverInfo.sin_addr.s_addr = inet_addr("127.0.0.1");     // local IP address
    serverInfo.sin_port = htons(8700);                       // local port */

	/* csie server (net0) */
	serverInfo.sin_addr.s_addr = inet_addr("140.112.30.36"); // net0 IP address
    serverInfo.sin_port = htons(2400);                       // net0 port */

	// socket connection
	printf("\ttry to connect to server, result ==> ");
    int err = connect(clientSockfd, (struct sockaddr *)& serverInfo, sizeof(serverInfo));

	if (err == -1)
        printf("ERROR\n");
	else
	{
		printf("SUCCESS\n\n");

		// Part II: I/O
		printf("Part II: starting I/O\n");

		// pthread
		pthread_t thread[JOBS];

		// set pthread Argument
		bool connect = true;
		Argument args;
		args.clientSockfd = clientSockfd;
		args.serverInfo = serverInfo;
		args.connectPtr = &connect;

		// keep client alive
		while (true)
		{
			// receiving all others' chat record
			pthread_create(&thread[0], nullptr, othersMessage, (void*)& args);
			pthread_create(&thread[1], nullptr, myMessage, (void*)& args);
			if (*args.connectPtr == false)
				break;
		}

		// close client socket
        close(clientSockfd);
        printf("Client close Socket\n");
	}
    return 0;
}
