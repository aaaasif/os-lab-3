#include <stdio.h>
#include <time.h> 

int display1(char * string);

int main()
{
   char string[]="Hello World!";
	while (1)
	{
		display1(string);
		sleep(1);
	}
	
}

int display1(char* string)
{
	printf("the orginal string is %s\n",string);
}


