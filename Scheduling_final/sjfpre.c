#include<stdio.h>
#include<limits.h>

struct process_struct
{
  int pid;
  int at;
  int bt;
  int ct,wt,tat,rt,start_time;
}ps[100];

int main()
{
    
    int n;
    int is_completed[100]={0},is_first_process=1;
    int bt_remaining[100];
    int current_time = 0;
    int completed = 0;
    printf("Enter total number of processes: ");
    scanf("%d",&n);    
    int sum_tat=0,sum_wt=0,sum_rt=0;

    for(int i=0;i<n;i++)
    {
        printf("\nEnter Process %d Arrival Time: ",i);
        scanf("%d",&ps[i].at);
        ps[i].pid = i ;
    }
    
    for(int i=0;i<n;i++)
    {
        printf("\nEnter Process %d Burst Time: ",i);
        scanf("%d",&ps[i].bt);
        bt_remaining[i]=ps[i].bt;
    }

    while (completed!=n)
    {
        //process with min burst time
        int min_index=-1;
        int minimum=INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (ps[i].at<=current_time && is_completed[i]== 0)
            {
                if (bt_remaining[i]<minimum)
                {
                    minimum=bt_remaining[i];
                    min_index=i;
                }
                if (bt_remaining[i] == minimum)
                {
                    if (ps[i].at<ps[min_index].at)
                    {
                        minimum=bt_remaining[i];
                        min_index=i;
                    }
                    
                }
                
                
            }
            
        }
        
        if(min_index==-1)
        {
            current_time++;
        }
        else
        {
            if (bt_remaining[min_index]==ps[min_index].bt)
            {
                ps[min_index].start_time = current_time;
                is_first_process=0;
            }
            bt_remaining[min_index] -= 1;
            current_time++; 
            printf("| P%d  %d",ps[min_index].pid,current_time);

            if(bt_remaining[min_index] == 0)
            {
                ps[min_index].ct = current_time;
                ps[min_index].tat = ps[min_index].ct - ps[min_index].at;
                ps[min_index].wt= ps[min_index].tat - ps[min_index].bt;
                ps[min_index].rt = ps[min_index].start_time - ps[min_index].at;
            
             
                sum_tat +=ps[min_index].tat;
                sum_wt += ps[min_index].wt;
                sum_rt += ps[min_index].rt;
                completed++;
                is_completed[min_index]=1;
                current_time=ps[min_index].ct;
            }
        }
    }
    //Output
    printf("\nProcess No.\tAT\tCPU Burst Time\tCT\tTAT\tWT\tRT\n");
    for(int i=0;i<n;i++)
     printf("%d\t\t%d\t%d\t\t%d\t%d\t%d\t%d\n",ps[i].pid,ps[i].at,ps[i].bt,ps[i].ct,ps[i].tat,ps[i].wt,ps[i].rt);

    printf("\n");    
    

    printf("\nAverage Turn Around time= %f ",(float)sum_tat/n);
    printf("\nAverage Waiting Time= %f ",(float)sum_wt/n);
    printf("\nAverage Response Time= %f ",(float)sum_rt/n);
    
}