#include <stdio.h>

void nextFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }
    for (int i = 0; i < n; i++) {
    int j = 0;
        int count = 0;
        while (count < m) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
            j = (j + 1) % m;
            count += 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("\nBlock for Process No %d with Size %d is %d", i + 1, processSize[i], allocation[i] + 1);
        else
            printf("\nBlock for Process No %d with Size %d cannot be allocated", i + 1, processSize[i]);
    }
    printf("\n\nEnd of process\n");
}

int main() {
    int m, n;
    printf("Enter the number of blocks: ");
    scanf("%d", &m);
    int blockSize[m];
    printf("Enter the size of each block:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
    }
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int processSize[n];
    printf("Enter the size of each process:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }
    nextFit(blockSize, m, processSize, n);
    return 0;
}
