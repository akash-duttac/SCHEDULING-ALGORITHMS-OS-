// C program to implement First Come First Serve CPU Scheduling Algorithm
#include <stdio.h>
#include <stdlib.h>
struct process{
    int pid, at, bt, ct, tat, wt;
};
int main()
{
    int n;
    printf("Enter total no. of processes: ");
    scanf("%d", &n);
    struct process arr[n];
    int total_time=0;
    printf("Enter arrival time and burst time of each process\n");
    for (int i=0; i<n; i++){
        struct process *ptr = arr + i;
        ptr->pid = i+1;
        printf("Process %d: ", ptr->pid);
        scanf("%d %d", &ptr->at, &ptr->bt);
        total_time += ptr->bt;
    }
    //sort the processes based on arrival times
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (arr[i].at > arr[j].at){
                struct process temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    // perform fcfs
    int current_time = 0;
    for (int i=0; i<n; i++){
        struct process *ptr = arr+i;
        if (ptr->at > current_time && current_time==0)
            current_time += ptr->at;
        else if (ptr->at > current_time) 
            current_time += current_time - ptr->at;
        current_time += ptr->bt;
        ptr->ct = current_time;
    }
    float avgWT=0, avgTAT=0;
    for (int i=0; i<n; i++){
        struct process *ptr = arr + i;
        ptr->tat = ptr->ct - ptr->at;
        ptr->wt = ptr->tat - ptr->bt;
        avgTAT += ptr->tat;
        avgWT += ptr->wt;
    }
    printf("\nP#\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i=0; i<n; i++){
        struct process *ptr = arr+i;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", ptr->pid, ptr->at, ptr->bt, ptr->ct, ptr->tat, ptr->wt);
    }
    printf("\nAverage Waiting Time = %.2f", avgWT/n);
    printf("\nAverage Turnaroung Time = %.2f", avgTAT/n);
    return 0;
}
