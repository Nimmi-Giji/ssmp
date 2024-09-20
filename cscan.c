#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MIN_DISK 0
#define MAX_DISK 4999

void sort(int* queue, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1; j++) {
            if(queue[j]>queue[j+1]) {
                int temp = queue[j];
                queue[j] = queue[j+1];
                queue[j+1] = temp;
            }
        }
    }
}

void cscan(int* queue, int n, int head, int dir) {
    int thm = 0, pos = head;
    sort(queue, n);
    printf("Total Head Movement: %d ", pos);
    if(dir) {
        for(int i = 0; i < n; i++) {
            if(queue[i] >= pos) {
                thm += abs(queue[i] - pos);
                pos = queue[i];
                printf("-> %d ", pos);
            }
        }
        thm += abs(MAX_DISK - pos);
        pos = MAX_DISK;
        printf("-> %d ", pos);
        thm += abs(MIN_DISK - pos);
        pos = MIN_DISK;
        printf("-> %d ", pos);
        for(int i = 0; i < n; i++) {
            if(queue[i] < head) {
                thm += abs(queue[i] - pos);
                pos = queue[i];
                printf("-> %d ", pos);
            }
        }
        printf("\n%d\n", thm);
    }
    else {
        for(int i = n - 1; i >= 0; i--) {
            if(queue[i] <= pos) {
                thm += abs(queue[i] - pos);
                pos = queue[i];
                printf("-> %d ", pos);
            }
        }
        thm += abs(MIN_DISK - pos);
        pos = MIN_DISK;
        printf("-> %d ", pos);
        thm += abs(MAX_DISK - pos);
        pos = MAX_DISK;
        printf("-> %d ", pos);
        for(int i = n - 1 ; i >= 0; i--) {
            if(queue[i] > head) {
                thm += abs(queue[i] - pos);
                pos = queue[i];
                printf("-> %d ", pos);
            }
        }
        printf("\n%d\n", thm);
    }
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
    printf("cscan to MAX:\n");
    cscan(queue, n, head, 1);
    printf("cscan to MIN:\n");
    cscan(queue, n, head, 0);
}