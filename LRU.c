#include <stdio.h>

int findLRU(int time[], int n) {
    int minTime = time[0];
    int index = 0;
    for (int i = 1; i < n; ++i) {
        if (time[i] < minTime) {
            minTime = time[i];
            index = i;
        }
    }
    return index;
}

int main() {
    int frames[10], pages[30], time[10] = {0};
    int no_of_frames, no_of_pages, faults = 0;

    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);
    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);
    printf("Enter reference string: ");
    for (int i = 0; i < no_of_pages; ++i) {
        scanf("%d", &pages[i]);
    }

    for (int i = 0; i < no_of_frames; ++i) {
        frames[i] = -1;
    }
     printf("\nIncoming\tFrame 1\t\tFrame 2\t\tFrame 3");
    for (int i = 0; i < no_of_pages; ++i) {
        int page = pages[i];
        int found = 0;
        for (int j = 0; j < no_of_frames; ++j) {
            if (frames[j] == page) {
                time[j] = i + 1;
                found = 1;
                break;
            }
        }

        if (!found) {
            int index = findLRU(time, no_of_frames);
            frames[index] = page;
            time[index] = i + 1;
            faults++;
        }

        
        printf("\n%d\t\t", pages[i]);
        for (int n = 0; n < no_of_frames; n++) {
            if (frames[n] != -1)
                printf("%d\t\t\t", frames[n]);
            else
                printf("-\t\t\t");
        }
    }
    printf("\n\nTotal Page Faults = %d", faults);

    return 0;
}
