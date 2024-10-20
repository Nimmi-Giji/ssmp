#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define NUM_FRAMES 3

void fifo(int* pages, int n) {
    int frames[NUM_FRAMES] = {-1, -1, -1};
    int pageFaultCount = 0;
    bool pageFault = false;
    int nextPageIndex = 0;

    for(int i = 0; i < n; i++) {
        int j, k;
        for(j = 0; j < NUM_FRAMES; j++) {
            if(frames[j] == pages[i]) {
                pageFault = false;
                break;
            }
        }
        if(j == NUM_FRAMES) {
            pageFault = true;
            pageFaultCount++;
            frames[nextPageIndex] = pages[i];
            nextPageIndex = (nextPageIndex +1)%NUM_FRAMES;
        }
        printf("Page %d ->\t", pages[i]);
        for(k = 0; k < NUM_FRAMES ; k++) {
            if(frames[k]!=-1) printf("%d\t", frames[k]);
            else printf(" \t");
        }
        if(pageFault) printf("(Page Fault)\n");
        else printf("(Page Hit)\n");
    }
    printf("Total - %d\n", pageFaultCount);
}

int main() {
    printf("Number of frames: %d\n",NUM_FRAMES);
    printf("Enter number of references: ");
    int n;
    scanf("%d", &n);
    int *pages = (int *)calloc(n, sizeof(int));
    printf("\nEnter references: ");
    for(int i = 0; i < n; i++) 
        scanf("%d", &pages[i]);
    fifo(pages, n);
}