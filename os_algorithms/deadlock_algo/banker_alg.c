#include <stdio.h>

int main() {
    int n, m;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[10][10], max[10][10], need[10][10], avail[10]; // need = max - alloc
    int finish[10] = {0}, safe[10];
    
    printf("Enter Allocation matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]); 

    printf("Enter Max matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available resources:\n");
    for (int j = 0; j < m; j++)
        scanf("%d", &avail[j]);

    // Need = Max - Allocation
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    int count = 0;
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int possible = 1;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        possible = 0;
                        break;
                    }
                }
                if (possible) {
                    for (int j = 0; j < m; j++)
                        avail[j] += alloc[i][j];

                    safe[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("System is NOT in a safe state.\n");
            return 0;
        }
    }

    printf("Safe Sequence: ");
    for (int i = 0; i < n; i++)
        printf("P%d ", safe[i]);
    printf("\n");

    return 0;
}