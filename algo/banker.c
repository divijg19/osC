#include <stdio.h>

int main() {
  int n = 3, m = 3;
  int alloc[3][3] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}};
  int max[3][3] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}};
  int avail[3] = {3, 3, 2};

  int need[3][3], finish[3] = {0}, safe[3], k = 0;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      need[i][j] = max[i][j] - alloc[i][j];

  for (int count = 0; count < n; count++) {
    for (int i = 0; i < n; i++) {
      if (!finish[i]) {
        int flag = 1;
        for (int j = 0; j < m; j++)
          if (need[i][j] > avail[j])
            flag = 0;

        if (flag) {
          safe[k++] = i;
          for (int j = 0; j < m; j++)
            avail[j] += alloc[i][j];
          finish[i] = 1;
        }
      }
    }
  }

  printf("Safe Sequence: ");
  for (int i = 0; i < n; i++)
    printf("P%d ", safe[i]);

  return 0;
}
