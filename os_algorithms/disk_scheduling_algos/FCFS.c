#include <stdio.h>
#include <stdlib.h>

void FCFS(int req[], int n, int head){
    int totalSeek = 0; // total head movement
    int current = head; // Current head position of the disk

    printf("\n FCFS DISK SCHE\n");
    printf("Sequences: %d", head);

    for(int i = 0; i < n; i++) {
        int seek = abs(req[i] - current); // calculate seek distance
        totalSeek += seek;
        current = req[i];
        printf(" -> %d", current);
    }

    printf("\nTotal Seek Operations: %d\n", totalSeek);
}

int main(){
    int requests[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int n = sizeof(requests) / sizeof(int);
    int head = 53;
    int diskSize = 200;

    printf("Disk Request Queue: ");
    for(int i = 0; i < n; i++){
        printf("%d ", requests[i]);
    }

    printf("\nInitial Head Position: %d\n", head);
    printf("Disk Size: %d cylinders\n", diskSize);

    FCFS(requests, n, head);

    return 0;
}