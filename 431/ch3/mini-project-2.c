/**
 * Mini-project 2
 *
 * Next create a similar program but this one must print each unique PID exactly 
 * once from each of the 8 processes. Name your code file mini-project-2.c
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid;

	printf("%d\n",getpid());
	pid = fork();

    if (pid == 0)
	    printf("%d\n",getpid());

	pid = fork();

    if (pid == 0)
        printf("%d\n",getpid());

	pid = fork();

    if (pid == 0)
        printf("%d\n",getpid());

	return 0;
}
