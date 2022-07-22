#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char c;
    if (argc<1)
    {
        printf("File name not passed");
        exit(1);
    }
    fp=fopen(argv[1],"r");
    do
    {
        c=fgetc(fp);
        printf("%c",c);
    } while (c!=EOF);
    fclose(fp);
    
}