#include <stdio.h>
#include <stdbool.h>

// Function to implement the LRU page replacement algorithm
void LRU(int pages[], int n, int capacity){
    // 'frame' stores the pages currently in memory.
    int frame[capacity];
    // 'recent' stores the timestamp of the last time a page in a frame was used.
    // The index of 'recent' corresponds to the index of 'frame'.
    int recent[capacity]; 
    int pageFaults = 0;

    // Initialize all frames and recent timestamps to -1 to indicate they are empty.
    for(int i = 0; i < capacity; i++){
        frame[i] = -1;
        recent[i] = -1;
    }

    printf("Page\tFrame\t\tPage Fault\n");

    // Iterate through each page in the reference string.
    for(int i= 0; i < n; i++){
        bool found = false;

        // Check if the current page is already in one of the frames.
        for(int j = 0; j < capacity; j++){
            if(frame[j] == pages[i]){
                found = true;
                // If found (a "page hit"), update its last used time to the current time 'i'.
                recent[j] = i;
                break;
            }
        }

        // If the page was not found in any frame, a "page fault" occurs.
        if(!found){
            pageFaults++;
            int emptyIdx = -1; 
            // First, look for an empty frame.
            for(int j = 0; j < capacity; j++){
                if(frame[j] == -1){
                    emptyIdx = j;
                    break;
                }
            }
            // If an empty frame is available, use it.
            if(emptyIdx != -1){
                frame[emptyIdx] = pages[i]; 
                recent[emptyIdx] = i;
            } else{
                // If no empty frames, find the least recently used page to replace.
                int lruIdx = 0;
                int lruTime = recent[0];
                // Find the frame with the smallest 'recent' value (the oldest timestamp).
                for(int j = 1; j < capacity; j++){
                    if(recent[j] < lruTime){
                        lruTime = recent[j];
                        lruIdx = j;
                    }
                }
                // Replace the least recently used page with the new page.
                frame[lruIdx] = pages[i];
                recent[lruIdx] = i;
            }
        }

        // Print the current page and the state of the frames.
        printf("%d\t", pages[i]);
        for(int j = 0; j < capacity; j++){
            if(frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        // Indicate if a page fault occurred for this page.
        if(!found) printf("\t\tYes");
        else printf("\t\tNo");
        printf("\n");
    }
    // Print the total number of page faults.
    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main(){
    // The sequence of page references.
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    // The total number of pages in the reference string.
    int n = sizeof(pages)/sizeof(pages[0]);
    // The number of frames available in memory.
    int capacity = 3;

    printf("Page Reference String: ");
    for(int i = 0; i < n; i++){
        printf("%d ", pages[i]);
    }
    printf("\nFrame Capacity: %d\n\n", capacity);

    // Run the LRU algorithm simulation.
    LRU(pages, n, capacity);

    return 0;
}