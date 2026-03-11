#include <stdio.h>

int main() {
    int n, tq, i, time = 0, remain;
    int bt[10], rt[10];

    printf("Enter number of processes: ");
    scanf("%d",&n);

    remain = n;

    for(i=0;i<n;i++){
        printf("Burst time P%d: ",i+1);
        scanf("%d",&bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d",&tq);

    while(remain != 0){
        for(i=0;i<n;i++){
            if(rt[i] > 0){
                if(rt[i] <= tq){
                    time += rt[i];
                    rt[i] = 0;
                    remain--;
                    printf("Process P%d finished at %d\n", i+1, time);
                } else {
                    rt[i] -= tq;
                    time += tq;
                }
            }
        }
    }

    return 0;
}
