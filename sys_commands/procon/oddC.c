//Child
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char *argv[]){
  int k = 0,n = 1;
  void *ptr1;
  int shm_fd = shmget((key_t) 1122,4096,0666);
  ptr1 = shmat(shm_fd,NULL,0666);
  printf("child:\n");
  int i = atoi(argv[1]);

  while(k<i){
    sprintf(ptr1,"%d  ",n);
    printf("%d  ",n);
    ptr1+=strlen(ptr1);
    k++;    
    n = n+2;
  }
  printf("\n");
}

//OUTPUT
// cc oddP.c       
// shivam@192 procon % cc oddC.c -o odd
// shivam@192 procon % ./a.out 5       
// child:
// 1  3  5  7  9  
// Parent: Child completed
// Parent is printing:
// 1  3  5  7  9