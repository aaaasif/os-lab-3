#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    pid= fork();

    printf("hello world\n");

    return 0;

}
