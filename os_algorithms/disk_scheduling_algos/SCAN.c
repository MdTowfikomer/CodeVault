#include <stdio.h>
#include <stdlib.h>

void SCAN(int req[], int n, int head, int end){
    int total = 0, start = head;

    // sort 
    for(int i = 0; i < n; i++){
        for(int j =i+1 ; j < n; j++){
            if(req[i] > req[j]){
                int t = req[i];
                req[i] = req[j];
                req[j] = t;
            }
        }
    }
    printf("Sequence: %d", head);

    // Right
    for(int i = 0; i < n; i++){
        if(req[i] >= start){
            total += abs(req[i] - head);
            head = req[i];
            printf(" -> %d", head);
        }
    }

    total += abs(end -head);
    printf(" -> %d", end);
    head = end;

    for(int i = n-1; i >= 0; i--){
        if(req[i] < start){
            total += abs(req[i] - head);
            head = req[i];
            printf(" -> %d", head);
        }
    }

    printf("\nTotal: %d\n", total);
}