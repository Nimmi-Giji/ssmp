#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define MIN_DISK 0
#define MAX_DISK 4999

void fcfs(int* queue,int head, int n) {
    int pos = head;
    int thm = 0;
    printf("Head movement fcfs:\n%d", pos);
    for(int i = 0 ;  i < n ; i++) {
        thm += abs(pos - queue[i]);
        pos = queue[i];
        printf("->%d", pos);
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
    fcfs(queue, head, n);
}