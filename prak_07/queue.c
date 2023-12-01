#include <stdio.h>
#include <math.h>
#include "queue.h"
#include "boolean.h"

void CreateQueue(Queue *q) {
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q) {
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}

boolean isFull(Queue q) {
    return ((IDX_HEAD(q)-1+CAPACITY)%CAPACITY == IDX_TAIL(q));
}

int length(Queue q) {
    int len = 0;
    if (!isEmpty(q)) {
        if (IDX_HEAD(q) <= IDX_TAIL(q)) {
            len = IDX_TAIL(q) - IDX_HEAD(q) + 1;
        } else {
            len = CAPACITY - (IDX_HEAD(q) - IDX_TAIL(q)) + 1;
        }
    }
    return len;
}

void enqueue(Queue *q, ElType val) {
    if (isEmpty(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        HEAD(*q) = val;
    } else {
        if (IDX_TAIL(*q) == CAPACITY-1) {
            IDX_TAIL(*q) = 0;
        } else {
            IDX_TAIL(*q)++;
        }
    }
    TAIL(*q) = val;
}

void dequeue(Queue *q, ElType *val) {
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q)) {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
        if (IDX_HEAD(*q) == CAPACITY-1) {
            IDX_HEAD(*q) = 0;
        } else {
            IDX_HEAD(*q)++;
        }
    }
}

void displayQueue(Queue q) {
    Queue temp;
    CreateQueue(&temp);
    int i, val, len = length(q);
    if (!isEmpty(q)) {
        for (i=0; i<len; i++) {
            dequeue(&q, &val);
            enqueue(&temp, val);
        }
    }
        
    printf("[");
    for (i=0; i<len; i++) {
        dequeue(&temp, &val);
        if (i==0) {
            printf("%d", val);
        } else {
            printf(",%d", val);
        }
        enqueue(&q, val);
    }
    printf("]\n");
    
}

// int main() {
//     Queue q;
//     CreateQueue(&q);
//     enqueue(&q, 9);
//     enqueue(&q, 2);
//     enqueue(&q, 6);
//     enqueue(&q, 4);
//     enqueue(&q, 3);
//     printf("%d\n", length(q));
//     displayQueue(q);
// }