#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

//int valueGlobal = 0;

void main()
{
	pid_t pid;

	pid = fork();
		
	if(pid==0){
		printf("In child...\n");
		execlp("/bin/ls", "ls", NULL);
		printf("Line J. \n");
	} else {
		printf("Parent start waiting ...");
		wait(NULL);
		printf("Child completes.\n");
	}

}
