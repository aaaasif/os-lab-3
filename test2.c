#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    pid_t pid;

    pid=fork();

    if (0==pid)
    {
        execl("/bin/ls","ls","-al",NULL);
        _exit(0);

    }
    else if (0<=pid)
    {
        printf("I am parent process\n");
        exit(0);
    }
}
