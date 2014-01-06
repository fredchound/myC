#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int valueGlobal = 5;

void main()
{
	pid_t pid;

	pid = fork();

	valueGlobal = 10;
	
	if (pid==0) {  // in Child
		printf("Child: address before write is %p\n", &valueGlobal);
		valueGlobal+=15;
		printf("Value in child is %d \n", valueGlobal);
		printf("Child: address after write is %p \n", &valueGlobal);
	} else if (pid>0){  // in parent
		printf("Parent: address before write is %p \n", &valueGlobal);
		wait(NULL);
		printf("Value in parent is %d \n", valueGlobal);
		printf("Parent: value after write is %p \n", &valueGlobal);
	}

}
