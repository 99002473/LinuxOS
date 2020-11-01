#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int fdisp,nbytes;
	fdisp=open("file1.txt",O_RDONLY);
	if(fdisp<0)
	{
		perr("open");
		exit(1);
	}
	int length=135;
	char buffer[length];
	nbytes=read(fdisp,buffer,length);
	if(nbytes<0)
	{
		perr("read");
		exit(2);
	}
    buffer[length]='\0';
    printf("%s\n",buffer);
    close(fdisp);
}