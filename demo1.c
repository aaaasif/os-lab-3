#include <stdio.h>

int display1(char * string);
int display2(char * string);

int main()
{
   char string[]="Hello World!";
	display1(string);
	display2(string);
}

int display1(char* string)
{
	printf("the orginal string is %s\n",string);
}

int display2(char * string1)
{
	char * string2;
	int size,i;
   
    size = strlen(string1);
	 string2 =(char*)malloc(size+1);

    for(i=0;i<size;i++)
       string2[size-i-1]=string1[i];
    string2[size+1]='\0';
    printf("the changed string is  %s\n ",string2);

} 
