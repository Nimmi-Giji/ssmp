#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define MIN_DISK 0
#define MAX_DISK 4999

void sort(int* arr, int n) {
    for(int i = 0 ; i < n - 1 ; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if( arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void scan(int* queue, int head, int n, int dir) {
    int pos = head;
    int thm = 0;
    sort(queue, n);
    printf("Head movement scan:\n%d", pos);
    if(dir) {
        for(int i = 0 ; i < n ; i++) {
            if(queue[i] >= pos) {
                thm += abs(pos - queue[i]);
                pos = queue[i];
                printf("->%d", pos);
            }
        }
        thm += abs(pos - MAX_DISK);
        pos = MAX_DISK;
        printf("->%d", pos);
        for(int i = n - 1 ; i >=0 ; i--) {
            if(queue[i] <= head) {
                thm += abs(pos - queue[i]);
                pos = queue[i];
                printf("->%d", pos);
            }
        }
    }
    else {
        for(int i = n - 1; i >= 0 ; i--) {
            if(queue[i] <= pos) {
                thm += abs(pos - queue[i]);
                pos = queue[i];
                printf("->%d", pos);
            }
        }
        thm += abs(pos - MIN_DISK);
        pos = MIN_DISK;
        printf("->%d", pos);
        for(int i = 0 ; i < n ; i++) {
            if(queue[i] >= head) {
                thm += abs(pos - queue[i]);
                pos = queue[i];
                printf("->%d", pos);
            }
        }   
    }
    printf("\nTotal head movement: %d\n", thm);
}
int main() {
    printf("MIN %d MAX %d\n",MIN_DISK,MAX_DISK);
    int n;
    printf("Enter number of disk acesses: ");
    scanf("%d",&n);
    int *queue = (int *)malloc(sizeof(int));
    int head = 143;
    printf("\ncurrent head at %d\n",head);
    printf("Enter access requests:\n");
    for(int i = 0; i < n; i++)
        scanf("%d",&queue[i]);
    printf("Scan to MAX:\n");
    scan(queue, head, n, 1);
    printf("Scan to MIN:\n");
    scan(queue, head, n, 0);
}