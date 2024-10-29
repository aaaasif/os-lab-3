#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
 
int main(int arg,char *args[])
{
    pid_t pid=fork();
    if(pid==-1)
    {
        printf("fork() failed ! error message:%s\n",strerror(errno));
        return -1;
    }
    if(pid>0)
    {
        int status=0;
        printf("Parenet process\n");
        wait(&status);
        if(WIFEXITED(status))//WIFEXITED： wait if exit ed
        {
            printf("child process return exit code:%d\n",WEXITSTATUS(status));
        }else if(WIFSIGNALED(status))
        {
            printf("child process return signaled code:%d\n",WTERMSIG(status));
        }else if(WIFSTOPPED(status))
        {
            printf("child process return stopped code:%d\n",WSTOPSIG(status));
        }else
        {
            printf("other code！\n");
        }
    }else if(pid==0)
    {
        printf("i am child !\n");
        abort();
        //exit(100);
    }
    printf("game is over!\n");
    return 0;
}