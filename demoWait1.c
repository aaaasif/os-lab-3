#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
 
int main(int arg, char *args[])
{
    pid_t pid = 0;
    int i = 0, ret = 0;
    for (i = 0; i < 10; i++)
    {
        pid = fork();
        if (pid == -1)
        {
            printf("fork() failed ! error message:%s\n", strerror(errno));
            return -1;
        }
        if (pid == 0)
        {
            //code here for child process
            printf("child %d  haved run!\n",getpid());
            exit(0);
        }
    }
    while (1)
    {
        //wait()  return the child process' id.
        ret = wait(NULL);
        printf("child process pid=%d is end\n", ret);
        if (ret == -1)
        {
            //父进程wait()函数阻塞过程中，有可能被别的信号中断，需要做异常处理
			//something is wrong when parent process block itself.
            if (errno == EINTR)
            {
                continue;
            }
            break;
        }
    }
    printf("game is over!\n");
    return 0;
}
