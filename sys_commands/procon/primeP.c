#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<sys/mman.h>

int main(int argc,char *argv[])
{
 pid_t pid;
 int i;
 int shm_fd;
 void *ptr;
 if(argc>2)
 {
  sscanf(argv[1],"%d",&i);
  if(i<1)
  {
   printf("error\n");
   return 0;
  }
 }
 else
 {
  printf("not passing n\n");
  exit(0);
 }
 pid=fork();
 if(pid==0)
 {
  execlp("./prime","prime",argv[1],argv[2],NULL);
 } 
 else
 {
  printf("parent\n");
  wait(NULL);
  printf("child completed\n");
  shm_fd=shm_open("os",O_RDONLY,0666);
  ptr=mmap(0,4096,PROT_READ,MAP_SHARED,shm_fd,0);
  printf("parent printing\n");
  printf("%s",(char *)ptr);
  shm_unlink("os");
 }
 return 0;
}