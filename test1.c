#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (0==pid)
    {
        printf("I am child process\n");

    }
    else if(pid>0)
    {

        printf("I am parent process\n");

    }
    else
    {
        printf("fork error\n");
    }

    exit(0);


}
