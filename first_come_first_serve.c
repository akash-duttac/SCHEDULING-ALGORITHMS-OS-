// C program to perform CPU Scheduling Algorithm
#include <stdio.h>
int main()
{
    int at[10] = {0}, bt[10] = {0}, tat[10] = {0}, wt[10] = {0}, ct[10] = {0};
    int n, sum = 0, totalTAT = 0, totalWT = 0;
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    printf("Enter Arrival & Burst Time for each process: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }
    for (int i = 0; i < n; i++)
    {
        // completion time
        sum += bt[i];
        ct[i] += sum;
    }
    for (int i = 0; i < n; i++)
    {
        // turaround time
        tat[i] = ct[i] - at[i];
        totalTAT += tat[i];
        // waiting time
        wt[i] = tat[i] - bt[i];
        totalWT += wt[i];
    }
    printf("\n");
    printf("P#\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    printf("\nAverage TAT = %.2f\nAverage WT = %.2f", (float)totalTAT / n, (float)totalWT / n);
    return 0;
}
