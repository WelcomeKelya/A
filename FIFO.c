#include <stdio.h>

int main() {
    int pageFaults = 0;
    int frames;

    printf("Enter the number of Frames:");
    scanf("%d", &frames);

    int pages;
    printf("Enter the number of pages:");
    scanf("%d", &pages);

    int incomingStream[pages];
    printf("Enter the Reference String:");
    for (int i = 0; i < pages; i++) {
        scanf("%d", &incomingStream[i]);
    }

    printf("Incoming\tFrame 1\t\t Frame 2\t\tFrame 3");
    int temp[frames];
    for (int m = 0; m < frames; m++) {
        temp[m] = -1;
    }

    for (int m = 0; m < pages; m++) {
        int found = 0;
        for (int n = 0; n < frames; n++) {
            if (incomingStream[m] == temp[n]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            pageFaults++;
            if (pageFaults <= frames) {
                temp[m] = incomingStream[m];
            } else {
                temp[(pageFaults - 1) % frames] = incomingStream[m];
            }
        }

        printf("\n%d\t\t", incomingStream[m]);
        for (int n = 0; n < frames; n++) {
            if (temp[n] != -1)
                printf("%d\t\t\t", temp[n]);
            else
                printf("-\t\t\t");
        }
    }

    printf("\nTotal Page Faults:\t%d\n", pageFaults);
    return 0;
}
