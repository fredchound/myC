#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

//int valueGlobal = 0;

void main()
{
	pid_t pid;

	int valueLocal = 0;

	for (valueLocal=0; valueLocal<4; valueLocal++){
		pid = fork();
	
		if(pid==0) { //child
			printf("Local value is %d \n", valueLocal);
//			printf("Global value is %d \n", valueGlobal);
		}

//		valueGlobal ++; 
	}

}
