#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXCOUNT 20

int sharedCounter = 0;


pthread_mutex_t lock= PTHREAD_MUTEX_INITIALIZER;

void * thread_odd()
{
        while(sharedCounter<MAXCOUNT){
		sleep(1);
		pthread_mutex_lock(&lock);
		printf("Odd acquired lock-");
		if(sharedCounter%2 != 0) {                
			printf("Odd print: %d ", sharedCounter);
			sharedCounter++;
		}
                pthread_mutex_unlock(&lock);
		printf("-Odd released lock \n");
		
        }
}

void * thread_even()
{
        while(sharedCounter<MAXCOUNT){
		sleep(1);
		pthread_mutex_lock(&lock);
		printf("Even acquired lock-");	
		if(sharedCounter%2 == 0) {                
			printf("Odd print: %d ", sharedCounter);
			sharedCounter++;
		}
                pthread_mutex_unlock(&lock);
		printf("-Even released lock \n");

        }
}

int main()
{
        int status;
        pthread_t tid1,tid2;

        pthread_create(&tid1,NULL,&thread_odd, NULL);
        pthread_create(&tid2,NULL,&thread_even,NULL);
        pthread_join(tid1,NULL);
        pthread_join(tid2,NULL);
        
	return 0;
}
