const int MAXSTR = 2048;
const char ULE_MESSAGE[] = "Max User Limit Exceed. See You~";
const int JOBS = 2; // one for recv all others message, the other for sending message

// define Argument struct passing to pthread
typedef struct _argument
{
	int clientSockfd;
	struct sockaddr_in serverInfo;
	bool* connectPtr;
} Argument;

void* othersMessage(void* argsVoid);
void* myMessage(void* argsVoid);
