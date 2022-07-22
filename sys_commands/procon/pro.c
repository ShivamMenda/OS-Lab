#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<sys/mman.h>

int main() 
{
	void * psm;
	char buf[10];
	int shmid1;
	shmid1 = shm_open("OS", O_CREAT | O_RDWR, 0666);
	ftruncate(shmid1, 1024);
	psm = mmap(0, 1024, PROT_WRITE, MAP_SHARED, shmid1, 0);
	printf("Key/ID/fd of the shared memory: %d\n", shmid1);
	printf("shared memory is attached at:%p\n", psm);
	printf("enter some data to write to shared memory\n");
	read(0, buf, 10);
	sprintf(psm, "%s", buf);
	return 0;
}