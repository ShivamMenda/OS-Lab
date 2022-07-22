//to read from file and write into a new file
#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <fcntl.h> 
#define BUFFER_SIZE 300
int main() { 
	int fd1,fd2,n; 
	char buffer[BUFFER_SIZE]; 
	fd1 = open("./test.txt", O_RDONLY); 
	fd2 = open("./copy.txt", O_CREAT | O_WRONLY, 0666); //permission: read-4, wr-2, exe-1, user, group, others 
	printf("File discriptor for test.txt is %d and copied file is %d\n\n", fd1, fd2); 
	if (fd1 == -1 || fd2 == -1) { 
		printf("Failed to open file.\n"); 
		exit(0);
	}
	n = read(fd1, buffer, BUFFER_SIZE); 
	write(fd2, buffer, n); 
	printf("File has been created and the contents are copied successfully\n"); 
	return 0;
}