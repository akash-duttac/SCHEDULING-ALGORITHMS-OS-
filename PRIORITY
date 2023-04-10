#include <stdio.h>
#include <stdlib.h>
struct process{
    int pid, priority, bt, wt, ct, tat;
};
int main() {
    int n;
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    struct process *arr = (struct process *)malloc(n*sizeof(struct process));
    printf("Enter the priority & burst time of the processes\n");
    for (int i=0; i<n; i++){
        printf("Process %d: ", i+1);
        scanf("%d %d", &arr[i].priority, &arr[i].bt);
        arr[i].pid = i+1;
    }

    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            if (arr[i].priority > arr[j].priority){
                struct process temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

    // waiting time of each process
    int totalWT = 0;
    arr[0].wt = 0;
    for (int i=1; i<n; i++){
        arr[i].wt = arr[i-1].wt + arr[i-1].bt;
        totalWT += arr[i].wt;
    }

    // completion time of each process
    for (int i=0; i<n; i++)
        arr[i].ct = arr[i].wt +arr[i].bt;

    printf("\nP#\tPriority\tBT\tWT\tCT\n");
    for (int i=0; i<n; i++)
        printf("%d\t%d\t\t%d\t%d\t%d\n",
               arr[i].pid, arr[i].priority,arr[i].bt,arr[i].wt,arr[i].ct);
    printf("\nAverage Waiting Time = %.2f", (float)totalWT/n);
    return 0;
}
