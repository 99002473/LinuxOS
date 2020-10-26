#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
  

void signal_hangup(); 
void signal_interact(); 
void signal_quit(); 
  
 
void main() 
{ 
    int pid; 
  
    /* child process */
    if ((pid = fork()) < 0) 
    { 
        perror("fork"); 
        exit(1); 
    } 
  
    if (pid == 0)
    { /* child */
        signal(SIGHUP, signal_hangup); 
        signal(SIGINT, signal_interact); 
        signal(SIGQUIT, signal_quit); 
        for (;;) 
            ; /* loop for ever */
    } 
  
    else /* parent */
    { 
        printf("\nParent: sends SIGHUP signal\n\n"); 
        kill(pid, SIGHUP); 
  
        sleep(3); 
        printf("\nParent: sends signal_interact signal\n\n"); 
        kill(pid, SIGINT); 
  
        sleep(3); 
        printf("\nParent: sends SIGQUIT signal\n\n"); 
        kill(pid, SIGQUIT); 
        sleep(3); 
    } 
} 
  
// signal_hangup() function definition 
void signal_hangup() 
  
{ 
    signal(SIGHUP, signal_hangup); /* reset signal */
    printf("Child  received a SIGHUP signal\n"); 
} 
  
// signal_interact() function definition 
void signal_interact() 
  
{ 
    signal(SIGINT, signal_interact); /* reset signal */
    printf("Child received a signal_interact signal\n"); 
} 
  
// signal_quit() function definition 
void signal_quit() 
{ 
    printf("Killed!\n"); 
    exit(0); 
} 