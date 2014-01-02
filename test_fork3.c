#include  <stdio.h>
#include  <sys/types.h>

void main()
{
  if(fork() && fork())
      fork();
  if( fork() || fork() )
      fork();
  printf("Hello world. \n");

}
