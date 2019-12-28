# include <stdio.h>
# include <iostream>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
using namespace std;

const int MAXSTR = 2048;
const int MAXUSR = 3;

// define Argument strct passing to pthread
typedef struct _argument
{
    int sockfd;
    int clientSockfd;
    struct sockaddr_in clientInfo;
} Argument;

void* newUser(void* argsVoid);

int main(int argc , char *argv[])
{
    char message[] = {"Hi Client, this is server.\n"};

    // construct the socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1)
        printf("Fail to create a socket.");

    // initialize the server socket
    struct sockaddr_in serverInfo;
    bzero(&serverInfo, sizeof(serverInfo));

    // set the socket info
    serverInfo.sin_family = PF_INET;
    serverInfo.sin_addr.s_addr = INADDR_ANY;
    // serverInfo.sin_port = htons(2400); // net0
    serverInfo.sin_port = htons(8700); // local
    bind(sockfd, (struct sockaddr*)& serverInfo, sizeof(serverInfo));
    listen(sockfd, MAXUSR);

    // thread
    pthread_t thread[MAXUSR];

    int threadCnt = 0;

    // keep server alive
    while (true)
    {
        // find new client
        struct sockaddr_in clientInfo;
        socklen_t addrlen = sizeof(clientInfo);
        int clientSockfd = accept(sockfd, (struct sockaddr*)& clientInfo, &addrlen);

        // set pthread Argument
        Argument args;
        args.sockfd = sockfd;
        args.clientSockfd = clientSockfd;
        args.clientInfo = clientInfo;

        // create thread
        pthread_create(&thread[threadCnt], NULL, newUser, (void*)& args);

        // assign to a thread and prepare for next client
        threadCnt++;
    }

    return 0;
}

// add new user for threading
void* newUser(void* argsVoid)
{
    // parse args
    Argument* args = (Argument*) argsVoid;
    int sockfd = args->sockfd;
    int clientSockfd = args->clientSockfd;
    struct sockaddr_in clientInfo = args->clientInfo;

    char inputBuffer[256]; // each recv line's buffer
    int revCnt = 0;        // for bug
    int bytesReceived = 1;

    // when the client is still alive
    while (true)
    {
        // get the client's input line
        bytesReceived = recv(clientSockfd, inputBuffer, sizeof(inputBuffer), 0);
        inputBuffer[bytesReceived] = '\0';

        // for every client input line
        if (revCnt % 4 == 0) // bug
        {
            // if the client want to exit from server
			if (strcmp(inputBuffer, "exit") == 0)
			{
				char byebye[10] = {"See You~"};
				send(clientSockfd, byebye, strlen(byebye) + 1, 0);
				break;
			}
            else
            {
                // Echo message back to client
                char message[MAXSTR] = {"You say:\n\t ==> "};
                strcat(message, inputBuffer);
                send(clientSockfd, message, strlen(message) + 1, 0);
                printf("Get<%d>: <%s>\n", (revCnt / 4) + 1, inputBuffer);
            }
        }
        revCnt++;
    }

	// close client socket
	close(clientSockfd);
    cout << "Client: " << clientSockfd << " DISCONNECT!\n";
}
