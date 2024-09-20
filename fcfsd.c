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
    int queue [] = {86, 1470, 913, 1774, 948, 1509, 1022, 1750, 130, 97};
    int head = 143;
    int n = sizeof(queue)/sizeof(queue[0]);
    fcfs(queue, head, n);
}