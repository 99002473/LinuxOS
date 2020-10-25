/* mini shell that can take 6 arguments*/
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
    pid_t ret_stat;
    int stat;
    int cmd_exe;
    char Comm[10];
    printf("Enter your command:");
    scanf("%s", Comm);                  
    ret_stat=fork();
    
    if(ret_stat<0)
    {
        perror("fork");
        exit(1);
    }
    if(ret_stat==0)
    {
        cmd_exe=execlp(Comm,Comm);
        if(cmd_exe<0)
        {
            perror("execlp");
            exit(2);
        }
        exit(0);
    }
    else
    {
        waitpid(-1,&stat,0); //wait(&stat);
        printf("parent--child exit stat=%d\n",
			WEXITSTATUS(stat));
    }
}