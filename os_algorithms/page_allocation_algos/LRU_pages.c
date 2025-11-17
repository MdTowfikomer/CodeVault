#include <stdio.h>
#include <stdbool.h>

void LRU(int pages[], int n, int capacity){
    int frame[capacity];
    int recent[capacity]; // store the time when last used
    int pageFaults = 0;

    for(int i = 0; i < capacity; i++){
        frame[i] = -1;
        recent[i] = -1;
    }

    printf("Page\tFrame\tPage Fault\n");

    for(int i= 0; i < n; i++){
        bool found = false;
        int frameIdx = -1;

        for(int j = 0; j < capacity; j++){
            if(frame[j] == pages[i]){
                found = true;
                frameIdx = j;
                recent[j] = i;
                break;
            }
        }

        if(!found){
            int emptyIdx = -1;
            for(int j = 0; j < capacity; j++){
                if(frame[j] == -1){
                    emptyIdx = j;
                    break;
                }
            }
            if(emptyIdx != -1){
                frame[emptyIdx] = pages[i];
                recent[emptyIdx] = i;
            } else{
                int lruIdx = 0;
                int lruTime = 
            }
        }

    }
}