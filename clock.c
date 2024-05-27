#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int page;
    int useBit;
} Frame;

int findPage(int page, Frame frames[], int numFrames) {
    for (int i = 0; i < numFrames; i++) {
        if (frames[i].page == page) {
            frames[i].useBit = 1; // Set the use bit since it's a hit
            return 1;
        }
    }
    return 0;
}

int findClockPointer(Frame frames[], int numFrames, int *clockPointer) {
    while (frames[*clockPointer].useBit == 1) {
        frames[*clockPointer].useBit = 0;
        *clockPointer = (*clockPointer + 1) % numFrames;
    }
    return *clockPointer;
}

void displayFrames(Frame frames[], int numFrames) {
    printf("Frames: ");
    for (int i = 0; i < numFrames; i++) {
        if (frames[i].page == -1) {
            printf(" |");
        } else {
            printf(" %d|", frames[i].page);
        }
    }
    printf("\n");
}

void clockPageReplacement(int pages[], int numPages, int maxFrames) {
    Frame *frames = (Frame *)malloc(maxFrames * sizeof(Frame));
    int numFrames = 0;
    int pageFaults = 0;
    int clockPointer = 0;

    for (int i = 0; i < maxFrames; i++) {
        frames[i].page = -1;
        frames[i].useBit = 0;
    }

    for (int i = 0; i < numPages; i++) {
        if (!findPage(pages[i], frames, numFrames)) {
            if (numFrames < maxFrames) {
                frames[numFrames].page = pages[i];
                frames[numFrames].useBit = 1;
                numFrames++;
            } else {
                int index = findClockPointer(frames, numFrames, &clockPointer);
                frames[index].page = pages[i];
                frames[index].useBit = 1;
                clockPointer = (index + 1) % maxFrames;
            }
            pageFaults++;
        }
        displayFrames(frames, numFrames);
    }
    printf("Total page faults: %d\n", pageFaults);
    free(frames);
}

int main() {
    int numPages, maxFrames;
    
    printf("Enter the number of pages: ");
    scanf("%d", &numPages);
    
    int *pages = (int *)malloc(numPages * sizeof(int));
    
    printf("Enter the page numbers: ");
    for (int i = 0; i < numPages; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &maxFrames);

    printf("Clock Page Replacement Algorithm\n");
    clockPageReplacement(pages, numPages, maxFrames);

    free(pages);
    return 0;
}
