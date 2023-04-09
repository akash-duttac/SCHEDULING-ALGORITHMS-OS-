#include <stdio.h>
int main(){
    int p[10]={0}, bt[10]={0}, wt[10]={0}, tat[10]={0}, ct[10]={0};
    int n, pos, temp, totalTAT=0, totalWT=0, i, j;
    printf("Enter total no. of processes: ");
    scanf("%d", &n);
    printf("Enter the burst times\n");
    for (i=0; i<n; i++){
        printf("P%d: ", i+1);
        scanf("%d", &bt[i]);
        p[i] = i+1;
    }
    //sorting the burst timed
    for (i=0; i<n; i++){
        pos = i;
        for (j=i+1; j<n; j++)
            if (bt[j] < bt[pos])
                pos = j;

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }
    wt[0] = 0;
    //calculating the waiting time
    for (i=1; i<n; i++){
        wt[i] = 0;
        for (j=0; j<i; j++)
            wt[i] += bt[j]; //each wt is added bt of all completed processes
        totalWT += wt[i];
    }
    //completion time
    for (i = 0; i < n; i++) {
        if (i == 0) {
            ct[i] = bt[i];
        } else {
            ct[i] = ct[i-1] + bt[i];
        }
    }
    printf("\nP#\tBT\tWT\tTAT\tCT\n");
    for (i=0; i<n; i++){
        tat[i] = bt[i] + wt[i]; //each tat
        totalTAT += tat[i];
        printf("%d\t%d\t%d\t%d\t%d\n", p[i],bt[i],wt[i],tat[i],ct[i]);
    }
    printf("Avg tat = %.2f", (float)totalTAT/n);
    printf("\nAvg wt = %.2f", (float)totalWT/n);
}