#include <stdio.h>

// Best Fit: Searches all blocks and picks the one with minimum wastage
void bestFit(int blockSize[], int m, int processSize[], int n){
    int allocation[n];

    for(int i = 0; i < n; i++){
        allocation[i] = -1;
    }

    for(int i = 0; i < n; i++){
        int bestIdx = -1;

        for(int j = 0; j < m; j++){
            if(blockSize[j] >= processSize[i]){
                if(bestIdx == -1 || blockSize[j] < blockSize[bestIdx]){
                    bestIdx = j;
                }
            }
        }

        if(bestIdx != -1){
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    printf("Process No.\tProcess Size\tBlock No.\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i+1, processSize[i]);
        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}


int main(){
    int blockSize[] = {100, 500, 200, 300, 600}; // kb
    int processSize[] = {212, 417, 112, 426};

    int m = sizeof(blockSize)/sizeof(int);
    int n = sizeof(processSize)/sizeof(int);

    bestFit(blockSize, m, processSize, n);

    return 0;
}