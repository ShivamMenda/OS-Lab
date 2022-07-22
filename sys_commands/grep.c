#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char file[10],pat[10],temp[200];
    FILE *fp;
    printf("Enter filename:");
    scanf("%s",file);
    printf("Enter pat:");
    scanf("%s",pat);

    fp=fopen(file,"r");
    while (!feof(fp))
    {
        fgets(temp,100,fp);
        if (strstr(temp,pat))
        {
            printf("%s",temp);
        }
        else
        {
            printf("Not found\n");
        }
        
    }
    fclose(fp);    
}