#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct process{
    int pid, at, bt, ct, wt, tat, rt, start_time;
};
int main()
{
    int n;
    printf("Enter total no. of processes: ");
    scanf("%d", &n);
    struct process arr[n];

    printf("Enter arrival time & burst time for each process\n");
    for (int i=0; i<n; i++){
        struct process *ptr = arr+i;
        ptr->pid = i+1;
        printf("Process %d: ", ptr->pid);
        scanf("%d %d", &ptr->at, &ptr->bt);
    }

    int current_time=0, completed=0;
    bool is_completed[100] = {false};
    while (completed!=n)
    {
        int min_index = -1;
        int minimum = 999999;
        for (int i=0; i<n; i++){
            if (arr[i].at<=current_time && is_completed[i]==false){
                if (arr[i].bt < minimum){
                    minimum = arr[i].bt;
                    min_index = i;
                }
                if (arr[i].bt == minimum){
                    if (arr[i].at < arr[min_index].at){
                        minimum = arr[i].bt;
                        min_index = i;
                    }
                }
            }
        }

        if (min_index==-1)
            current_time+=1;
        else{
            struct process *ptr = arr+min_index;
            ptr->start_time = current_time;
            ptr->ct = ptr->start_time + ptr->bt;
            ptr->tat = ptr->ct - ptr->at;
            ptr->wt = ptr->tat - ptr->bt;
            ptr->rt = ptr->wt;
        }

        completed++;
        is_completed[min_index]=true;
        current_time = arr[min_index].ct;
    }
    printf("\nP#\tAT\tBT\tCT\tWT\tTAT\tRT\n");
    for (int i=0; i<n; i++){
        struct process *ptr = arr+i;
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", ptr->pid,ptr->at,ptr->bt,ptr->ct,ptr->wt,ptr->tat,ptr->rt);
    }
    return 0;
}