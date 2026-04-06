#include <stdio.h>

void firstFit(int blockSize[], int m, int processSize[], int n) {
  int allocation[n];

  for (int i = 0; i < n; i++) {
    allocation[i] = -1;
    for (int j = 0; j < m; j++) {
      if (blockSize[j] >= processSize[i]) {
        allocation[i] = j;
        blockSize[j] -= processSize[i];
        break;
      }
    }
  }

  printf("\nFirst Fit Allocation:\n");
  for (int i = 0; i < n; i++)
    printf("Process %d -> Block %d\n", i + 1, allocation[i] + 1);
}
