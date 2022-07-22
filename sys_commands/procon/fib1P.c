#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<sys/wait.h>
#include<string.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    int i;
    pid_t pid;
    int k;
    int n1,n2,n3;
    int shmid;
    void *ptr;
    if (argc > 1)
	{
	    sscanf(argv[1], "%d", &i);
	    if (i < 1)
	    {
	    printf("Error input: %d\n", i);
	    return 0;
	    }
	}
	else
	    {
	    return 1;
	    }

    pid=fork();
    if (pid==0)
    {
        execlp("./fib1", "fib1", argv[1], NULL);
    }
    else
    {
        shmid=shmget((key_t) 1122,4096,0666 | IPC_CREAT);
        ptr=shmat(shmid,NULL,0666);
        wait(NULL);
        printf("\nPARENT: child completed\n");
        printf("Parent printing:\n");
        printf("%s", (char *)ptr);
        shmdt(ptr);
    }
    
}