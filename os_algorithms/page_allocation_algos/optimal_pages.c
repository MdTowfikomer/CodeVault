#include <stdio.h>
#include <stdbool.h>

void Optimal(int pages[], int n, int capacity) {
    int frame[capacity];
    int pageFaults = 0;

    for (int i = 0; i < capacity; i++) {
        frame[i] = -1;
    }

    printf("\n\n--- Optimal Page Replacement ---\n");
    printf("Page\tFrames\tPage Fault\n");

    for (int i = 0; i < n; i++) {
        bool found = false;

        // check if page already exists
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                found = true;
                break;
            }
        }

        if (!found) { // [1, 3, 81]
            // If empty slot exists, use that
            int emptyIndex = -1;
            for (int j = 0; j < capacity; j++) {
                if (frame[j] == -1) {
                    emptyIndex = j; 
                    break;
                }
            }

            if (emptyIndex != -1) {
                frame[emptyIndex] = pages[i];
            } else {
                // Find optimal page to replace
                int farthest = -1, replaceIndex = -1;

                for (int j = 0; j < capacity; j++) {
                    int nextUse = -1;

                    for (int k = i + 1; k < n; k++) {
                        if (frame[j] == pages[k]) {
                            nextUse = k;
                            break;
                        }
                    }

                    if (nextUse == -1) {
                        replaceIndex = j;
                        break;
                    }

                    if (nextUse > farthest) {
                        farthest = nextUse;
                        replaceIndex = j;
                    }
                }

                frame[replaceIndex] = pages[i];
            }

            pageFaults++;
        }

        // printing
        printf("%d\t", pages[i]);
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == -1) printf("- ");
            else printf("%d ", frame[j]);
        }
        printf(found ? "\tNo\n" : "\tYes\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
    printf("Page Fault Rate: %.2f%%\n", (float)pageFaults * 100 / n);
}
