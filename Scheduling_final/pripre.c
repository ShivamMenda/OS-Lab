#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

struct process_struct
{
  int pid;
  int at;
  int bt;
  int priority;
  int ct,wt,tat,rt,start_time;
}ps[100];

int main()
{
    int n;
    bool is_completed[100]={false},is_first_process=true;
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
    for(int i=0;i<n;i++)
    {
        printf("\nEnter Process %d Priority: ",i);
        scanf("%d",&ps[i].priority);
    }

    while(completed!=n)
    {
        //find process with min. burst time in ready queue at current time
        int max_index = -1;
        int maximum = -1;
        for(int i = 0; i < n; i++) {
            if(ps[i].at <= current_time && is_completed[i] == 0) {
                if(ps[i].priority > maximum) {
                    maximum = ps[i].priority;
                    max_index = i;
                }
                if(ps[i].priority== maximum) {
                    if(ps[i].at < ps[max_index].at) {
                        maximum= ps[i].priority;
                        max_index = i;
                    }
                }
            }
        }

   // printf("max Index=%d ",max_index);
    if(max_index==-1)
    {
        current_time++;
    }
    else
    {
       if(bt_remaining[max_index]==ps[max_index].bt)
           ps[max_index].start_time = current_time;

       bt_remaining[max_index]--;
       current_time++;
       printf("| P%d  %d",ps[min_index].pid,current_time);
       
       if(bt_remaining[max_index]==0)
       {
            ps[max_index].start_time = current_time;
            ps[max_index].ct = ps[max_index].start_time + ps[max_index].bt;
            ps[max_index].tat = ps[max_index].ct - ps[max_index].at;
            ps[max_index].wt= ps[max_index].tat - ps[max_index].bt;
            ps[max_index].rt = ps[max_index].start_time - ps[max_index].at;
            
            
            sum_tat +=ps[max_index].tat;
            sum_wt += ps[max_index].wt;
            sum_rt += ps[max_index].rt;
            completed++;
            is_completed[max_index]=true;
            
            printf("Max=%d ", ps[max_index].ct);
       }
    }
  }
  printf("\nProcess No.\tPriority\tAT\tCPU Burst Time\tCT\tTAT\tWT\tRT\n");
    for(int i=0;i<n;i++)
     printf("%d\t%d\t%d\t%d\t\t%d\t%d\t%d\t%d\n",ps[i].pid,ps[i].priority,ps[i].at,ps[i].bt,ps[i].ct,ps[i].tat,ps[i].wt,ps[i].rt);

    printf("\n");    
    

    printf("\nAverage Turn Around time= %f ",(float)sum_tat/n);
    printf("\nAverage Waiting Time= %f ",(float)sum_wt/n);
    printf("\nAverage Response Time= %f ",(float)sum_rt/n);   

}