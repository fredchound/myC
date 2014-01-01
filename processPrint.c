#include <stdio.h>
#include <sys/types.h>


void childProcess(int i)
{
	printf("Child prints: %d \n",i);
}


void parentProcess(int i)
{
	printf("Parent prints: %d \n",i);
}


int main()
{

	int i;
	pid_t pid;
	pid=fork();
	
	for(i=0;i<20;i++){
		if (pid)
			parentProcess(2*i+1);
		else
			childProcess(2*i);
	}

	return 1;

}
