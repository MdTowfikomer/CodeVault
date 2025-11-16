#include <stdio.h>


// First Fit takes the first available block that's big enough. It doesn't look for the best fit. So even though we have blocks available, Process 4 (426 KB) can't fit anywhere because

void firstFit(int blockSize[], int m, int processSize[], int n){
    // stores the block number allocated to process i
    int allocation[n]; 

    for(int i = 0; i < n; i++){
        allocation[i] = -1;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(blockSize[j] >= processSize[i]){
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("FIRST FIT ALLOCATION\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for(int i = 0; i < n; i++){
        printf("%d\t\t%d\t\t", i+1, processSize[i]);
        if(allocation[i] != -1){
            printf("%d\n", allocation[i]+1);
        } else{
            printf("Not Allocated\n");
        }
    }
}

int main(){
    int blockSize[] = {100, 500, 200, 300, 600}; // kb
    int processSize[] = {212, 417, 112, 426};

    int m = sizeof(blockSize)/sizeof(int);
    int n = sizeof(processSize)/sizeof(int);

    firstFit(blockSize, m, processSize, n);

    return 0;
}