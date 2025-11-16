#include <stdio.h>

int main(){
    int n, i, j, temp;
    float awt = 0, atat = 0;

    printf("Enter no of processes: ");
    scanf("%d", &n);

    int p[n], bt[n], wt[n], tat[n]; // here we got process array as well
 
    printf("Enter brust times:\n");
    for(i = 0; i < n; i++){
        p[i] = i + 1; // [1, 2,3, 4, ....n]
        printf("P%d:", i+1);
        scanf("%d", &bt[i]);
    }

    // Sort by burst time (SJF)
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            if(bt[i] > bt[j]){ //bt: 5, 2, 3, 1, 4 //p: 1, 2, 3, 4, 5
                temp = bt[i];   //after sort: bt=> 1, 2, 3, 4, 5
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];    // 4, 2, 3, 5, 1
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    

    // Calculating the waiting time and turnaround time
    wt[0] = 0; // Waiting time for the first process is 0
    for(i = 1; i < n; i++){
        wt[i] = wt[i-1] + bt[i-1];
    }

    for(i = 0; i < n; i++){
        tat[i] = wt[i] + bt[i];

        awt += wt[i];
        atat += tat[i];
    }

    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++){
        printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage WT: %.2f", awt/n);
    printf("\nAverage TAT: %.2f\n", atat/n);

    return 0;
}