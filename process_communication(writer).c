#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    key_t key;
    int shmid;
    char *str;

    key = 1234;

    shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    str = (char *)shmat(shmid, NULL, 0);

    strcpy(str, "Hello from writer");

    printf("Data written into shared memory: %s\n", str);

    shmdt(str);

    return 0;
}