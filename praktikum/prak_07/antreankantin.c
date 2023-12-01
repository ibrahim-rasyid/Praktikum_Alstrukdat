#include <stdio.h>
#include "boolean.h"
#include "queue.h"

int main() {
    Queue q;
    CreateQueue(&q);
    int cmd, sum=0, count=0, val;
    float avg;
    scanf("%d", &cmd);
    
    while (cmd != 0)  {
        if (cmd == 1) {
            scanf("%d", &val);
            if (isFull(q)) {
                printf("Queue penuh\n");
            } else {
                enqueue(&q, val);
            }
        } else if (cmd = 2) {
            if (isEmpty(q)) {
                printf("Queue kosong\n");
            } else {
                dequeue(&q, &val);
                sum += val;
                // printf("%d\n", sum);
                // printf("%d\n", val);
                count++;
            }
        }
        // displayQueue(q);
        scanf("%d", &cmd);
    }

    printf("%d\n", count);
    if (count == 0) {
        printf("Tidak bisa dihitung\n");
    } else {
        avg = (float) sum/count;
        printf("%.2f\n", avg);
    }
}