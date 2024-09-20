#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define NUM_FRAMES 3

void lfu(int* pages, int n) {
    int frames[NUM_FRAMES] = {-1, -1, -1};
    int frequency[NUM_FRAMES] = {0};
    int insertTime[NUM_FRAMES] = {-1, -1, -1};
    int pageFaultCount = 0;
    bool pageFault = false;

    for(int i = 0; i < n; i++) {
        int j, k;
        for(j = 0; j < NUM_FRAMES; j++) {
            if(frames[j] == pages[i]) {
                pageFault = false;
                frequency[j]++;
                break;
            }
        }
        if( j == NUM_FRAMES) {
            pageFault = true;
            pageFaultCount++;
            int leastFrequent = 0;
            for(k = 1; k < NUM_FRAMES; k++) {
                if(frequency[k] < frequency[leastFrequent])
                    leastFrequent = k;
                else if(frequency[k] == frequency[leastFrequent]) {
                    if(insertTime[k] < insertTime[leastFrequent])
                        leastFrequent = k;
                }
            }
            frames[leastFrequent] = pages[i];
            frequency[leastFrequent] = 1;
            insertTime[leastFrequent] = i;
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
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2};
    int n = sizeof(pages)/sizeof(int);
    lfu(pages, n);
}