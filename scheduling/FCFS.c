#include <stdio.h>

int main() {
  int n, bt[20], wt[20], tat[20];
  float avg_wt = 0, avg_tat = 0;

  printf("Enter number of processes: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("Enter burst time for P%d: ", i + 1);
    scanf("%d", &bt[i]);
  }

  wt[0] = 0;
  for (int i = 1; i < n; i++)
    wt[i] = wt[i - 1] + bt[i - 1];

  for (int i = 0; i < n; i++) {
    tat[i] = wt[i] + bt[i];
    avg_wt += wt[i];
    avg_tat += tat[i];
  }

  printf("\nProcess\tBT\tWT\tTAT\n");
  for (int i = 0; i < n; i++)
    printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);

  printf("\nAvg WT = %.2f\n", avg_wt / n);
  printf("Avg TAT = %.2f\n", avg_tat / n);

  return 0;
}
