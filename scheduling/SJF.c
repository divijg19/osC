#include <stdio.h>

int main() {
  int n, bt[20], wt[20], tat[20], temp;

  printf("Enter number of processes: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("Enter BT for P%d: ", i + 1);
    scanf("%d", &bt[i]);
  }

  // Sorting
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (bt[i] > bt[j]) {
        temp = bt[i];
        bt[i] = bt[j];
        bt[j] = temp;
      }

  wt[0] = 0;
  for (int i = 1; i < n; i++)
    wt[i] = wt[i - 1] + bt[i - 1];

  for (int i = 0; i < n; i++)
    tat[i] = wt[i] + bt[i];

  printf("\nProcess\tBT\tWT\tTAT\n");
  for (int i = 0; i < n; i++)
    printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);

  return 0;
}
