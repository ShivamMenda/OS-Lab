#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<unistd.h>
#include<sys/shm.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
 void *ptr;
 int shm_fd=shm_open("os",O_CREAT|O_RDWR,0666);
 ftruncate(shm_fd,4096);
 ptr=mmap(0,4096,PROT_WRITE,MAP_SHARED,shm_fd,0);
 printf("child\n");
 int i=atoi(argv[1]);
 int j=atoi(argv[2]);
 if(i==1 || i==2)
 {
  sprintf(ptr,"2  ");
  printf("2  ");
  ptr+=strlen(ptr);
  i++;
  if(i==2)
   i++;
 }
 for(int m=i;m<=j;m++)
 {
  int flag=0;
  for(int n=2;n<m;n++)
   if(m%n==0)
    flag=1;
  if(flag==0)
  {
   sprintf(ptr,"%d  ",m);
   printf("%d  ",m);
   ptr+=strlen(ptr);
  }
 } 
 
}