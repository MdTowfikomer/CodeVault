#include <stdio.h>

int main(){
    int n, i; 
    float awt = 0, atat = 0; // average waiting time and turnaround time

    printf("Enter no of processes:");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n];

    printf("Enter burst times:\n");
    for(i= 0; i< n; i++){
        printf("P%d: ", i+1); //remember
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;
    for(i = 1; i <n; i++){
        wt[i] = wt[i-1] + bt[i-1];
    }

    for(i = 0; i < n; i++){
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];
    }

    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i< n; i++){
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage WT: %.2f", awt/n);
    printf("\nAverage TAT: %.2f", atat/n);

    return 0;

}
