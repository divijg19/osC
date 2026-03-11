#include <stdio.h>

int main() {

    int pages[50], frame[10];
    int n, f, i, j, k = 0, fault = 0, flag;

    printf("Enter number of pages: ");
    scanf("%d",&n);

    printf("Enter page reference string:\n");

    for(i=0;i<n;i++)
        scanf("%d",&pages[i]);

    printf("Enter number of frames: ");
    scanf("%d",&f);

    for(i=0;i<f;i++)
        frame[i] = -1;

    for(i=0;i<n;i++){

        flag = 0;

        for(j=0;j<f;j++)
            if(frame[j] == pages[i])
                flag = 1;

        if(flag == 0){
            frame[k] = pages[i];
            k = (k+1)%f;
            fault++;
        }
    }

    printf("Page Faults = %d\n", fault);

    return 0;
}
