#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<sys/wait.h>

int main(int argc,char *argv[])
{
    int i,j;
    pid_t pid;
    int k;
    int n1,n2,n3;
    const int SIZE = 4096;
        int shm_fd;
    void *ptr;
    if (argc > 2)
    {
        sscanf(argv[1], "%d", &i);
        sscanf(argv[2], "%d", &j);
        
        if (i < 1)
        {
            printf("Error input: %d\n", i);
            return 0;
        }
        if (j < 1)
        {
            printf("Error input: %d\n", j);
            return 0;
        }
    }
    else
    {
      printf("Error: not passing N in command line\n");
      exit(0);
    }
    pid = fork();
    if (pid == 0)// CHILD
    {   
        execlp("./prime","prime",argv[1],argv[2],NULL);
    }
    else if (pid > 0)
    {
        wait(NULL);
        printf("\nPARENT: child completed\n");
        shm_fd = shm_open("OS", O_RDONLY, 0666);
        ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
        printf("Parent printing:\n");
        printf("%s ", (char *)ptr);
        shm_unlink("OS");
    }
    return 0;
}