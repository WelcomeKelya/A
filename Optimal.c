#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_FRAMES 3

int findPage(int page, int frames[], int numFrames) {
    for (int i = 0; i < numFrames; i++) {
        if (frames[i] == page) {
            return 1;
        }
    }
    return 0;
}

int findOptimalPage(int pages[], int frames[], int numFrames, int numPages, int currentIndex) {
    int farthest = currentIndex, farthestIndex = -1;
    for (int i = 0; i < numFrames; i++) {
        int j;
        for (j = currentIndex; j < numPages; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    farthestIndex = i;
                }
                break;
            }
        }
        if (j == numPages) { // If the page is never used in future
            return i;
        }
    }
    return (farthestIndex == -1) ? 0 : farthestIndex;
}

void displayFrames(int frames[], int numFrames) {
    printf("Frames: ");
    for (int i = 0; i < numFrames; i++) {
        if (frames[i] == -1) {
            printf(" |");
        } else {
            printf(" %d|", frames[i]);
        }
    }
    printf("\n");
}

void optimalPageReplacement(int pages[], int numPages) {
    int frames[MAX_FRAMES] = {-1, -1, -1}; // Initialize frames to -1
    int numFrames = 0;
    int pageFaults = 0;

    for (int i = 0; i < numPages; i++) {
        if (!findPage(pages[i], frames, numFrames)) {
            if (numFrames < MAX_FRAMES) {
                frames[numFrames++] = pages[i];
            } else {
                int index = findOptimalPage(pages, frames, numFrames, numPages, i);
                frames[index] = pages[i];
            }
            pageFaults++;
        }
        displayFrames(frames, numFrames);
    }
    printf("Total page faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {1, 2, 3, 4, 5, 2, 1, 6, 7, 8, 7};
    int numPages = sizeof(pages) / sizeof(pages[0]);
    printf("Optimal Page Replacement Algorithm\n");
    optimalPageReplacement(pages, numPages);
    return 0;
}
