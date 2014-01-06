#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>


void main()
{
	pid_t pid1, pid2;

	pid1 = fork();
		
	if(pid1==0){
		pid2 = getpid();
		printf("child: pid1 is %d\n", pid1);
		printf("child: pid2 is %d\n", pid2);

	} else {
		pid2 = getpid();
		printf("parent: pid1 is %d\n", pid1);
		printf("parent: pid2 is %d\n", pid2);
		wait(NULL);
	}

}
