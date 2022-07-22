#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include<sys/ipc.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
         int k,n1,n2,n3,flag=0,f;
         void *ptr;
         int shm_fd = shm_open("OS", O_CREAT | O_RDWR, 0666);
         ftruncate(shm_fd,4096);
         ptr = mmap(0,4096,PROT_WRITE, MAP_SHARED, shm_fd, 0);
         printf("CHILD:\n");
         int i=atoi(argv[1]);
         int j=atoi(argv[2]);
         for(k=i+1;k<=j;k++)
         {
                flag=0;
                for(j=2; j<=i/2; j++)
                {
                    if(i%j==0)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    printf("%d ",i);
                   sprintf(ptr,"%d ",i);
                    ptr += strlen(ptr); 
                } 
                      
	    }
}

