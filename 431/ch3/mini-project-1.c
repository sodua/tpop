/*
 * Solution to Mini-project-1
 * 
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t pid;

	pid = fork();
	
    if (pid == 0) { /* child process */
        printf("Bye!\n");
	} 
    else if (pid > 0) { /* parent process */
		printf ("Hi!\n");
	}	
    return 0;    
}
