#include <stdio.h>

int main(){
    int n, i, tq, time = 0, remain; // time allocated to all process
    float awt = 0, atat = 0;

    // same, taking no of process
    printf("Enter no of process:\n");
    scanf("%d", &n);
    remain = n; // remaining process left


    int bt[n], rem_bt[n], wt[n], tat[n]; // here we are tracking the remaining burst time as well

    // taking bt
    printf("Enter brust times:\n");
    for( i = 0; i<n; i++){  
        printf("P%d: ", i+1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i]; // before the while-loop the burst and rem_burst are same...!!
    }

    printf("Enter time quantum: "); // time for each process to process..!
    scanf("%d", &tq);

    // Round Robin Scheduling
    while(remain > 0){
        for(i = 0; i < n; i++){
            if(rem_bt[i] > 0){
               if(rem_bt[i] <= tq){
                time += rem_bt[i]; // add all the rem_bt to time
                rem_bt[i] = 0;  // initialize the rem_bt to 0 
                remain--;   // reduce one process
                tat[i] = time;  // add tat to the time taken by the process
               } else{
                time += tq; // add time quatum to the time..!
                rem_bt[i] -= tq; // 5-4 = 1
               }
            }
        }
    }

    //calculating the waiting time
    for(i = 0; i < n; i++){
        wt[i] = tat[i] - bt[i];
        awt += wt[i];
        atat += tat[i];
    }

    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++){
        printf("P%d\t%d\t%d\t%d\n",i+1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage WT: %.2f", awt/n);
    printf("\nAverage TAT: %.2f", atat/n);

    return 0;
}