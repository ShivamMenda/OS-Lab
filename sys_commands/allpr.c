//TO DEMONSTRATE EXIT(),GETPID(),GETPPID(),WAIT(),SLEEP(),EXECLP()
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() 
{
pid_t child_pid,my_pid,parent_pid,wid;
int i = 10;
child_pid = fork();
if (child_pid < 0) 
{
printf("Fork failed. Exiting!\n");
exit(0);
}
if (child_pid == 0) 
{
// Child process
  //printf("[CHILD] Before using exit syscall\n");
  //exit(0);
  printf("[CHILD] This is the child process.\n");
  my_pid = getpid();
  parent_pid = getppid();
  printf("[CHILD] My pid is %d\n", my_pid);
  printf("[CHILD] My parent's pid is %d\n", parent_pid);
  printf("[CHILD] i= %d\n",--i);
  printf("[CHILD] Child process going to load another program using execlp syscall\n");
  //execlp("/bin/pwd", "pwd", NULL);
  execlp("./ex","ex",NULL);
} 
else 
{
  // Parent process
  wid=wait(NULL);  
  printf("[PARENT] This is the parent process.\n");
  my_pid = getpid();
  parent_pid = getppid();
  printf("[PARENT] My pid is %d\n", my_pid);
  printf("[PARENT] Waiting for child to terminate\n");
  printf("[PARENT] Resuming after the termination of %d\n", wid);
  printf("[PARENT] My parent's pid is %d\n", parent_pid);
  printf("[PARENT] My child's pid is %d\n", child_pid);
   printf("[PARENT] i= %d\n",++i);
}
return 0;
}