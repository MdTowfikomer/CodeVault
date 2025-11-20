#include <stdio.h>
#include <stdbool.h>

void FIFO(int pages[], int n, int capacity){
    int frame[capacity]; // array that stores page
    int pageFaults = 0; // status pages
    int index = 0;

    for(int i = 0; i < capacity; i++){
        frame[i] = -1;
    }

    printf("page\tFrames\tPage Fault\n");

    for(int i = 0; i < n; i++){
        bool found = false; // marks as false

        // check for repeated pages
        for(int j = 0; j < capacity; j++){
            if(frame[j] == pages[i]){  
                found = true;  // if true break
                break;
            }
        }

        if(!found){
            frame[index] = pages[i];
            index = (index + 1) % capacity; // circular queue..!! 
            pageFaults++;

            printf("%d\t", pages[i]);
            for(int j = 0; j < capacity; j++){
                if(frame[j] != -1){
                    printf("%d ", frame[j]);
                } else{
                    printf("- ");
                }
            }
                printf("\tYes\n");
        } else{
                printf("%d\t", pages[i]);
                for(int j = 0; j < capacity; j++){
                    if(frame[j] != -1){
                        printf("%d ", frame[j]);
                    } else{
                        printf("- ");
                    }
                }
                printf("\tNo\n");
        }
    }
    printf("\nTotal Page Faults: %d\n", pageFaults);
    printf("Page Fault Rate: %.2f%%\n", (float)pageFaults * 100 / n);
}


int main(){
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages)/sizeof(int);

    int capacity = 3;

    printf("Page Referenece String: ");
    for(int i =0; i < n; i++){
        printf("%d ", pages[i]);
    }

    printf("\nNumber of Frames: %d\n", capacity);

    FIFO(pages, n, capacity);

    return 0;
}
