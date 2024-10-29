#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{
        int   sum=0;

        fork();

        for(int i=0; i<100; i++)
        {
                sleep(0.5);
                printf("PID %d: the value of i is %d\n", getpid(),i);
                fflush(stdout);
                sum+=i;
        }

        printf("the total is %d\n", sum);

        exit(0);
}

