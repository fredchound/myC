#include <stdio.h>

#define N 12


int max(int a, int b)
{
    if  (a>b)
        return a;
    else
        return b; 
    
}

int min(int a, int b)
{
    if  (a>b)
        return b;
    else
        return a; 
    
}


int main()
{
 
     int A[N] = {0,1,0,2,1,0,1,3,2,1,2,1}; 
     int max_left[N] = {0};
     int max_right[N] = {0};
     
     for (int i=1; i<N; i++) {
         max_left[i] = max(max_left[i-1], A[i-1]);
         max_right[N-1-i] = max(max_right[N-i], A[N-i]);
         
     }    
 
     for (int i=0;i<N;i++){
         printf("%d", A[i]);
     }
     printf("\n");
     
     for (int i=0;i<N;i++){
         printf("%d", max_left[i]);
     }
     printf("\n");
     
     for (int i=0;i<N;i++){
         printf("%d", max_right[i]);
     }
     printf("\n");  
    
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int height = min(max_left[i], max_right[i]);
         if (height > A[i]) {
          sum += height - A[i];
         }
    }
    printf("sum %d\n", sum);
    
    
    return sum;
     
}

