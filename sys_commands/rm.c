#include<stdio.h>

int main()
{
    char filename[10];
    printf("Enter file name:");
    scanf("%s",filename);

    if (remove(filename)==0)
    {
        printf("File was removed\n");
    }
    else
    {
        printf("File can't be removed");
    }
    
    
}