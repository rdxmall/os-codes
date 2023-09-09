#include<stdio.h>

int main() {
    int incomingStream[] = {4, 1, 2, 4, 5};
    int pageFaults = 0;
    int frames = 3;
    int m, n, s, pages;
    pages = sizeof(incomingStream) / sizeof(incomingStream[0]);
    printf(" Incoming\t Frame1\t\t Frame2\t\t Frame3 ");
    int temp[frames];

    for (m = 0; m < frames; m++) {
        temp[m] = -1;
    }

    for (m = 0; m < pages; m++) {
        s = 0;
        for (n = 0; n < frames; n++) {
            if (incomingStream[m] == temp[n]) {
                s++;
                break; // No need to continue searching
            }
        }

        if (s == 0) {
            pageFaults++;
            if (pageFaults <= frames) {
                temp[m] = incomingStream[m];
            } else {
                temp[(pageFaults - 1) % frames] = incomingStream[m];
            }
        }

        printf("\n");
        printf("%d\t\t", incomingStream[m]);
        for (n = 0; n < frames; n++) {
            if (temp[n] != -1) {
                printf(" %d\t\t", temp[n]);
            } else {
                printf(" - \t\t");
            }
        }
    }

    printf("\n \n Total Page Faults:\t%d\n", pageFaults);

    return 0;
}
