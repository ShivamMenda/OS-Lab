#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h> 
#include <fcntl.h>//header in the C POSIX library that contains constructs that
#define BUFFER_SIZE 30
int main() { 
	int fd,n; 
	char buffer[BUFFER_SIZE]; 
	fd = open("./copy.txt", O_RDWR); //open(const char *__file, int __oflag, int mode) 
	/*path to file which you want to use; flags-O_RDONLY: read only, O_WRONLY: write 
	only, O_RDWR: read and write, O_CREAT: create file if it doesn’t exist, 
	O_EXCL: prevent creation if it already exists*/ 
	printf("File discriptor is %d\n", fd); 
	if (fd == -1) 
	{ 
		printf("Failed to open file.\n"); 
		exit(0);
	}
	printf("Reading first 10 characters from file: \n");
	n = read(fd, buffer, 10); 
	write(1, buffer, n);
	 //lseek is a system call that is used to change the location of the read/write pointer of a file descriptor 
	printf("\nSkipping 5 characters from current position in the file: \n"); 
	lseek(fd, 5, SEEK_CUR);//SEEK_CUR - the file offset shall be set to its current location plus offset. 
	n = read(fd, buffer, 10); 
	write(1, buffer, n);
	printf("\nGoing 10 characters before the current position in the file: \n"); 
	lseek(fd, -10, SEEK_CUR);
	 
	n = read(fd, buffer, 10); 
	write(1, buffer, n); 
	printf("\nGoing to 5th last character in the file: \n"); 
	lseek(fd, -5, SEEK_END);//SEEK_END -the file offset shall be set to the size of the file plus offset
	n = read(fd, buffer, 7); 
	write(1, buffer, 5); printf("\nGoing to the 3rd character in the file: \n");
	lseek(fd, 3, SEEK_SET);//SEEK_SET-the file offset shall be set to offset bytes. 
	n = read(fd, buffer, 5); 
	write(1, buffer, n);
	return 0;
}
