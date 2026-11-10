#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    key_t key = 1234;
    int shmid;
    char *str;

    shmid = shmget(key, 1024, 0666);

    str = (char *)shmat(shmid, NULL, 0);

    printf("Data read from shared memory: %s\n", str);

    shmdt(str);

    return 0;
}