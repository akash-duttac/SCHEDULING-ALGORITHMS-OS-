//non preemptive priority scheduling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
struct process{
    int pid, at, bt, priority, ct, wt, tat, rt, start_time;
};
int main()
{
    int n;
    printf("Enter total no. of processes: ");
    scanf("%d", &n);
    struct process arr[n];
    for (int i = 0; i < n; i++)
    {
        struct process *ptr = arr + i;
        ptr->pid = i + 1;
        printf("Process %d\nEnter Arrival Time: ", ptr->pid);
        scanf("%d", &ptr->at);
        printf("Enter Burst Time: ");
        scanf("%d", &ptr->bt);
        printf("Enter priority: ");
        scanf("%d", &ptr->priority);
    }

    int completed=0, current_time=0;
    bool is_completed[100]={false};
    while (completed != n)
    {
        int max_index = -1;
        int maximum = -1;
        for (int i=0; i<n; i++){
            if (arr[i].at <= current_time && is_completed[i]==false){
                if (arr[i].priority > maximum){
                    maximum = arr[i].priority;
                    max_index = i;
                }
                if (arr[i].priority == maximum){
                    if (arr[i].at < arr[max_index].at){
                        maximum = arr[i].priority;
                        max_index = i;
                    }
                }
            }
        }

        if (max_index==-1)
        current_time++;
        else{
            int i = max_index;
            arr[i].start_time = current_time;
            arr[i].ct = arr[i].start_time + arr[i].bt;
            arr[i].tat = arr[i].ct - arr[i].at;
            arr[i].wt = arr[i].tat - arr[i].bt;
            arr[i].rt = arr[i].start_time - arr[i].at;
            completed++;
            is_completed[i] = true;
            current_time = arr[i].ct;
         }
    }


    float sumwt=0,sumtat=0,sumrt=0;
    printf("\nP#\tAT\tBT\tCT\tWT\tTAT\tRT\n");
    for (int i=0; i<n; i++){
        struct process *ptr = arr+i;
        sumwt+=ptr->wt;
        sumtat+=ptr->tat;
        sumrt+=ptr->rt;
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",ptr->pid,ptr->at,ptr->bt,ptr->ct,ptr->wt,ptr->tat,ptr->rt);
    }
    printf("\nAvg WT = %.2f", sumwt/n);
    printf("\nAvg TAT = %.2f", sumtat/n);
    printf("\nAvg RT = %.2f", sumrt/n);
    return 0;
}