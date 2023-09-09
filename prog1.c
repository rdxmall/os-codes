#include <stdio.h>
#include <stdlib.h> // Add this line for scanf and printf

int main() {
    int n, bt[30], wait_t[30], turn_ar_t[30], av_wt_t = 0, avturn_ar_t = 0, i, j;

    printf("Enter the total number of processes:");
    scanf("%d", &n);

    printf("\nEnter The Process Burst Time\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]:", i + 1);
        scanf("%d", &bt[i]);
    }

    wait_t[0] = 0;
    for (i = 1; i < n; i++) {
        wait_t[i] = 0;
        for (j = 0; j < i; j++)
            wait_t[i] += bt[j];
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        turn_ar_t[i] = bt[i] + wait_t[i];
        av_wt_t += wait_t[i];
        avturn_ar_t += turn_ar_t[i];

        printf("P[%d]\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wait_t[i], turn_ar_t[i]);
    }

    float av_wt_float = (float)av_wt_t / n; // Use float for average calculation
    float avturn_ar_float = (float)avturn_ar_t / n;

    printf("\nAverage Waiting Time: %.2f\n", av_wt_float);
    printf("Average Turnaround Time: %.2f\n", avturn_ar_float);

    return 0;
}

