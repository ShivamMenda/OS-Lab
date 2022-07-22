#include <stdio.h>
#include<stdlib.h>
typedef struct process
{
    int pid, at, bt, ct, tt, wt, flag;
} pro;

int temp[10];
void turnaroundtime(pro p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].tt = p[i].ct - p[i].at;
    }
}

void waittime(pro p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].wt = p[i].tt - temp[i];
        // p[i].rt = p[i].wt;
    }
}

void sortat(pro p[], int n)
{
    pro t, *p1, *p2;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[i].at > p[i + 1].at)
            {
                p1 = &p[i];
                p2 = &p[i + 1];
                t = *p1;
                *p1 = *p2;
                *p2 = t;
                int a = temp[i];
                temp[i] = temp[i + 1];
                temp[i + 1] = a;
            }
        }
    }
}

void schedule(pro p[], int n, int quantum)
{
    int time = p[0].at;
    int completed = 0;
    int cnt = 0;

    int *wait = (int *)malloc(sizeof(int) * n);
    int f = 0;
    int r = -1;
    r = (r + 1) % n;
    cnt++;
    wait[r] = 0;
    p[0].flag = 1;

    while (completed != n)
    {

        int cur = wait[f];

        f = (f + 1) % n;

        if (p[cur].bt > quantum)
        {
            p[cur].bt = p[cur].bt - quantum;
            time = time + quantum;
        }
        else
        {

            printf("%d\n", p[cur].bt);
            time = time + p[cur].bt;
            p[cur].bt = 0;
           
        }
        p[cur].ct = time;
        cnt--;

        for (int i = 0; i < n && p[i].at <= time; i++)
        {
            if (i == cur || p[i].flag == 1 || p[i].bt == 0)
                continue;
            r = (r + 1) % n;
            p[i].flag = 1;
            wait[r] = i;
            cnt++;
        }

        if (p[cur].bt > 0)
        {
            r = (r + 1) % n;
            wait[r] = cur;
            cnt++;
        }
        else
        {
            completed++;
        }
    }
}
void avgtime(pro p[], int n, int quantum)
{
    schedule(p, n, quantum);
    turnaroundtime(p, n);
    waittime(p, n);
    printf("\npid\tat\tbt\tct\ttt\twt\trt\n");
    int tott = 0, totwt = 0;
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, temp[i], p[i].ct, p[i].tt, p[i].wt);
        tott += p[i].tt;
        totwt += p[i].wt;
    }

    printf("Average tt = %f\n", (float)tott / (float)n);
    printf("Average tt = %f\n", (float)totwt / (float)n);
}
int main()
{
    pro p[10];
    int n;
    int quantum;
    printf("Enter number of processes\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter pid, arrival time and burst time of process %d : \n", i + 1);
        scanf("%d %d %d", &p[i].pid, &p[i].at, &p[i].bt);
        temp[i] = p[i].bt;
        p[i].ct = 0;
        p[i].flag = 0;
    }
    printf("Enter quantum\n");
    scanf("%d", &quantum);
    sortat(p, n);
    avgtime(p, n, quantum);
    return 0;
}