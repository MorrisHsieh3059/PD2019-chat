const int MAXSTR = 2048;
const int MAXUSR = 10;
const char ULE_MESSAGE[] = "Max User Limit Exceed. See You~";
const char SENDER[] = {"<sender>"};
const char SENDEE[] = {"<sendee>"};
const char BYEBYE[10] = {"See You~"};
// const char GREET[] = {"Hi Client, this is server.\n"};

// define Argument strct passing to pthread
typedef struct _argument
{
    int* uidPtr;
    int* threadCntPtr;
    int serverSockfd;
    int clientSockfd;
    struct sockaddr_in clientInfo;
} Argument;

void* newUser(void* argsVoid);
