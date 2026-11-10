#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX 100

struct msg_buffer
{
    long msg_type;
    char msg_text[MAX];
};

int main()
{
    key_t key;
    int msgid;
    struct msg_buffer message;

    key = ftok("progfile", 65);

    msgid = msgget(key, 0666 | IPC_CREAT);

    message.msg_type = 1;

    printf("Write Data: ");
    fgets(message.msg_text, MAX, stdin);

    msgsnd(msgid, &message, sizeof(message.msg_text), 0);

    printf("Data sent is: %s\n", message.msg_text);

    return 0;
}