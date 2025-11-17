#include <stdio.h>
#include <stdlib.h>

void SSTF(int req[], int n, int head){ // 98
    int totalSeek = 0; // total head
    int current = head;     // 53
    int visited[n]; // tracking which req is used

    for(int i= 0; i < n; i++){
        visited[i] = 0; // 0, 0, 0, 0...
    }

    printf("SSTF Disk Scheduling\n");
    printf("Sequence: %d", head); // 53

    for(int count = 0; count < n; count++){
        int minSeek = 9999; // large value to find min   // INT_MAX(INFINITY)
        int minIndex = -1;  // index of closed req  //minIdx (-1 = not found)

        for(int i = 0; i < n; i++){ 
            if(!visited[i]){ // ? [0, 0, 0,]
                int seek = abs(req[i] - current);  // head = 98 - 53 => 45,  1. 183-53 => 130, 2. 37-53 => 16

                if(seek < minSeek){ // 45 < 9999 (true); 2. 130 < 45 (false); 16 < 45(true)
                    minSeek = seek; // 45 // 16
                    minIndex = i; // 0 // 2
                }// 0. mS = 45, min = 0; 2. mS = 16, minIdx = 2;
            }
        }

        visited[minIndex] = 1; // [0, 0, 0, 0, 0, 1, 0]
        totalSeek += minSeek;  // 65 
        current = req[minIndex];    
        printf(" ->%d", current);
    }

    printf("\nTotal Seek Operations: %d\n", totalSeek);

}

int main(){
    int requests[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int n = sizeof(requests)/sizeof(int);
    int head = 53;
    int diskSize = 200;

    printf("Disk Request Queue: ");
    for(int i = 0; i < n; i++){
        printf("%d ", requests[i]);
    }

    printf("\nInitial Head Position: %d\n", head);
    printf("Disk Size: %d cylinders\n", diskSize);

    SSTF(requests, n, head);

    return 0;
}