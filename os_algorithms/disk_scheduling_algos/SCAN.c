#include <stdio.h>
#include <stdlib.h>

void SCAN_RIGHT(int req[], int n, int head, int diskSize){
    int totalSeek = 0;
    int current = head;

    // Sort the requests (same as SJF)
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(req[i] > req[j]){
                int temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    printf("\nSCAN (Right Direction) DISK SCHEDULING\n");
    printf("Sequence: %d", head);

    // 1. Service requests to the RIGHT of head
    for(int i = 0; i < n; i++){
        if(req[i] >= head){
            int seek = abs(req[i] - current);
            totalSeek += seek;
            current = req[i];
            printf(" -> %d", current);
        }
    }

    printf("\nBefore this:\n");
    // 2. Go to END of disk
    int end = diskSize - 1;
    if(current != end){
        totalSeek += abs(end - current);
        current = end;
        printf(" -> %d", current);
    }
    printf("\nAfter this:\n");

    // 3. Now service remaining LEFT requests (from end to start of list)
    for(int i = n - 1; i >= 0; i--){
        if(req[i] < head){
            int seek = abs(req[i] - current);
            totalSeek += seek;
            current = req[i];
            printf(" -> %d", current);
        }
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
    printf("\nDisk Size: %d cylinders\n", diskSize);

    SCAN_RIGHT(requests, n, head, diskSize);

    return 0;
}
