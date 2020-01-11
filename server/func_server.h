const int MAXSTR = 2048;
const int MAXUSR = 10;
const char ULE_MESSAGE[] = "Max User Limit Exceed. See You~";
const char SENDER[] = {"<sender>"};
const char SENDEE[] = {"<sendee>"};
const char BYEBYE[10] = {"See You~"};
const char USER_ADD_NOTE[15] = {"<userCntIn>"};
const char USER_DEL_NOTE[15] = {"<userCntOut>"};
const char NAME[20][10] = {
							"Alice", "Bob", "Cathy", "Dora", "Emily", "Blueming", "Wayne", "Morris", "Bourbon", "Calvin",
							"Mushi", "Jasper", "Howard", "Sulli", "Taeyeon", "IU", "Tiffany", "Sunny", "Jessica", "Yoona",
						  };
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
