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

    printf("Page\tFrame\t\tPage Fault\n");

    for(int i= 0; i < n; i++){
        bool found = false;

        for(int j = 0; j < capacity; j++){
            if(frame[j] == pages[i]){
                found = true;
                recent[j] = i;
                break;
            }
        }

        if(!found){ // [-1, 3, 1]
            pageFaults++;
            int emptyIdx = -1; 
            for(int j = 0; j < capacity; j++){
                if(frame[j] == -1){
                    emptyIdx = j; // 0
                    break;
                }
            }
            if(emptyIdx != -1){ // 0 != -1 (true)
                frame[emptyIdx] = pages[i]; 
                recent[emptyIdx] = i;
            } else{
                int lruIdx = 0;
                int lruTime = recent[0];
                for(int j = 1; j < capacity; j++){
                    if(recent[j] < lruTime){
                        lruTime = recent[j];
                        lruIdx = j;
                    }
                }
                frame[lruIdx] = pages[i];
                recent[lruIdx] = i;
            }
        }

        printf("%d\t", pages[i]);
        for(int j = 0; j < capacity; j++){
            if(frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        if(!found) printf("\t\tYes");
        else printf("\t\tNo");
        printf("\n");
    }
    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main(){
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages)/sizeof(pages[0]);
    int capacity = 3;

    printf("Page Reference String: ");
    for(int i = 0; i < n; i++){
        printf("%d ", pages[i]);
    }
    printf("\nFrame Capacity: %d\n\n", capacity);

    LRU(pages, n, capacity);

    return 0;
}