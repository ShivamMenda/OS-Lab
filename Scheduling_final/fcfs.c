#include<stdio.h>
#include<stdlib.h>

struct process
{
    int pid;
    int at; //Given Arrival time
    int bt; //Given Burst time
    int ct,wt,tat,rt,start_time;
}ps[100];

int max(int a,int b)
{
    return a>b?a:b;
}

int comparatorAT(const void * a,const void * b)
{
    int x=((struct process *)a)->at;
    int y=((struct process *)b)->at;
    if (x<y)
    {
        return -1;
    }
    else if (x>=y)
    {
        return 1;
    }  
    return 1;   
}

int comparatorPID(const void * a,const void * b)
{
    int x=((struct process *)a)->pid;
    int y=((struct process *)b)->pid;
    if (x<y)
    {
        return -1;
    }
    else if (x>=y)
    {
        return 1;
    }
    return 1;     
}



int main()
{
    int n;
    printf("Enter the total no of processes:");
    scanf("%d",&n);
    float sum_tat=0,sum_wt=0,sum_rt=0;
    for (int i = 0; i <n; i++)
    {
        printf("Enter process %d arrival time: ",i);
        scanf("%d",&ps[i].at);
        ps[i].pid=i;    
    }
    for (int i = 0; i < n; i++)
    {
       printf("Enter process %d burst time: ",i);
       scanf("%d",&ps[i].bt);
    }
    

    //sort
    qsort((void *)ps,n,sizeof(struct process),comparatorAT);

    //Calculations
    for (int i = 0; i < n; i++)
    {
        ps[i].start_time= (i==0)? ps[i].at : max(ps[i].at,ps[i-1].ct);
        ps[i].ct=ps[i].start_time+ps[i].bt;
        ps[i].tat=ps[i].ct-ps[i].at;
        ps[i].wt=ps[i].tat-ps[i].bt;
        ps[i].rt=ps[i].wt;

        sum_tat+=ps[i].tat;
        sum_wt+=ps[i].wt;
        sum_rt+=ps[i].rt;
    }
    
    qsort((void *)ps,n,sizeof(struct process),comparatorPID);
    
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",ps[i].pid,ps[i].at,ps[i].bt,ps[i].ct,ps[i].tat,ps[i].wt);
    }

    printf("\n");
    printf("\nAverage TAT=%f",sum_tat/n);
    printf("\nAverage WT=%f",sum_wt/n);
    printf("\nAverage RT=%f",sum_rt/n);

}