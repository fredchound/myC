#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int valueGlobal = 0;

void main()
{
	pid_t pid;

	pid= fork();
	if( pid ==0 ){ 
		valueGlobal++;
		printf("Process %d created\n", valueGlobal);
		
	}

	pid = fork();
	if( pid ==0 ){ 
		valueGlobal++;
		printf("Process %d created\n", valueGlobal);
		
	}

	pid = fork();
	if( pid ==0 ){ 
		valueGlobal++;
		printf("Process %d created\n", valueGlobal);
		
	}

}
