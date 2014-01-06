#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

#define S 5

int nums[S] = {0, 1, 2, 3, 4};

void main()
{
	pid_t pid;
 	int i;

	pid = fork();
		
	if(pid==0){
		for(i = 0; i<S; i++){
			nums[i]*=-i;
			printf("child: %d ", nums[i]);
		}
	} else {
//		wait(NULL);
		for(i = 0; i<S; i++){
			nums[i]*=-i;
			printf("parent: %d ", nums[i]);
		}
	}

}
